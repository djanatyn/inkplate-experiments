#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <Inkplate.h>
#include "StateManager.h"

// ============================================================================
// Screen Layout Constants (600x600 pixels)
// ============================================================================

// Row 1: Weather and Indoor Temperature (0-149px)
#define WEATHER_X 0
#define WEATHER_Y 0
#define WEATHER_W 300
#define WEATHER_H 150

#define INDOORTEMP_X 300
#define INDOORTEMP_Y 0
#define INDOORTEMP_W 300
#define INDOORTEMP_H 150

// Row 2: Decimal Time and Binary Clock (150-299px)
#define DECIMALTIME_X 0
#define DECIMALTIME_Y 150
#define DECIMALTIME_W 300
#define DECIMALTIME_H 150

#define BINARYCLOCK_X 300
#define BINARYCLOCK_Y 150
#define BINARYCLOCK_W 300
#define BINARYCLOCK_H 150

// Row 3: Last.fm Now Playing (300-399px)
#define LASTFM_X 0
#define LASTFM_Y 300
#define LASTFM_W 600
#define LASTFM_H 100

// Row 4: Game of Life (400-599px)
#define GAMEOFLIFE_X 0
#define GAMEOFLIFE_Y 400
#define GAMEOFLIFE_W 600
#define GAMEOFLIFE_H 200

// ============================================================================
// Display Manager Class
// ============================================================================

class DisplayManager {
public:
    DisplayManager(Inkplate& display);

    // Draw entire screen layout with current state
    void drawAll(StateManager* state);

    // Draw individual widget sections
    void drawWeather(StateManager* state);
    void drawIndoorTemp(StateManager* state);
    void drawDecimalTime(StateManager* state);
    void drawBinaryClock(StateManager* state);
    void drawLastFm(StateManager* state);
    void drawGameOfLifeArea();  // Just clear/border for Game of Life to draw on
    void drawBadukArea();       // Just clear/border for Baduk to draw on

    // Utility drawing functions
    void drawSection(int x, int y, int w, int h, const char* title);
    void drawStaleIndicator(int x, int y);
    void drawBinaryDigits(int x, int y, uint8_t value, int numBits, int dotSize, int spacing);
    void drawBinaryDigitsHorizontal(int x, int y, uint8_t value, int numBits, int dotSize, int spacing);
    void drawBinarySquares(int x, int y, uint8_t value, int numBits, int squareSize, int spacing);
    void drawBorderLine(int x1, int y1, int x2, int y2);

    // Screen initialization
    void drawLoadingScreen();
    void drawWiFiErrorScreen();

    // Helper for text bounds calculation
    void getCenteredTextPosition(const char* text, int areaX, int areaW,
                                 int areaY, int areaH, int& outX, int& outY);

private:
    Inkplate& display;
};

#endif
