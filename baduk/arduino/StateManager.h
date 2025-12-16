#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "config.h"
#include "games_metadata.h"
#include <Arduino.h>

class StateManager {
public:
    // Current game state
    uint16_t currentGameIndex;
    uint16_t currentMoveIndex;
    uint8_t moveCount;
    unsigned long lastMoveUpdate;

    // Board state (19x19 grid)
    // 0 = empty, 1 = black, 2 = white
    uint8_t board[BOARD_SIZE][BOARD_SIZE];

    // Playback state
    bool gameActive;
    uint16_t gameOrder[255];  // Support up to 255 games
    uint16_t totalGames;

    // Current game metadata (store index, read pointers on demand from GAMES_METADATA)
    uint16_t lastMoveRow;
    uint16_t lastMoveCol;

    StateManager();
    void init();
    void loadGame(uint16_t gameIndex);
    void resetBoard();
    void applyMove(uint16_t encodedMove);
    bool shouldPlayNextMove(unsigned long currentMillis);
    void advanceMove();
    void nextGame();
};

#endif
