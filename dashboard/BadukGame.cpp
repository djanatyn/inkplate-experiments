#include "BadukGame.h"
#include <cstring>

// ============================================================================
// Constructor
// ============================================================================

BadukGame::BadukGame()
    : currentGameIndex(0), currentMoveIndex(0), moveCount(0),
      totalGames(0), lastMoveRow(255), lastMoveCol(255) {
    resetBoard();
}

// ============================================================================
// Initialization and Setup
// ============================================================================

void BadukGame::init() {
    totalGames = GAME_COUNT;
    currentGameIndex = 0;
    loadGame(0);
}

void BadukGame::loadGame(uint16_t gameIndex) {
    if (gameIndex >= totalGames) {
        return;
    }

    currentGameIndex = gameIndex;
    currentMoveIndex = 0;
    lastMoveRow = 255;
    lastMoveCol = 255;
    resetBoard();

    // Read game data from PROGMEM
    // Format: [game_count (2 bytes)] [offset_table (2 bytes per game)] [game_data...]
    // Offset to game data from PROGMEM
    uint16_t offset = pgm_read_word(&GAMES_DATA[2 + gameIndex * 2]);
    moveCount = pgm_read_byte(&GAMES_DATA[offset]);
}

void BadukGame::resetBoard() {
    for (uint8_t i = 0; i < BADUK_BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BADUK_BOARD_SIZE; j++) {
            board[i][j] = 0;  // Empty
        }
    }
}

// ============================================================================
// Move Management
// ============================================================================

void BadukGame::applyMove(uint16_t encodedMove) {
    // Decode 9x9 position
    // For 9x9: position = col * 9 + row
    // So: col = position / 9, row = position % 9
    uint8_t col = encodedMove / BADUK_BOARD_SIZE;
    uint8_t row = encodedMove % BADUK_BOARD_SIZE;
    uint8_t color = (currentMoveIndex % 2 == 0) ? 1 : 2;  // 1 = black, 2 = white

    if (row < BADUK_BOARD_SIZE && col < BADUK_BOARD_SIZE) {
        board[row][col] = color;
        lastMoveRow = row;
        lastMoveCol = col;
    }
}

void BadukGame::step() {
    if (currentMoveIndex < moveCount) {
        // Find game data offset
        uint16_t gameOffset = pgm_read_word(&GAMES_DATA[2 + currentGameIndex * 2]);

        // Read data sequentially (new variable-length format)
        uint16_t dataOffset = gameOffset + 1;  // Skip move_count byte

        // Skip to current move by iterating through previous moves
        for (uint16_t i = 0; i < currentMoveIndex; i++) {
            dataOffset += 2;  // Move position (u16)
            uint8_t numCaptures = pgm_read_byte(&GAMES_DATA[dataOffset]);
            dataOffset += 1 + (numCaptures * 2);  // num_captures + captured positions
        }

        // Read current move
        uint8_t byte0 = pgm_read_byte(&GAMES_DATA[dataOffset]);
        uint8_t byte1 = pgm_read_byte(&GAMES_DATA[dataOffset + 1]);
        uint16_t encodedMove = byte0 | (byte1 << 8);
        dataOffset += 2;

        // Apply the move
        applyMove(encodedMove);

        // Read and apply captures
        uint8_t numCaptures = pgm_read_byte(&GAMES_DATA[dataOffset]);
        dataOffset += 1;

        for (uint8_t i = 0; i < numCaptures; i++) {
            uint8_t cap0 = pgm_read_byte(&GAMES_DATA[dataOffset]);
            uint8_t cap1 = pgm_read_byte(&GAMES_DATA[dataOffset + 1]);
            uint16_t capturedPos = cap0 | (cap1 << 8);
            dataOffset += 2;

            // Decode and remove captured stone
            uint8_t capCol = capturedPos / BADUK_BOARD_SIZE;
            uint8_t capRow = capturedPos % BADUK_BOARD_SIZE;
            if (capRow < BADUK_BOARD_SIZE && capCol < BADUK_BOARD_SIZE) {
                board[capRow][capCol] = 0;  // Remove captured stone
            }
        }

        currentMoveIndex++;
    } else if (currentMoveIndex >= moveCount) {
        // Game finished, advance to next game
        nextGame();
    }
}

void BadukGame::nextGame() {
    uint16_t nextIndex = (currentGameIndex + 1) % totalGames;
    loadGame(nextIndex);
}

// ============================================================================
// Coordinate Conversion
// ============================================================================

int BadukGame::pixelX(int boardCol) {
    return BADUK_BOARD_OFFSET_X + (boardCol * BADUK_GRID_SPACING);
}

int BadukGame::pixelY(int boardRow) {
    return BADUK_BOARD_OFFSET_Y + (boardRow * BADUK_GRID_SPACING);
}

// ============================================================================
// Rendering
// ============================================================================

void BadukGame::draw(Inkplate& display) {
    drawGameInfo(display);
    drawBoard(display);
    drawStones(display);
}

