#ifndef BADUK_GAME_H
#define BADUK_GAME_H

#include <Inkplate.h>
#include "games_data_9x9.h"
#include "games_metadata_9x9.h"

// ============================================================================
// Display Area Layout (600x200px at bottom of screen)
// ============================================================================
// [Game Info: 400x200px]  [9x9 Board: 200x200px]
// Text on left            Board rendering on right

#define BADUK_AREA_X 0
#define BADUK_AREA_Y 400
#define BADUK_AREA_W 600
#define BADUK_AREA_H 200

// ============================================================================
// 9x9 Board Display Constants
// ============================================================================
// The 9x9 board fits in a 200x200px area with 24px grid spacing
// 8 spaces between 9 lines = 8 * 24 = 192px (centered in 200px area)

#define BADUK_BOARD_SIZE 9
#define BADUK_GRID_SPACING 24              // Space between grid lines (px)
#define BADUK_ACTUAL_BOARD_SIZE (BADUK_GRID_SPACING * (BADUK_BOARD_SIZE - 1))  // 192px
#define BADUK_STONE_RADIUS 10              // Stone radius (fits in 24px spacing)

// Board is positioned on the right side of the display area
// 200px from x=404 to x=600 gives space for the board
#define BADUK_BOARD_OFFSET_X (BADUK_AREA_X + 400 + (200 - BADUK_ACTUAL_BOARD_SIZE) / 2)  // 408px
#define BADUK_BOARD_OFFSET_Y (BADUK_AREA_Y + (BADUK_AREA_H - BADUK_ACTUAL_BOARD_SIZE) / 2)  // 404px

// ============================================================================
// 9x9 Hoshi (Star) Points
// ============================================================================
// Hoshi positions for 9x9 board: (2,2), (2,6), (4,4), (6,2), (6,6)

#define BADUK_HOSHI_COUNT 5

// ============================================================================
// BadukGame Class
// ============================================================================
// Manages a single 9x9 Go game in the dashboard display area
// Handles board state, move advancement, and rendering

class BadukGame {
public:
    // Game state (public for access from dashboard)
    uint16_t currentGameIndex;
    uint16_t currentMoveIndex;
    uint8_t moveCount;
    uint16_t totalGames;

    // Last move tracking for highlighting
    uint16_t lastMoveRow;
    uint16_t lastMoveCol;

    // Constructor
    BadukGame();

    // Initialization and game management
    void init();
    void loadGame(uint16_t gameIndex);
    void step();              // Advance one move
    void nextGame();          // Load next game in rotation

    // Rendering
    void draw(Inkplate& display);
    void drawBoard(Inkplate& display);
    void drawGridLines(Inkplate& display);
    void drawHoshiPoints(Inkplate& display);
    void drawStones(Inkplate& display);
    void drawGameInfo(Inkplate& display);

private:
    // Board state: 0=empty, 1=black, 2=white
    uint8_t board[BADUK_BOARD_SIZE][BADUK_BOARD_SIZE];

    // Helper methods for coordinate conversion
    int pixelX(int boardCol);
    int pixelY(int boardRow);
    void resetBoard();
    void applyMove(uint16_t encodedMove);
};

#endif
