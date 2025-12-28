use chrono::{Datelike, NaiveDate};
use clap::Parser;
use html_escape::decode_html_entities;
use ical::parser::ical::component::IcalEvent;
use ical::IcalParser;
use std::fs;
use std::io::BufReader;
use textwrap::wrap;

#[derive(Parser, Debug)]
#[command(name = "generate-events")]
#[command(about = "Generate C header for astronomical events from iCal files")]
struct Args {
    /// Input iCal files (comma-separated)
    #[arg(short, long, value_delimiter = ',')]
    input: Vec<String>,

    /// Output directory for generated header
    #[arg(short, long, default_value = "..")]
    output_dir: String,

    /// Keywords to filter events (comma-separated)
    #[arg(short, long, value_delimiter = ',')]
    keywords: Option<Vec<String>>,
}

#[derive(Debug, Clone)]
struct AstroEvent {
    year: u32,
    month: u8,
    day: u8,
    name: String,
    description: String,
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = Args::parse();

    println!("Astronomical Event Generator");
    println!("=============================");

    let keywords = args.keywords.unwrap_or_else(Vec::new);

    if keywords.is_empty() {
        println!("Including all events (no filtering)");
    } else {
        println!("Filtering for keywords: {:?}", keywords);
    }

    let mut all_events = Vec::new();

    // Parse each iCal file
    for input_file in &args.input {
        println!("\nParsing {}...", input_file);

        let file = fs::File::open(input_file)?;
        let reader = BufReader::new(file);
        let parser = IcalParser::new(reader);

        for calendar in parser {
            let calendar = calendar?;

            for event in calendar.events {
                if let Some(astro_event) = parse_event(&event, &keywords) {
                    all_events.push(astro_event);
                }
            }
        }

        println!("  Found {} events", all_events.len());
    }

    // Sort by date (chronologically across years)
    all_events.sort_by_key(|e| (e.year, e.month, e.day));

    // Remove duplicates (same year/month/day + name)
    all_events.dedup_by(|a, b| {
        a.year == b.year && a.month == b.month && a.day == b.day && a.name == b.name
    });

    println!("\nTotal unique events: {}", all_events.len());

    // Generate header
    let output_path = format!("{}/events_data.h", args.output_dir);
    generate_header(&all_events, &output_path)?;

    println!("Generated: {}", output_path);
    println!("Done!");

    Ok(())
}

fn parse_event(event: &IcalEvent, keywords: &[String]) -> Option<AstroEvent> {
    // Extract SUMMARY
    let summary = event
        .properties
        .iter()
        .find(|p| p.name == "SUMMARY")
        .and_then(|p| p.value.as_ref())?;

    // Extract DESCRIPTION
    let description = event
        .properties
        .iter()
        .find(|p| p.name == "DESCRIPTION")
        .and_then(|p| p.value.as_ref())
        .map(|s| s.as_str())
        .unwrap_or("");

    // Extract DTSTART
    let dtstart = event
        .properties
        .iter()
        .find(|p| p.name == "DTSTART")
        .and_then(|p| p.value.as_ref())?;

    // Parse date (format: YYYYMMDD)
    let date = parse_ical_date(dtstart)?;

    // Filter by keywords (if any provided)
    if !keywords.is_empty() {
        let summary_lower = summary.to_lowercase();
        let desc_lower = description.to_lowercase();

        let matches_keyword = keywords.iter().any(|kw| {
            summary_lower.contains(&kw.to_lowercase()) || desc_lower.contains(&kw.to_lowercase())
        });

        if !matches_keyword {
            return None;
        }
    }

    // Decode HTML entities
    let name = decode_html_entities(summary).to_string();
    let description = decode_html_entities(description).to_string();

    // Remove link from description (if present)
    let description = description
        .rsplit_once("https")
        .map(|(before, _)| before.trim())
        .unwrap_or(description.trim())
        .to_string();

    // Format description for display with line wrapping
    // Event descriptions use text size 2 (same as poems), which is ~12px/char
    // With POETRY_WIDTH = 520px (SCREEN_WIDTH - 80px margins), that's ~43 chars
    let wrapped_lines: Vec<_> = wrap(&description, 40)
        .into_iter()
        .take(4) // Limit to 4 lines to fit on screen with size 2
        .collect();

    let description = wrapped_lines.join("\n");

    Some(AstroEvent {
        year: date.year() as u32,
        month: date.month() as u8,
        day: date.day() as u8,
        name,
        description,
    })
}

