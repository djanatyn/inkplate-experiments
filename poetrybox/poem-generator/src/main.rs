use clap::Parser;
use epub::doc::EpubDoc;
use serde::{Deserialize, Serialize};
use std::error::Error;
use std::fs;
use std::path::Path;
use textwrap::wrap;

#[derive(Parser, Debug)]
#[command(name = "poem-generator")]
#[command(about = "Generate C header files for poems stored in flash memory")]
struct Args {
    /// Output directory for generated header
    #[arg(short, long, default_value = ".")]
    output_dir: String,
}

#[derive(Debug, Serialize, Deserialize)]
struct Poem {
    title: String,
    author: String,
    text: String,
}

#[derive(Debug, Clone)]
struct ResourceLookup {
    path: String,
    title: String,
}

fn main() -> Result<(), Box<dyn Error>> {
    let poems = extract_all_poems()?;
    let args = Args::parse();

    println!("Loaded {} poems", poems.len());

    // Generate header file
    let output_path = Path::new(&args.output_dir).join("poems_data.h");
    generate_header(&poems, output_path.to_str().unwrap())?;

    println!("Generated: {}", output_path.display());
    println!("Done!");

    Ok(())
}

fn extract_all_poems() -> Result<Vec<Poem>, Box<dyn Error>> {
    let mut poems = vec![];

    // On Earth We're Briefly Gorgeous
    poems.append(&mut extract_poems_from_epub(
        "../poems/ocean-vuong/on-earth-we're-briefly-gorgeous.epub",
        &[
            // part 1
            ResourceLookup {
                path: "OEBPS/xhtml/11_Chapter.xhtml".to_string(),
                title: "Part 1 - Chapter 1".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/12_Chapter.xhtml".to_string(),
                title: "Part 1 - Chapter 2".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/13_Chapter.xhtml".to_string(),
                title: "Part 1 - Chapter 3".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/14_Chapter.xhtml".to_string(),
                title: "Part 1 - Chapter 4".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/15_Chapter.xhtml".to_string(),
                title: "Part 1 - Chapter 5".to_string(),
            },
            // part 2
            ResourceLookup {
                path: "OEBPS/xhtml/18_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 1".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/19_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 2".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/20_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 3".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/21_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 4".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/22_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 5".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/23_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 6".to_string(),
            },
            // part 3
            ResourceLookup {
                path: "OEBPS/xhtml/26_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 1".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/27_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 2".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/28_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 3".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/29_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 4".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/30_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 5".to_string(),
            },
            ResourceLookup {
                path: "OEBPS/xhtml/32_Chapter.xhtml".to_string(),
                title: "Part 3 - Chapter 6".to_string(),
            },
        ],
    )?);

    Ok(poems)
}

fn escape_c_string(s: &str) -> String {
    s.replace('\\', "\\\\")
        .replace('"', "\\\"")
        .replace('\n', "\\n")
        .replace('\r', "\\r")
}

// Display constants
const LINES_PER_PAGE: usize = 22; // Conservative for 600px height, 20px line height, margins
const TEXT_SIZE: u8 = 2;
const CHAR_WIDTH_PX: u8 = 12;
const LINE_HEIGHT_PX: u8 = 20;

fn paginate_poem(text: &str) -> Vec<String> {
    let lines: Vec<&str> = text.lines().collect();

    lines
        .chunks(LINES_PER_PAGE)
        .map(|chunk| chunk.join("\n"))
        .collect()
}

