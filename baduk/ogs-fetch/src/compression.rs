use std::fs;
use sgf_parse::{parse, go::Prop};
use goban::rules::game::Game;
use goban::rules::{GobanSizes, Move as GobanMove, CHINESE};
use goban::pieces::stones::Color;

/// Parse SGF moves from a game file and track captures
/// Extracts moves in the format ;B[pd] or ;W[cd]
/// Also simulates the game to detect captured stones
/// Only parses the main line, stops at variation branches
pub fn parse_sgf_moves(content: &str, board_size: u32) -> (Vec<u16>, Vec<Vec<u16>>) {
    let mut moves = Vec::new();
    let mut captures_per_move = Vec::new();

    // Parse SGF with sgf-parse library
    let Ok(game_trees) = parse(content) else {
        return (moves, captures_per_move);
    };

    // Get the first game tree
    let Some(game_tree) = game_trees.first() else {
        return (moves, captures_per_move);
    };

    // Convert GameTree to SgfNode and get the root node
    let Ok(root_node) = game_tree.as_go_node() else {
        return (moves, captures_per_move);
    };

    // Create goban game for capture simulation
    let goban_size = match board_size {
        9 => GobanSizes::Nine,
        13 => GobanSizes::Thirteen,
        19 => GobanSizes::Nineteen,
        _ => return (moves, captures_per_move),
    };
    let mut game = Game::new(goban_size, CHINESE);

    // Iterate through the main variation
    for node in root_node.main_variation() {
        // Check for move properties (B for black, W for white)
        for prop in node.properties() {
            match prop {
                Prop::B(mv) | Prop::W(mv) => {
                    // Convert move to our coordinate format and encode
                    if let Some(encoded) = encode_move_from_lib(&mv, board_size) {
                        // Snapshot board before move
                        let before = snapshot_board(&game, board_size);

                        // Play move on goban simulation (use try_play to handle errors gracefully)
                        if let Some(coord) = extract_coord_from_lib(&mv) {
                            match game.try_play(GobanMove::Play(coord.0, coord.1)) {
                                Ok(_) => {
                                    // Move was successful
                                    moves.push(encoded);

                                    // Snapshot board after move
                                    let after = snapshot_board(&game, board_size);

                                    // Find captured stones
                                    let captured = find_captured_stones(&before, &after, board_size);
                                    captures_per_move.push(captured);
                                }
                                Err(e) => {
                                    // Skip this move if it's illegal
                                    eprintln!("Warning: Skipping illegal move {:?} at position ({},{}): {:?}",
                                              mv, coord.0, coord.1, e);
                                }
                            }
                        }
                    }
                }
                _ => {}
            }
        }
    }

    (moves, captures_per_move)
}

/// Snapshot board state from goban game
fn snapshot_board(game: &Game, board_size: u32) -> Vec<Option<Color>> {
    let mut board = Vec::new();
    for row in 0..board_size {
        for col in 0..board_size {
            board.push(game.goban().get_color((row as u8, col as u8)));
        }
    }
    board
}

/// Find stones that were removed (captured) by comparing board states
fn find_captured_stones(
    before: &[Option<Color>],
    after: &[Option<Color>],
    board_size: u32,
) -> Vec<u16> {
    let mut captured = Vec::new();
    for (index, (before_color, after_color)) in before.iter().zip(after.iter()).enumerate() {
        // Stone existed before but not after = captured
        if before_color.is_some() && after_color.is_none() {
            // Convert linear index back to position
            let row = (index / board_size as usize) as u16;
            let col = (index % board_size as usize) as u16;
            let position = col * board_size as u16 + row;
            captured.push(position);
        }
    }
    captured
}

/// Extract (x, y) coordinate from sgf-parse Move
fn extract_coord_from_lib(mv: &sgf_parse::go::Move) -> Option<(u8, u8)> {
    match mv {
        sgf_parse::go::Move::Move(point) => Some((point.x as u8, point.y as u8)),
        _ => None,
    }
}

/// Helper to convert sgf-parse Move to our u16 encoding
fn encode_move_from_lib(mv: &sgf_parse::go::Move, board_size: u32) -> Option<u16> {
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
            encode_move(&coords, board_size)
        }
    }
}

