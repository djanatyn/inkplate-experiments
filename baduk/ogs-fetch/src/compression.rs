use std::fs;
use sgf_parse::{parse, go::Prop};

/// Parse SGF moves from a game file
/// Extracts moves in the format ;B[pd] or ;W[cd]
/// Only parses the main line, stops at variation branches
pub fn parse_sgf_moves(content: &str) -> Vec<u16> {
    let mut moves = Vec::new();

    // Parse SGF with sgf-parse library
    // parse() returns Vec<GameTree>
    let Ok(game_trees) = parse(content) else {
        return moves;
    };

    // Get the first game tree
    let Some(game_tree) = game_trees.first() else {
        return moves;
    };

    // Convert GameTree to SgfNode and get the root node
    let Ok(root_node) = game_tree.as_go_node() else {
        return moves;
    };

    // Iterate through the main variation
    for node in root_node.main_variation() {
        // Check for move properties (B for black, W for white)
        for prop in node.properties() {
            match prop {
                Prop::B(mv) | Prop::W(mv) => {
                    // Convert move to our coordinate format and encode
                    if let Some(encoded) = encode_move_from_lib(&mv) {
                        moves.push(encoded);
                    }
                }
                _ => {}
            }
        }
    }

    moves
}

/// Helper to convert sgf-parse Move to our u16 encoding
fn encode_move_from_lib(mv: &sgf_parse::go::Move) -> Option<u16> {
    match mv {
        sgf_parse::go::Move::Pass => {
            // Passes are not stored in our compressed format
            None
        }
        sgf_parse::go::Move::Move(point) => {
            // Convert Point (x, y) to SGF coordinate string
            // Point.x becomes the first character, Point.y becomes the second character
            let coords = format!(
                "{}{}",
                (point.x + b'a') as char,
                (point.y + b'a') as char
            );
            encode_move(&coords)
        }
    }
}

/// Encode SGF coordinates (e.g., "pd") to a single number
/// SGF uses letters a-s (0-18) for both columns and rows
/// Position = col * 19 + row (where col is first char, row is second char)
fn encode_move(coords: &str) -> Option<u16> {
    if coords.len() < 2 {
        return None;
    }

    let col = coords.chars().next()? as u32;
    let row = coords.chars().nth(1)? as u32;

    // Convert letters to numbers: 'a'=0, 'b'=1, ..., 's'=18
    let col_num = col.saturating_sub('a' as u32);
    let row_num = row.saturating_sub('a' as u32);

    // Check if coordinates are valid (0-18)
    if col_num >= 19 || row_num >= 19 {
        return None;
    }

    let position = (col_num * 19 + row_num) as u16;
    Some(position)
}

/// Extract SGF property value from content
/// Looks for pattern like "DT[2017-04-10]" and returns "2017-04-10"
fn extract_sgf_property(content: &str, property: &str) -> String {
    let pattern = format!("{}[", property);
    if let Some(start) = content.find(&pattern) {
        let start = start + pattern.len();
        if let Some(end) = content[start..].find(']') {
            return content[start..start + end].to_string();
        }
    }
    String::new()
}

/// Extract game metadata from SGF content
fn extract_metadata(content: &str) -> GameMetadata {
    GameMetadata {
        date: extract_sgf_property(content, "DT"),
        black_player: extract_sgf_property(content, "PB"),
        white_player: extract_sgf_property(content, "PW"),
        black_rank: extract_sgf_property(content, "BR"),
        white_rank: extract_sgf_property(content, "WR"),
    }
}

/// Game metadata structure
pub struct GameMetadata {
    pub date: String,           // YYYY-MM-DD format
    pub black_player: String,
    pub white_player: String,
    pub black_rank: String,
    pub white_rank: String,
}

/// Compressed game data structure
pub struct CompressedGame {
    pub moves: Vec<u16>,
    pub filename: String,
    pub metadata: GameMetadata,
}

