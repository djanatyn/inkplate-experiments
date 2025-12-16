#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <Arduino.h>
#include <Inkplate.h>

// ============================================================================
// Game of Life Configuration
// ============================================================================

// Screen area for Game of Life (400-599px)
#define GOL_AREA_X 0
#define GOL_AREA_Y 400
#define GOL_AREA_WIDTH 600
#define GOL_AREA_HEIGHT 200

// Cell size (pixels)
#define GOL_CELL_SIZE 10

// Calculated grid dimensions
#define GOL_COLS (GOL_AREA_WIDTH / GOL_CELL_SIZE)    // 60 columns
#define GOL_ROWS (GOL_AREA_HEIGHT / GOL_CELL_SIZE)   // 20 rows

// ============================================================================
// Game of Life Class
// ============================================================================

class GameOfLife {
public:
    GameOfLife();

    // Initialize the Game of Life with random state
    void init();

    // Perform one step of the simulation
    void step();

    // Draw the current state to display
    void draw(Inkplate& display);

    // Reset to a new random state
    void randomize();

private:
    // Grid cells (using uint8_t for each cell's age)
    // 0 = dead, 1+ = alive (value indicates age for fade effect)
    uint8_t gridA[GOL_COLS * GOL_ROWS];
    uint8_t gridB[GOL_COLS * GOL_ROWS];

    uint8_t* currentGrid;
    uint8_t* nextGrid;

    int frameCount;
    int cellDelta;  // Track cell changes to detect stability

    // Helper methods
    int countNeighbors(int x, int y);
    int getGridIndex(int x, int y);
    void swapGrids();
};

#endif
