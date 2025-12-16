#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "config.h"
#include "StateManager.h"
#include "games_metadata.h"
#include <Arduino.h>
#include <Inkplate.h>

class DisplayManager {
private:
    Inkplate& display;
    uint16_t partialUpdateCount;

public:
    DisplayManager(Inkplate& disp);

    void drawAll(StateManager* state);
    void drawBoard();
    void drawStones(StateManager* state);
    void drawGameInfo(StateManager* state);
    void drawGridLines();
    void drawHoshiPoints();
    int pixelX(int boardCol);
    int pixelY(int boardRow);
};

#endif