/// Compress all SGF files in a directory
pub fn compress_games_from_directory(
    input_dir: &str,
    max_games: usize,
) -> Result<Vec<CompressedGame>, Box<dyn std::error::Error>> {
    let mut games = Vec::new();
    let mut file_count = 0;

    // Read all .sgf files from directory
    for entry in fs::read_dir(input_dir)? {
        if file_count >= max_games {
            break;
        }

        let entry = entry?;
        let path = entry.path();

        if path.extension().and_then(|s| s.to_str()) == Some("sgf") {
            if let Ok(content) = fs::read_to_string(&path) {
                let moves = parse_sgf_moves(&content);
                if !moves.is_empty() {
                    let filename = path
                        .file_name()
                        .and_then(|name| name.to_str())
                        .unwrap_or("unknown.sgf")
                        .to_string();
                    let metadata = extract_metadata(&content);
                    games.push(CompressedGame { moves, filename, metadata });
                    file_count += 1;
                    let game_ref = games.last().unwrap();
                    println!("  Compressed game {} ({} moves) from {} ({} vs {} on {})",
                        file_count,
                        game_ref.moves.len(),
                        game_ref.filename,
                        game_ref.metadata.black_player,
                        game_ref.metadata.white_player,
                        game_ref.metadata.date);
                }
            }
        }
    }

    println!("Compressed {} games total", games.len());
    Ok(games)
}

/// Escape a string for use in C string literal
fn escape_c_string(s: &str) -> String {
    s.replace('\\', "\\\\")
        .replace('"', "\\\"")
        .replace('\n', "\\n")
        .replace('\r', "\\r")
}

/// Generate a C header file with game metadata
pub fn generate_metadata_header(games: &[CompressedGame], output_path: &str) -> Result<(), Box<dyn std::error::Error>> {
    let mut header = String::new();
    header.push_str("#ifndef GAMES_METADATA_H\n");
    header.push_str("#define GAMES_METADATA_H\n\n");
    header.push_str("#include <Arduino.h>\n\n");

    header.push_str("struct GameMetadata {\n");
    header.push_str("    const char* date;\n");
    header.push_str("    const char* black_player;\n");
    header.push_str("    const char* white_player;\n");
    header.push_str("    const char* black_rank;\n");
    header.push_str("    const char* white_rank;\n");
    header.push_str("};\n\n");

    // Generate string constants in PROGMEM
    header.push_str("// Metadata strings (stored in PROGMEM)\n");
    for (game_idx, game) in games.iter().enumerate() {
        header.push_str(&format!("const char GAME_{}_DATE[] PROGMEM = \"{}\";\n", game_idx, escape_c_string(&game.metadata.date)));
        header.push_str(&format!("const char GAME_{}_BLACK[] PROGMEM = \"{}\";\n", game_idx, escape_c_string(&game.metadata.black_player)));
        header.push_str(&format!("const char GAME_{}_WHITE[] PROGMEM = \"{}\";\n", game_idx, escape_c_string(&game.metadata.white_player)));
        header.push_str(&format!("const char GAME_{}_BLACK_RANK[] PROGMEM = \"{}\";\n", game_idx, escape_c_string(&game.metadata.black_rank)));
        header.push_str(&format!("const char GAME_{}_WHITE_RANK[] PROGMEM = \"{}\";\n", game_idx, escape_c_string(&game.metadata.white_rank)));
    }

    header.push_str("\n// Metadata array\n");
    header.push_str("const GameMetadata GAMES_METADATA[] PROGMEM = {\n");
    for game_idx in 0..games.len() {
        header.push_str(&format!(
            "    {{ GAME_{}_DATE, GAME_{}_BLACK, GAME_{}_WHITE, GAME_{}_BLACK_RANK, GAME_{}_WHITE_RANK }},\n",
            game_idx, game_idx, game_idx, game_idx, game_idx
        ));
    }
    header.push_str("};\n\n");
    header.push_str("#endif\n");

    fs::write(output_path, header)?;
    Ok(())
}