/// Encode SGF coordinates (e.g., "pd") to a single number
/// SGF uses letters a-s (0-18) for 19x19, a-i (0-8) for 9x9
/// Position = col * board_size + row (where col is first char, row is second char)
fn encode_move(coords: &str, board_size: u32) -> Option<u16> {
    if coords.len() < 2 {
        return None;
    }

    let col = coords.chars().next()? as u32;
    let row = coords.chars().nth(1)? as u32;

    // Convert letters to numbers: 'a'=0, 'b'=1, ..., 's'=18
    let col_num = col.saturating_sub('a' as u32);
    let row_num = row.saturating_sub('a' as u32);

    // Check if coordinates are valid for the given board size
    if col_num >= board_size || row_num >= board_size {
        return None;
    }

    let position = (col_num * board_size + row_num) as u16;
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

/// Check if a game has handicap stones (HA property)
fn has_handicap(content: &str) -> bool {
    // Look for HA[n] property where n > 0
    if let Some(start) = content.find("HA[") {
        let start = start + 3;
        if let Some(end) = content[start..].find(']') {
            if let Ok(handicap_str) = content[start..start + end].parse::<i32>() {
                return handicap_str > 0;
            }
        }
    }
    false
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
    pub captures: Vec<Vec<u16>>,  // Captured stone positions for each move
    pub filename: String,
    pub metadata: GameMetadata,
}

/// Compress all SGF files in a directory
pub fn compress_games_from_directory(
    input_dir: &str,
    board_size: u32,
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
                // Skip games with handicap stones
                if has_handicap(&content) {
                    let filename = path
                        .file_name()
                        .and_then(|name| name.to_str())
                        .unwrap_or("unknown.sgf")
                        .to_string();
                    println!("  Skipping handicap game: {}", filename);
                    continue;
                }

                let (moves, captures) = parse_sgf_moves(&content, board_size);
                if !moves.is_empty() {
                    let filename = path
                        .file_name()
                        .and_then(|name| name.to_str())
                        .unwrap_or("unknown.sgf")
                        .to_string();
                    let metadata = extract_metadata(&content);
                    games.push(CompressedGame { moves, captures, filename, metadata });
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

/// Generate a C header file with compressed game data including captures
pub fn generate_c_header(games: &[CompressedGame], output_path: &str) -> Result<(), Box<dyn std::error::Error>> {
    let mut header = String::new();
    header.push_str("#ifndef GAMES_DATA_H\n");
    header.push_str("#define GAMES_DATA_H\n\n");
    header.push_str("#include <Arduino.h>\n\n");

    header.push_str("// Number of games stored\n");
    header.push_str(&format!("const uint16_t GAME_COUNT = {};\n\n", games.len()));

    header.push_str("// Compressed game data with captures (stored in PROGMEM to save RAM)\n");
    header.push_str("// Format: For each game: u8 move_count, then for each move: u16 position, u8 num_captures, u16*num_captures positions\n");
    header.push_str("const uint8_t GAMES_DATA[] PROGMEM = {\n");

    // Write game count as little-endian u16
    header.push_str("    // Header: game count\n");
    let count_le = (games.len() as u16).to_le_bytes();
    header.push_str(&format!("    0x{:02X}, 0x{:02X},  // Game count: {}\n", count_le[0], count_le[1], games.len()));

    // Calculate offsets for each game (need to account for variable-length capture data)
    let mut offsets = Vec::new();
    let mut current_offset = 2 + (games.len() * 2); // header + offset table

    for game in games {
        offsets.push(current_offset as u16);

        // For this game: move_count (1 byte) + for each move: position (2 bytes) + num_captures (1 byte) + captures (variable)
        current_offset += 1; // move_count

        for (move_idx, _) in game.moves.iter().enumerate() {
            current_offset += 2; // position (u16)
            current_offset += 1; // num_captures (u8)
            if let Some(captures) = game.captures.get(move_idx) {
                current_offset += captures.len() * 2; // each capture is u16
            }
        }
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

        // Write each move with its captures
        for (move_idx, mv) in game.moves.iter().enumerate() {
            // Write move position
            let move_le = mv.to_le_bytes();
            header.push_str(&format!("    0x{:02X}, 0x{:02X},", move_le[0], move_le[1]));

            // Get captures for this move
            let captures = game.captures.get(move_idx).cloned().unwrap_or_default();
            header.push_str(&format!("  0x{:02X}", captures.len() as u8));

            // Write captured stone positions
            for captured_pos in captures.iter() {
                let cap_le = captured_pos.to_le_bytes();
                header.push_str(&format!(", 0x{:02X}, 0x{:02X}", cap_le[0], cap_le[1]));
            }

            // Add comma after each move except the last move of the last game
            let is_last_move = move_idx == game.moves.len() - 1;
            let is_last_game = game_idx == games.len() - 1;

            if !is_last_move || !is_last_game {
                header.push_str(",");
            }

            header.push_str(&format!("  // Move {}: pos={}\n", move_idx, mv));
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
        assert_eq!(encode_move("aa", 19), Some(0));
        assert_eq!(encode_move("pd", 19), Some(15 * 19 + 3));
        assert_eq!(encode_move("ss", 19), Some(18 * 19 + 18));
    }

    #[test]
    fn test_parse_sgf_moves() {
        // Test with proper SGF game structure
        let sgf = "(;FF[4]GM[1];B[pd];W[dp];B[pq])";
        let (moves, captures) = parse_sgf_moves(sgf, 19);
        assert_eq!(moves.len(), 3);
        assert_eq!(captures.len(), 3);

        // Verify first move is pd -> (15, 3) -> 15*19+3 = 288
        assert_eq!(moves[0], 288);
    }

    #[test]
    fn test_parse_sgf_moves_stops_at_variations() {
        // Test that parser follows main line (first child at each node)
        // The SGF (;B[pd](;W[dp])(;W[pp])) has B[pd] with two child variations
        // main_variation() includes the first child, so we get both B[pd] and W[dp]
        let sgf = "(;FF[4]GM[1];B[pd](;W[dp])(;W[pp]))";
        let (moves, captures) = parse_sgf_moves(sgf, 19);
        assert_eq!(moves.len(), 2);
        assert_eq!(captures.len(), 2);
        assert_eq!(moves[0], 288); // pd
        // moves[1] is W[dp]: "dp" = (3, 15) = 3 * 19 + 15 = 72
        assert_eq!(moves[1], 72);
    }

    #[test]
    fn test_handicap_detection() {
        // Game with handicap stones
        let sgf_with_handicap = "(;FF[4]GM[1]HA[2];B[pd];W[dp])";
        assert!(has_handicap(sgf_with_handicap));

        // Game without handicap stones
        let sgf_no_handicap = "(;FF[4]GM[1];B[pd];W[dp])";
        assert!(!has_handicap(sgf_no_handicap));

        // Game with HA[0] should not be treated as handicap
        let sgf_zero_handicap = "(;FF[4]GM[1]HA[0];B[pd];W[dp])";
        assert!(!has_handicap(sgf_zero_handicap));
    }

    #[test]
    fn test_capture_detection_structure() {
        // Test that the capture detection mechanism is working correctly
        // Parse a 9x9 game and verify structure
        let sgf = "(;FF[4]GM[1]SZ[9];B[de];W[ce];W[df];W[ee];W[dd])";
        let (moves, captures) = parse_sgf_moves(sgf, 9);

        // We should have moves and matching capture lists
        assert_eq!(moves.len(), 5);
        assert_eq!(captures.len(), 5);
        assert_eq!(moves.len(), captures.len());

        // Each capture list should be a Vec<u16> (may be empty for non-capture moves)
        for (i, (mv, caps)) in moves.iter().zip(captures.iter()).enumerate() {
            println!("Move {}: position={}, captures={:?}", i, mv, caps);
            // Captures should be reasonable positions (0-80 for 9x9)
            for captured_pos in caps {
                assert!(*captured_pos < 81, "Captured position {} is outside 9x9 board", captured_pos);
            }
        }

        // The first move should be at position 31 (d5)
        assert_eq!(moves[0], 31);
        // First move typically has no captures
        assert!(captures[0].is_empty());
    }

    #[test]
    fn test_captures_in_real_game_snippet() {
        // Test with a real OGS 9x9 game (game 9034489 from https://online-go.com/game/9034489)
        // Played between GnuGo (Black) and djanatyn (White)
        // Uses the actual SGF file from the test_game_9034489.sgf in src/

        // Read the SGF file the same way compress_games_from_directory does
        let sgf_content = fs::read_to_string("src/test_game_9034489.sgf")
            .expect("Failed to read test SGF file");

        // Skip games with handicap stones
        assert!(!has_handicap(&sgf_content), "Test game should not have handicap stones");

        // Parse the game using the same function as production code
        let (moves, captures) = parse_sgf_moves(&sgf_content, 9);

        println!("\n=== OGS Game 9034489 Capture Analysis ===");
        println!("Parsed {} moves from real OGS game 9034489", moves.len());

        // Verify we have captures data for each move
        assert_eq!(moves.len(), captures.len());

        // Count how many moves had captures
        let moves_with_captures = captures.iter().filter(|c| !c.is_empty()).count();
        println!("Found {} moves with captures out of {}\n", moves_with_captures, moves.len());

        // Print out detailed capture information with board visualization
        // Recreate the game using goban to show the board state when captures occur
        let mut game = Game::new(GobanSizes::Nine, CHINESE);
        for (i, (mv, caps)) in moves.iter().zip(captures.iter()).enumerate() {
            // Decode move to coordinates
            let col = mv / 9;
            let row = mv % 9;

            // Play the move
            game.play(GobanMove::Play(col as u8, row as u8));

            if !caps.is_empty() {
                println!("\nMove {}: captured {} stones", i, caps.len());
                println!("{}", game.goban());  // Use goban's built-in board display
            }
        }

        // Verify the structure is correct
        assert!(!moves.is_empty(), "Should have parsed moves from the game");
        assert_eq!(moves.len(), captures.len(), "Moves and captures should have same length");

        // Verify captures are valid board positions (0-80 for 9x9)
        for capture_list in &captures {
            for pos in capture_list {
                assert!(*pos < 81, "Capture position {} is invalid for 9x9 board", pos);
            }
        }
    }

    #[test]
    fn test_no_captures_early_game() {
        // Simple opening moves without captures
        let sgf = "(;FF[4]GM[1]SZ[19];B[pd];W[dp];B[pq];W[pp])";
        let (moves, captures) = parse_sgf_moves(sgf, 19);

        assert_eq!(moves.len(), 4);
        assert_eq!(captures.len(), 4);

        // Early game opening moves shouldn't have captures
        for capture_list in &captures {
            assert!(capture_list.is_empty(), "No captures should occur in opening moves");
        }
    }
}
