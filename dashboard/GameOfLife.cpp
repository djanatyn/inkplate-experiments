#include "GameOfLife.h"

GameOfLife::GameOfLife()
    : currentGrid(gridA),
      nextGrid(gridB),
      frameCount(0),
      cellDelta(0) {
    // Initialize grids to all dead cells
    memset(gridA, 0, GOL_COLS * GOL_ROWS);
    memset(gridB, 0, GOL_COLS * GOL_ROWS);
}

void GameOfLife::init() {
    randomize();
}

int GameOfLife::getGridIndex(int x, int y) {
    // Wrap around edges (toroidal topology)
    int wrappedX = x;
    int wrappedY = y;

    if (wrappedX < 0) wrappedX = GOL_COLS - 1;
    if (wrappedX >= GOL_COLS) wrappedX = 0;
    if (wrappedY < 0) wrappedY = GOL_ROWS - 1;
    if (wrappedY >= GOL_ROWS) wrappedY = 0;

    return wrappedX + wrappedY * GOL_COLS;
}

int GameOfLife::countNeighbors(int x, int y) {
    int count = 0;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;  // Skip the cell itself

            int neighborX = x + dx;
            int neighborY = y + dy;
            int index = getGridIndex(neighborX, neighborY);

            if (currentGrid[index] > 0) {
                count++;
            }
        }
    }

    return count;
}

void GameOfLife::swapGrids() {
    uint8_t* temp = currentGrid;
    currentGrid = nextGrid;
    nextGrid = temp;
}

void GameOfLife::step() {
    cellDelta = 0;

    // Clear next grid
    memset(nextGrid, 0, GOL_COLS * GOL_ROWS);

    // Apply Conway's Game of Life rules
    for (int y = 0; y < GOL_ROWS; y++) {
        for (int x = 0; x < GOL_COLS; x++) {
            int index = x + y * GOL_COLS;
            uint8_t cellState = currentGrid[index];
            int neighbors = countNeighbors(x, y);

            uint8_t nextState = 0;

            // Conway's rules:
            // 1. Any live cell with 2-3 neighbors survives
            // 2. Any dead cell with exactly 3 neighbors becomes alive
            // 3. All other cells die or stay dead

            if (cellState > 0) {
                // Cell is currently alive
                if (neighbors == 2 || neighbors == 3) {
                    nextState = cellState + 1;  // Age the cell
                    if (nextState > 15) nextState = 15;  // Cap at 15 for visual aging
                }
            } else {
                // Cell is currently dead
                if (neighbors == 3) {
                    nextState = 1;  // Birth of a new cell
                }
            }

            // Track changes
            if ((nextState > 0) != (cellState > 0)) {
                cellDelta++;
            }

            nextGrid[index] = nextState;
        }
    }

    // Swap grids
    swapGrids();
    frameCount++;

    // Reset if pattern stabilizes (low change rate)
    if (cellDelta * GOL_CELL_SIZE < frameCount) {
        randomize();
    }
}

void GameOfLife::draw(Inkplate& display) {
    // Draw current grid state
    for (int y = 0; y < GOL_ROWS; y++) {
        for (int x = 0; x < GOL_COLS; x++) {
            int index = x + y * GOL_COLS;
            uint8_t cellState = currentGrid[index];

            int pixelX = GOL_AREA_X + x * GOL_CELL_SIZE;
            int pixelY = GOL_AREA_Y + y * GOL_CELL_SIZE;

            if (cellState > 0) {
                // Alive cell - draw as filled square
                // Younger cells are darker, older cells fade
                if (cellState == 1) {
                    // New cells - solid black
                    display.fillRect(pixelX, pixelY, GOL_CELL_SIZE, GOL_CELL_SIZE, BLACK);
                } else {
                    // Older cells - draw filled with fading by drawing smaller
                    int fadeSize = GOL_CELL_SIZE - (cellState - 1);
                    if (fadeSize > 0) {
                        display.fillRect(pixelX + (GOL_CELL_SIZE - fadeSize) / 2,
                                        pixelY + (GOL_CELL_SIZE - fadeSize) / 2,
                                        fadeSize, fadeSize, BLACK);
                    }
                }
            } else {
                // Dead cell - draw as white/empty
                display.fillRect(pixelX, pixelY, GOL_CELL_SIZE, GOL_CELL_SIZE, WHITE);
            }
        }
    }
}

void GameOfLife::randomize() {
    frameCount = 0;
    cellDelta = 0;

    // Clear both grids
    memset(gridA, 0, GOL_COLS * GOL_ROWS);
    memset(gridB, 0, GOL_COLS * GOL_ROWS);

    // Random population with 15-25% density
    int density = random(15, 26);  // 15-25%

    for (int y = 0; y < GOL_ROWS; y++) {
        for (int x = 0; x < GOL_COLS; x++) {
            int index = x + y * GOL_COLS;
            // Create living cell if random number < density
            if (random(100) < density) {
                gridA[index] = 1;  // New cell (age 1)
            }
        }
    }

    Serial.println("Game of Life randomized");
}