/// Generate a C header file with compressed game data
pub fn generate_c_header(games: &[CompressedGame], output_path: &str) -> Result<(), Box<dyn std::error::Error>> {
    let mut header = String::new();
    header.push_str("#ifndef GAMES_DATA_H\n");
    header.push_str("#define GAMES_DATA_H\n\n");
    header.push_str("#include <Arduino.h>\n\n");

    header.push_str("// Number of games stored\n");
    header.push_str(&format!("const uint16_t GAME_COUNT = {};\n\n", games.len()));

    header.push_str("// Compressed game data (stored in PROGMEM to save RAM)\n");
    header.push_str("const uint8_t GAMES_DATA[] PROGMEM = {\n");

    // Write game count as little-endian u16
    header.push_str("    // Header: game count\n");
    let count_le = (games.len() as u16).to_le_bytes();
    header.push_str(&format!("    0x{:02X}, 0x{:02X},  // Game count: {}\n", count_le[0], count_le[1], games.len()));

    // Calculate offsets for each game
    let mut offsets = Vec::new();
    let mut current_offset = 2 + (games.len() * 2); // header + offset table

    for game in games {
        offsets.push(current_offset as u16);
        current_offset += 1 + (game.moves.len() * 2); // move_count + moves
    }

    // Write offset table
    header.push_str("\n    // Offset table\n");
    for (i, offset) in offsets.iter().enumerate() {
        let offset_le = offset.to_le_bytes();
        header.push_str(&format!("    0x{:02X}, 0x{:02X},  // Game {} offset ({})\n", offset_le[0], offset_le[1], i, games[i].filename));
    }

    // Write game data
    header.push_str("\n    // Game data\n");
    for (game_idx, game) in games.iter().enumerate() {
        header.push_str(&format!("    // Game {}: {} moves (from {})\n", game_idx, game.moves.len(), game.filename));

        // Write move count
        header.push_str(&format!("    0x{:02X},\n", game.moves.len() as u8));

        // Write moves in groups of 8 for readability
        for (move_idx, mv) in game.moves.iter().enumerate() {
            if move_idx % 8 == 0 {
                header.push_str("    ");
            }

            let move_le = mv.to_le_bytes();
            header.push_str(&format!("0x{:02X}, 0x{:02X}", move_le[0], move_le[1]));

            // Add comma after each move except the very last move of the very last game
            let is_last_move = move_idx == game.moves.len() - 1;
            let is_last_game = game_idx == games.len() - 1;

            if !is_last_move || !is_last_game {
                header.push_str(",");
            }

            if !is_last_move {
                header.push_str(" ");
            }

            if (move_idx + 1) % 8 == 0 || is_last_move {
                header.push_str("\n");
            }
        }
    }

    header.push_str("};\n\n");
    header.push_str("// Total size of compressed data\n");
    header.push_str(&format!("const uint16_t GAMES_DATA_SIZE = sizeof(GAMES_DATA);\n\n"));
    header.push_str("#endif\n");

    fs::write(output_path, header)?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_encode_move() {
        assert_eq!(encode_move("aa"), Some(0));
        assert_eq!(encode_move("pd"), Some(15 * 19 + 3));
        assert_eq!(encode_move("ss"), Some(18 * 19 + 18));
    }

    #[test]
    fn test_parse_sgf_moves() {
        // Test with proper SGF game structure
        let sgf = "(;FF[4]GM[1];B[pd];W[dp];B[pq])";
        let moves = parse_sgf_moves(sgf);
        assert_eq!(moves.len(), 3);

        // Verify first move is pd -> (15, 3) -> 15*19+3 = 288
        assert_eq!(moves[0], 288);
    }

    #[test]
    fn test_parse_sgf_moves_stops_at_variations() {
        // Test that parser follows main line (first child at each node)
        // The SGF (;B[pd](;W[dp])(;W[pp])) has B[pd] with two child variations
        // main_variation() includes the first child, so we get both B[pd] and W[dp]
        let sgf = "(;FF[4]GM[1];B[pd](;W[dp])(;W[pp]))";
        let moves = parse_sgf_moves(sgf);
        assert_eq!(moves.len(), 2);
        assert_eq!(moves[0], 288); // pd
        // moves[1] is W[dp]: "dp" = (3, 15) = 3 * 19 + 15 = 72
        assert_eq!(moves[1], 72);
    }
}