fn generate_header(poems: &[Poem], output_path: &str) -> Result<(), Box<dyn std::error::Error>> {
    let mut header = String::new();

    // Header guard
    header.push_str("#ifndef POEMS_DATA_H\n");
    header.push_str("#define POEMS_DATA_H\n\n");
    header.push_str("#include <Arduino.h>\n\n");

    // Display constants
    header.push_str("// Display constants (must match actual rendering)\n");
    header.push_str(&format!(
        "const uint8_t LINES_PER_PAGE = {};\n",
        LINES_PER_PAGE
    ));
    header.push_str(&format!("const uint8_t TEXT_SIZE = {};\n", TEXT_SIZE));
    header.push_str(&format!(
        "const uint8_t CHAR_WIDTH_PX = {};\n",
        CHAR_WIDTH_PX
    ));
    header.push_str(&format!(
        "const uint8_t LINE_HEIGHT_PX = {};\n\n",
        LINE_HEIGHT_PX
    ));

    // Poem count
    header.push_str("// Number of poems\n");
    header.push_str(&format!("const uint16_t POEM_COUNT = {};\n\n", poems.len()));

    // Generate title strings
    header.push_str("// Poem titles (stored in PROGMEM)\n");
    for (i, poem) in poems.iter().enumerate() {
        header.push_str(&format!(
            "const char POEM_{}_TITLE[] PROGMEM = \"{}\";\n",
            i,
            escape_c_string(&poem.title)
        ));
    }

    // Title pointers array
    header.push_str("\n// Title pointers array\n");
    header.push_str("const char* const POEM_TITLES[] PROGMEM = {\n");
    for i in 0..poems.len() {
        header.push_str(&format!("    POEM_{}_TITLE", i));
        if i < poems.len() - 1 {
            header.push_str(",\n");
        } else {
            header.push('\n');
        }
    }
    header.push_str("};\n\n");

    // Paginate all poems and track first page indices
    let mut all_pages: Vec<String> = Vec::new();
    let mut poem_first_pages: Vec<usize> = Vec::new();

    for poem in poems {
        poem_first_pages.push(all_pages.len()); // Record first page of this poem
        let pages = paginate_poem(&poem.text);
        all_pages.extend(pages);
    }

    header.push_str(&format!(
        "const uint16_t TOTAL_PAGES = {};\n\n",
        all_pages.len()
    ));

    // Generate POEM_FIRST_PAGE array
    header.push_str("// First page index for each poem\n");
    header.push_str("const uint16_t POEM_FIRST_PAGE[] PROGMEM = {\n");
    for (i, &first_page) in poem_first_pages.iter().enumerate() {
        let page_count = if i < poem_first_pages.len() - 1 {
            poem_first_pages[i + 1] - first_page
        } else {
            all_pages.len() - first_page
        };
        header.push_str(&format!(
            "    {},  // Poem {}: {} page{}\n",
            first_page,
            i,
            page_count,
            if page_count == 1 { "" } else { "s" }
        ));
    }
    header.push_str("};\n\n");

    // Generate individual page arrays (same pattern as events.rs for ASTRO_NAMES)
    header.push_str("// Individual page text arrays (stored in PROGMEM)\n");
    for (i, page_text) in all_pages.iter().enumerate() {
        header.push_str(&format!(
            "const char PAGE_{}[] PROGMEM = \"{}\";\n",
            i,
            escape_c_string(page_text)
        ));
    }

    // Generate pointer array to pages
    header.push_str("\n// Pointer array to all pages (stored in PROGMEM)\n");
    header.push_str("const char* const PAGES[] PROGMEM = {\n");
    for i in 0..all_pages.len() {
        header.push_str(&format!("    PAGE_{}", i));
        if i < all_pages.len() - 1 {
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

/// Extract plain text from HTML content, preserving paragraph breaks
fn extract_text_from_html(html_content: &str) -> String {
    duct::cmd!("pandoc", "-f", "html", "-t", "plain")
        .stdin_bytes(html_content)
        .read()
        .unwrap()
}

/// Format poem text to fit the Inkplate display width
/// Display is 600px wide, with POETRY_X=40 margin, so usable width is ~520px
/// At text size 2, each char is ~12px, so we can fit ~43 chars per line
fn format_for_display(text: &str, max_width: usize) -> String {
    // Count initial non-ASCII characters
    let initial_non_ascii = text.chars().filter(|c| *c as u32 > 0x7F).count();

    // Normalize characters for display
    let mut text = text.to_string();
    let mut total_replacements = 0;

    // Track each replacement (char literals only for non-quote characters)
    let replacements = [
        ('—', "--", "Em dash U+2014"),
        ('–', "--", "En dash U+2013"),
        ('ạ', "a", "a with dot below"),
        ('ẹ', "e", "e with dot below"),
        ('ệ', "e", "e with circumflex and dot below"),
        ('ớ', "o", "o with horn and acute"),
        ('ở', "o", "o with horn and hook above"),
        ('ế', "e", "e with circumflex and acute"),
        ('Đ', "D", "D with stroke (capital)"),
        ('đ', "d", "d with stroke (lowercase)"),
    ];

    for (from, to, desc) in replacements {
        let count = text.matches(from).count();
        if count > 0 {
            eprintln!("  Replacing {} ({}) {} times", desc, from, count);
            text = text.replace(from, to);
            total_replacements += count;
        }
    }

    // Handle string-based replacements for all quotes (must use Unicode escapes)
    let string_replacements = [
        ("\u{201C}", "\"", "Left double quote U+201C"),
        ("\u{201D}", "\"", "Right double quote U+201D"),
        ("\u{201E}", "\"", "Double low-9 quote U+201E"),
        ("\u{2018}", "'", "Left single quote U+2018"),
        ("\u{2019}", "'", "Right single quote U+2019"),
        ("\u{201A}", "'", "Single low-9 quote U+201A"),
    ];

    for (from, to, desc) in string_replacements {
        let count = text.matches(from).count();
        if count > 0 {
            eprintln!("  Replacing {} ({}) {} times", desc, from, count);
            text = text.replace(from, to);
            total_replacements += count;
        }
    }

    let final_non_ascii = text.chars().filter(|c| *c as u32 > 0x7F).count();

    if initial_non_ascii > 0 || final_non_ascii > 0 || total_replacements > 0 {
        eprintln!(
            "Normalization: {} non-ASCII chars -> {} replacements -> {} remaining non-ASCII",
            initial_non_ascii, total_replacements, final_non_ascii
        );
    }

    let lines: Vec<&str> = text.lines().collect();
    let mut formatted = String::new();

    for line in lines {
        if line.trim().is_empty() {
            // Preserve empty lines (stanza breaks)
            formatted.push('\n');
        } else {
            // Wrap long lines to fit display width
            let wrapped = wrap(line, max_width);
            for wrapped_line in wrapped {
                formatted.push_str(&wrapped_line);
                formatted.push('\n');
            }
        }
    }

    formatted
}

/// Extract poems from an EPUB file
fn extract_poems_from_epub(
    epub_path: &str,
    resource_paths: &[ResourceLookup],
) -> Result<Vec<Poem>, Box<dyn std::error::Error>> {
    let mut doc = EpubDoc::new(epub_path)?;
    let mut poems = Vec::new();

    // Find chapters matching the provided labels
    let resources: Vec<(ResourceLookup, String)> = doc
        .resources
        .iter()
        .filter_map(|(_, r)| {
            if let Some(lookup) = resource_paths
                .into_iter()
                .find(|rl| *rl.path == *r.path.as_os_str())
            {
                Some((lookup.clone(), r.path.display().to_string()))
            } else {
                None
            }
        })
        .collect();

    for (lookup, path) in resources {
        println!("processing chapter: {:?}", path);

        // Get HTML content for this chapter
        if let Some(content) = doc.get_resource_str_by_path(&path) {
            // Extract and format text
            let raw_text = extract_text_from_html(&content);
            let formatted_text = format_for_display(&raw_text, 40);

            poems.push(Poem {
                title: lookup.title,
                author: "Ocean Vuong".to_string(),
                text: formatted_text,
            });
        }
    }

    Ok(poems)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_escape_c_string() {
        assert_eq!(escape_c_string("hello"), "hello");
        assert_eq!(escape_c_string("hello\nworld"), "hello\\nworld");
        assert_eq!(escape_c_string("say \"hi\""), "say \\\"hi\\\"");
        assert_eq!(escape_c_string("path\\to\\file"), "path\\\\to\\\\file");
    }

    #[test]
    fn test_generate_header_with_placeholder() {
        let poems = vec![Poem {
            title: "Test Poem".to_string(),
            author: "Test Author".to_string(),
            text: "Line 1\nLine 2\nLine 3".to_string(),
        }];

        let output = "/tmp/test_poems.h";
        generate_header(&poems, output).expect("Failed to generate header");

        let content = fs::read_to_string(output).expect("Failed to read output");

        assert!(content.contains("POEM_COUNT = 1"));
        assert!(content.contains("Test Poem"));
        assert!(content.contains("TOTAL_PAGES"));
    }

    #[test]
    fn test_pagination() {
        // Create a poem with exactly 44 lines (should be 2 pages at 22 lines/page)
        let lines: Vec<String> = (1..=44).map(|i| format!("Line {}", i)).collect();
        let text = lines.join("\n");

        let pages = paginate_poem(&text);

        assert_eq!(pages.len(), 2, "44 lines should create 2 pages");
        assert_eq!(
            pages[0].lines().count(),
            22,
            "First page should have 22 lines"
        );
        assert_eq!(
            pages[1].lines().count(),
            22,
            "Second page should have 22 lines"
        );

        // Verify content
        assert!(pages[0].starts_with("Line 1"));
        assert!(pages[0].contains("Line 22"));
        assert!(pages[1].starts_with("Line 23"));
        assert!(pages[1].contains("Line 44"));
    }

    #[test]
    fn test_pagination_with_multiple_poems() {
        let poems = vec![
            Poem {
                title: "Short Poem".to_string(),
                author: "Test".to_string(),
                text: (1..=10)
                    .map(|i| format!("Line {}", i))
                    .collect::<Vec<_>>()
                    .join("\n"),
            },
            Poem {
                title: "Long Poem".to_string(),
                author: "Test".to_string(),
                text: (1..=50)
                    .map(|i| format!("Line {}", i))
                    .collect::<Vec<_>>()
                    .join("\n"),
            },
        ];

        let output = "/tmp/test_poems_multi.h";
        generate_header(&poems, output).expect("Failed to generate header");
        let content = fs::read_to_string(output).expect("Failed to read output");

        // Check constants
        assert!(content.contains("POEM_COUNT = 2"));
        assert!(content.contains("TOTAL_PAGES = 4")); // 1 page + 3 pages

        // Check POEM_FIRST_PAGE array
        assert!(content.contains("0,  // Poem 0: 1 page"));
        assert!(content.contains("1,  // Poem 1: 3 pages")); // 50 lines = ceil(50/22) = 3 pages
    }

    #[test]
    fn test_quote_normalization_pipeline() {
        // Extract Part 2 - Chapter 2 which contains fancy quotes
        let poems = extract_poems_from_epub(
            "../poems/ocean-vuong/on-earth-we're-briefly-gorgeous.epub",
            &[ResourceLookup {
                path: "OEBPS/xhtml/19_Chapter.xhtml".to_string(),
                title: "Part 2 - Chapter 2".to_string(),
            }],
        )
        .expect("Failed to extract poem");

        assert_eq!(poems.len(), 1, "Should extract exactly one chapter");

        let poem = &poems[0];
        let text = &poem.text;

        println!("Chapter title: {}", poem.title);
        println!("Text length: {}", text.len());

        // Check for fancy quotes and other problematic Unicode (not Latin-1 Supplement)
        // Allow: Basic Latin (0x00-0x7F) and Latin-1 Supplement (0x80-0xFF)
        // Reject: Fancy quotes and other characters above 0xFF
        let bad_chars: Vec<(usize, char, String)> = text
            .char_indices()
            .filter(|(_, c)| *c as u32 > 0xFF)
            .map(|(idx, c)| {
                let bytes: Vec<u8> = c.to_string().bytes().collect();
                let hex_str = bytes
                    .iter()
                    .map(|b| format!("{:02x}", b))
                    .collect::<Vec<_>>()
                    .join(" ");
                (idx, c, hex_str)
            })
            .collect();

        // Also report Latin-1 Supplement for visibility (but don't fail on them)
        let latin1_chars: Vec<char> = text
            .chars()
            .filter(|c| {
                let code = *c as u32;
                code >= 0x80 && code <= 0xFF
            })
            .collect();

        if !latin1_chars.is_empty() {
            println!(
                "Found {} Latin-1 Supplement characters (OK): {:?}",
                latin1_chars.len(),
                latin1_chars.iter().take(10).collect::<Vec<_>>()
            );
        }

        if !bad_chars.is_empty() {
            println!(
                "Found {} problematic characters above Latin-1:",
                bad_chars.len()
            );
            for (idx, ch, hex) in bad_chars.iter().take(20) {
                let context_start = idx.saturating_sub(20);
                let context_end = std::cmp::min(idx + 20, text.len());
                println!(
                    "  At position {}: '{}' (U+{:04X}, bytes: {}) in context: {:?}",
                    idx,
                    ch,
                    *ch as u32,
                    hex,
                    &text[context_start..context_end]
                );
            }
        }

        assert_eq!(
            bad_chars.len(),
            0,
            "Found {} characters above Latin-1 Supplement (should only have 0x00-0xFF)",
            bad_chars.len()
        );
    }
}