fn parse_ical_date(date_str: &str) -> Option<NaiveDate> {
    // iCal format: YYYYMMDD or YYYYMMDDTHHMMSS
    let date_part = date_str.split('T').next()?;

    if date_part.len() < 8 {
        return None;
    }

    let year: i32 = date_part[0..4].parse().ok()?;
    let month: u32 = date_part[4..6].parse().ok()?;
    let day: u32 = date_part[6..8].parse().ok()?;

    NaiveDate::from_ymd_opt(year, month, day)
}

fn escape_c_string(s: &str) -> String {
    s.replace('\\', "\\\\")
        .replace('"', "\\\"")
        .replace('\n', "\\n")
        .replace('\r', "")
}

fn generate_header(
    events: &[AstroEvent],
    output_path: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    let mut header = String::new();

    // Header guard
    header.push_str("#ifndef EVENTS_DATA_H\n");
    header.push_str("#define EVENTS_DATA_H\n\n");
    header.push_str("#include <Arduino.h>\n\n");

    // Event count
    header.push_str("// Number of astronomical events\n");
    header.push_str(&format!(
        "const uint16_t ASTRO_EVENT_COUNT = {};\n\n",
        events.len()
    ));

    // Event dates array
    header.push_str("// Event dates (month, day)\n");
    header.push_str("struct AstroEventDate {\n");
    header.push_str("    uint32_t year;\n");
    header.push_str("    uint8_t month;\n");
    header.push_str("    uint8_t day;\n");
    header.push_str("};\n\n");

    header.push_str("const AstroEventDate ASTRO_EVENTS[] PROGMEM = {\n");
    for event in events {
        header.push_str(&format!(
            "    {{{}, {}, {}}},  // {}/{}/{}: {}\n",
            event.year, event.month, event.day, event.year, event.month, event.day, event.name
        ));
    }
    header.push_str("};\n\n");

    // Event names
    header.push_str("// Event names (stored in PROGMEM)\n");
    for (i, event) in events.iter().enumerate() {
        header.push_str(&format!(
            "const char ASTRO_NAME_{}[] PROGMEM = \"{}\";\n",
            i,
            escape_c_string(&event.name)
        ));
    }

    header.push_str("\nconst char* const ASTRO_NAMES[] PROGMEM = {\n");
    for i in 0..events.len() {
        header.push_str(&format!("    ASTRO_NAME_{}", i));
        if i < events.len() - 1 {
            header.push_str(",\n");
        } else {
            header.push('\n');
        }
    }
    header.push_str("};\n\n");

    // Event descriptions
    header.push_str("// Event descriptions (stored in PROGMEM)\n");
    for (i, event) in events.iter().enumerate() {
        header.push_str(&format!(
            "const char ASTRO_DESC_{}[] PROGMEM = \"{}\";\n",
            i,
            escape_c_string(&event.description)
        ));
    }

    header.push_str("\nconst char* const ASTRO_DESCS[] PROGMEM = {\n");
    for i in 0..events.len() {
        header.push_str(&format!("    ASTRO_DESC_{}", i));
        if i < events.len() - 1 {
            header.push_str(",\n");
        } else {
            header.push('\n');
        }
    }
    header.push_str("};\n\n");

    header.push_str("#endif\n");

    fs::write(output_path, header)?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_parse_ical_date() {
        assert_eq!(
            parse_ical_date("20251214"),
            Some(NaiveDate::from_ymd_opt(2025, 12, 14).unwrap())
        );
        assert_eq!(
            parse_ical_date("20251214T120000"),
            Some(NaiveDate::from_ymd_opt(2025, 12, 14).unwrap())
        );
    }

    #[test]
    fn test_escape_c_string() {
        assert_eq!(escape_c_string("hello"), "hello");
        assert_eq!(escape_c_string("say \"hi\""), "say \\\"hi\\\"");
        assert_eq!(escape_c_string("line1\nline2"), "line1\\nline2");
    }
}