void BadukGame::drawBoard(Inkplate& display) {
    display.setTextSize(1);
    display.setTextColor(BLACK);

    // Draw grid lines
    drawGridLines(display);

    // Draw hoshi (star) points
    drawHoshiPoints(display);

    // Draw board edge
    display.drawRect(pixelX(0), pixelY(0),
                     BADUK_GRID_SPACING * (BADUK_BOARD_SIZE - 1),
                     BADUK_GRID_SPACING * (BADUK_BOARD_SIZE - 1),
                     BLACK);
}

void BadukGame::drawGridLines(Inkplate& display) {
    // Draw vertical lines
    for (int col = 0; col < BADUK_BOARD_SIZE; col++) {
        int x = pixelX(col);
        display.drawLine(x, pixelY(0), x, pixelY(BADUK_BOARD_SIZE - 1), BLACK);
    }

    // Draw horizontal lines
    for (int row = 0; row < BADUK_BOARD_SIZE; row++) {
        int y = pixelY(row);
        display.drawLine(pixelX(0), y, pixelX(BADUK_BOARD_SIZE - 1), y, BLACK);
    }
}

void BadukGame::drawHoshiPoints(Inkplate& display) {
    // Hoshi (star) points on a 9x9 board
    int hoshis[BADUK_HOSHI_COUNT][2] = {
        {2, 2}, {2, 6}, {4, 4}, {6, 2}, {6, 6}
    };

    for (int i = 0; i < BADUK_HOSHI_COUNT; i++) {
        int x = pixelX(hoshis[i][0]);
        int y = pixelY(hoshis[i][1]);
        display.fillCircle(x, y, 2, BLACK);
    }
}

void BadukGame::drawStones(Inkplate& display) {
    for (int row = 0; row < BADUK_BOARD_SIZE; row++) {
        for (int col = 0; col < BADUK_BOARD_SIZE; col++) {
            uint8_t cell = board[row][col];

            if (cell == 1) {
                // Black stone - filled circle
                display.fillCircle(pixelX(col), pixelY(row), BADUK_STONE_RADIUS, BLACK);
            } else if (cell == 2) {
                // White stone - outlined circle
                display.drawCircle(pixelX(col), pixelY(row), BADUK_STONE_RADIUS, BLACK);
                // Fill with white by drawing a slightly smaller filled white circle
                display.fillCircle(pixelX(col), pixelY(row), BADUK_STONE_RADIUS - 1, WHITE);
            }

            // Mark the last stone with a small circle (inverted color for visibility)
            if (row == lastMoveRow && col == lastMoveCol && currentMoveIndex > 0) {
                int x = pixelX(col);
                int y = pixelY(row);
                int markerRadius = 3;
                // Invert color: WHITE marker on black stones, BLACK marker on white stones
                int markerColor = (cell == 1) ? WHITE : BLACK;
                display.fillCircle(x, y, markerRadius, markerColor);
            }
        }
    }
}

void BadukGame::drawGameInfo(Inkplate& display) {
    display.setTextSize(2);
    display.setTextColor(BLACK);

    // Read metadata from PROGMEM
    GameMetadata metadata;
    memcpy_P(&metadata, &GAMES_METADATA[currentGameIndex], sizeof(GameMetadata));

    // Calculate text position (left 300px area)
    int infoX = BADUK_AREA_X + 20;
    int lineHeight = 25;
    int y = BADUK_AREA_Y + 10;

    // Line 1: Game number
    display.setCursor(infoX, y);
    display.print("Game ");
    display.print(currentGameIndex + 1);
    display.print("/");
    display.println(totalGames);

    // Line 2: Move counter
    y += lineHeight;
    display.setCursor(infoX, y);
    display.print("Move ");
    display.print(currentMoveIndex);
    display.print("/");
    display.println(moveCount);

    // Line 3: Date
    y += lineHeight;
    display.setCursor(infoX, y);
    char dateBuffer[12];
    strcpy_P(dateBuffer, metadata.date);
    display.println(dateBuffer);

    // Line 4: Black player and rank
    y += lineHeight;
    display.setCursor(infoX, y);
    display.print("B:");
    char blackBuffer[20];
    strcpy_P(blackBuffer, metadata.black_player);
    display.print(blackBuffer);
    display.print(" (");
    char blackRankBuffer[6];
    strcpy_P(blackRankBuffer, metadata.black_rank);
    display.print(blackRankBuffer);
    display.println(")");

    // Line 5: White player and rank
    y += lineHeight;
    display.setCursor(infoX, y);
    display.print("W:");
    char whiteBuffer[20];
    strcpy_P(whiteBuffer, metadata.white_player);
    display.print(whiteBuffer);
    display.print(" (");
    char whiteRankBuffer[6];
    strcpy_P(whiteRankBuffer, metadata.white_rank);
    display.print(whiteRankBuffer);
    display.println(")");
}
