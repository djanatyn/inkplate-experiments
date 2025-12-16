#include "StateManager.h"
#include "games_data.h"

StateManager::StateManager()
    : currentGameIndex(0), currentMoveIndex(0), moveCount(0),
      lastMoveUpdate(0), gameActive(false), totalGames(0),
      lastMoveRow(255), lastMoveCol(255) {
}

void StateManager::init() {
    // Initialize game order
    totalGames = GAME_COUNT;
    for (uint16_t i = 0; i < totalGames; i++) {
        gameOrder[i] = i;
    }

    // TODO: Implement random shuffling if RANDOM_GAME_ORDER is enabled

    currentGameIndex = 0;
    loadGame(0);
}

void StateManager::loadGame(uint16_t gameIndex) {
    if (gameIndex >= totalGames) {
        return;
    }

    currentGameIndex = gameIndex;
    currentMoveIndex = 0;
    lastMoveRow = 255;
    lastMoveCol = 255;
    resetBoard();
    gameActive = true;
    lastMoveUpdate = millis();

    // Read game data from PROGMEM
    uint16_t offset = pgm_read_word(&GAMES_DATA[2 + gameIndex * 2]);
    moveCount = pgm_read_byte(&GAMES_DATA[offset]);

    Serial.print("=== Loaded game ");
    Serial.print(gameIndex);
    Serial.print(" ===");
    Serial.print(" offset=");
    Serial.print(offset);
    Serial.print(" moves=");
    Serial.println(moveCount);
}

void StateManager::resetBoard() {
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;  // Empty
        }
    }
}

void StateManager::applyMove(uint16_t encodedMove) {
    // Decode position
    uint8_t row = encodedMove / BOARD_SIZE;
    uint8_t col = encodedMove % BOARD_SIZE;
    uint8_t color = (currentMoveIndex % 2 == 0) ? 1 : 2;  // 1 = black, 2 = white

    Serial.print("  Move ");
    Serial.print(currentMoveIndex);
    Serial.print(": encoded=0x");
    Serial.print(encodedMove, HEX);
    Serial.print(" row=");
    Serial.print(row);
    Serial.print(" col=");
    Serial.print(col);
    Serial.print(" color=");
    Serial.print(color == 1 ? "BLACK" : "WHITE");

    if (row < BOARD_SIZE && col < BOARD_SIZE) {
        board[row][col] = color;
        lastMoveRow = row;
        lastMoveCol = col;
        Serial.println(" ✓");
    } else {
        Serial.print(" ✗ OUT OF BOUNDS (max=");
        Serial.print(BOARD_SIZE - 1);
        Serial.println(")");
    }
}

bool StateManager::shouldPlayNextMove(unsigned long currentMillis) {
    return gameActive && (currentMillis - lastMoveUpdate >= MOVE_INTERVAL);
}

void StateManager::advanceMove() {
    if (currentMoveIndex < moveCount) {
        // Read move from PROGMEM
        uint16_t offset = pgm_read_word(&GAMES_DATA[2 + currentGameIndex * 2]);
        uint16_t moveOffset = offset + 1 + (currentMoveIndex * 2);  // +1 for move count byte

        // Read individual bytes for verification
        uint8_t byte0 = pgm_read_byte(&GAMES_DATA[moveOffset]);
        uint8_t byte1 = pgm_read_byte(&GAMES_DATA[moveOffset + 1]);
        uint16_t encodedMove = pgm_read_word(&GAMES_DATA[moveOffset]);

        Serial.print("Reading from gameOffset=");
        Serial.print(offset);
        Serial.print(" moveOffset=");
        Serial.print(moveOffset);
        Serial.print(" bytes=[0x");
        Serial.print(byte0, HEX);
        Serial.print(", 0x");
        Serial.print(byte1, HEX);
        Serial.print("] encoded=0x");
        Serial.print(encodedMove, HEX);
        Serial.println();

        applyMove(encodedMove);

        currentMoveIndex++;
    }
}

void StateManager::nextGame() {
    currentGameIndex++;
    if (currentGameIndex >= totalGames) {
        if (LOOP_GAMES) {
            currentGameIndex = 0;
        } else {
            gameActive = false;
            return;
        }
    }

    loadGame(currentGameIndex);
}
