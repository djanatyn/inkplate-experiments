#include "DisplayManager.h"
#include "config.h"

DisplayManager::DisplayManager(Inkplate& disp) : display(disp) {}

void DisplayManager::drawAll(StateManager* state) {
    // Clear the entire display
    display.clearDisplay();

    // Draw each widget section
    drawWeather(state);
    drawIndoorTemp(state);
    drawDecimalTime(state);
    drawBinaryClock(state);
    drawLastFm(state);
    drawGameOfLifeArea();

    // Draw divider lines between sections
    display.drawLine(300, 0, 300, 300, BLACK);      // Vertical line between weather/temp and time/clock
    display.drawLine(0, 150, 600, 150, BLACK);      // Horizontal line between row 1 and row 2
    display.drawLine(0, 300, 600, 300, BLACK);      // Horizontal line between row 2 and Last.fm
}

void DisplayManager::drawWeather(StateManager* state) {
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setTextWrap(false);

    // Clear section
    display.fillRect(WEATHER_X, WEATHER_Y, WEATHER_W, WEATHER_H, WHITE);

    // City name (small)
    display.setTextSize(1);
    display.setCursor(WEATHER_X + 20, WEATHER_Y + 8);
    display.println(WEATHER_CITY);

    // Weather data
    if (state->weatherData.temperature == 0 && !state->weatherData.isStale) {
        // No data yet
        display.setCursor(WEATHER_X + 20, WEATHER_Y + 50);
        display.println("Loading...");
    } else {
        // Temperature
        char tempStr[32];
        snprintf(tempStr, sizeof(tempStr), "%.1fF", state->weatherData.temperature);
        display.setTextSize(3);
        display.setCursor(WEATHER_X + 20, WEATHER_Y + 25);
        display.println(tempStr);

        // Description (truncated if too long)
        String desc = state->weatherData.description;
        if (desc.length() > 15) {
            desc = desc.substring(0, 12) + "...";
        }
        display.setTextSize(2);
        display.setCursor(WEATHER_X + 20, WEATHER_Y + 75);
        display.println(desc);

        // Humidity
        char humidStr[32];
        snprintf(humidStr, sizeof(humidStr), "Humidity: %.0f%%", state->weatherData.humidity);
        display.setTextSize(2);
        display.setCursor(WEATHER_X + 20, WEATHER_Y + 105);
        display.println(humidStr);

        // Stale indicator
        if (state->weatherData.isStale) {
            drawStaleIndicator(WEATHER_X + 270, WEATHER_Y + 10);
        }
    }
}

void DisplayManager::drawIndoorTemp(StateManager* state) {
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setTextWrap(false);

    // Clear section
    display.fillRect(INDOORTEMP_X, INDOORTEMP_Y, INDOORTEMP_W, INDOORTEMP_H, WHITE);

    // Title
    display.setCursor(INDOORTEMP_X + 15, INDOORTEMP_Y + 10);
    display.println("Indoor");

    // Temperature
    char tempStr[32];
    snprintf(tempStr, sizeof(tempStr), "%.1fF", state->indoorTemp);
    display.setTextSize(3);
    display.setCursor(INDOORTEMP_X + 15, INDOORTEMP_Y + 45);
    display.println(tempStr);

    // Humidity
    char humidStr[32];
    snprintf(humidStr, sizeof(humidStr), "%.1f%%", state->indoorHumidity);
    display.setTextSize(2);
    display.setCursor(INDOORTEMP_X + 15, INDOORTEMP_Y + 90);
    display.print("Humidity: ");
    display.println(humidStr);
}

void DisplayManager::drawDecimalTime(StateManager* state) {
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setTextWrap(false);

    // Clear section
    display.fillRect(DECIMALTIME_X, DECIMALTIME_Y, DECIMALTIME_W, DECIMALTIME_H, WHITE);

    // Title
    display.setCursor(DECIMALTIME_X + 20, DECIMALTIME_Y + 10);
    display.println("Time");

    // Current time in HH:MM:SS format
    char timeStr[32];
    snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d",
             state->currentHour, state->currentMinute, state->currentSecond);

    display.setTextSize(3);
    display.setCursor(DECIMALTIME_X + 20, DECIMALTIME_Y + 60);
    display.println(timeStr);
}

void DisplayManager::drawBinaryClock(StateManager* state) {
    // Clear section
    display.fillRect(BINARYCLOCK_X, BINARYCLOCK_Y, BINARYCLOCK_W, BINARYCLOCK_H, WHITE);

    // Layout parameters - maximize square size
    int marginX = 5;
    int marginY = 5;
    int squareSize = 43;      // Size of each bit indicator (square)
    int spacingH = 3;         // Horizontal spacing between squares
    int spacingV = 5;         // Vertical spacing between rows
    int labelWidth = 12;      // Width allocated for H/M/S labels
    int labelMargin = 3;      // Margin between label and squares

    int startX = BINARYCLOCK_X + marginX + labelWidth + labelMargin;
    int startY = BINARYCLOCK_Y + marginY;

    // Small labels on the left side
    display.setTextSize(1);
    display.setTextColor(BLACK);

    display.setCursor(BINARYCLOCK_X + marginX, startY + squareSize / 2 - 4);
    display.print("H");

    display.setCursor(BINARYCLOCK_X + marginX, startY + squareSize + spacingV + squareSize / 2 - 4);
    display.print("M");

    display.setCursor(BINARYCLOCK_X + marginX, startY + 2 * (squareSize + spacingV) + squareSize / 2 - 4);
    display.print("S");

    // Hours (top row) - 6 bits for 0-23
    drawBinarySquares(startX, startY, state->currentHour, 6, squareSize, spacingH);

    // Minutes (middle row) - 6 bits for 0-59
    drawBinarySquares(startX, startY + squareSize + spacingV, state->currentMinute, 6, squareSize, spacingH);

    // Seconds (bottom row) - 6 bits for 0-59
    drawBinarySquares(startX, startY + 2 * (squareSize + spacingV), state->currentSecond, 6, squareSize, spacingH);
}

void DisplayManager::drawBinaryDigits(int x, int y, uint8_t value, int numBits, int dotSize, int spacing) {
    for (int i = numBits - 1; i >= 0; i--) {
        bool isBitSet = (value >> i) & 1;
        int dotY = y + ((numBits - 1 - i) * spacing);

        if (isBitSet) {
            // Filled circle for 1
            display.fillCircle(x, dotY, dotSize / 2, BLACK);
        } else {
            // Empty circle for 0
            display.drawCircle(x, dotY, dotSize / 2, BLACK);
        }
    }
}

void DisplayManager::drawBinarySquares(int x, int y, uint8_t value, int numBits, int squareSize, int spacing) {
    // Draw bits as squares (filled for 1, outline for 0)
    for (int i = numBits - 1; i >= 0; i--) {
        bool isBitSet = (value >> i) & 1;
        int squareX = x + ((numBits - 1 - i) * (squareSize + spacing));

        if (isBitSet) {
            // Filled square for 1
            display.fillRect(squareX, y, squareSize, squareSize, BLACK);
        } else {
            // Empty square (outline) for 0
            display.drawRect(squareX, y, squareSize, squareSize, BLACK);
        }
    }
}

void DisplayManager::drawLastFm(StateManager* state) {
    display.setTextColor(BLACK);
    display.setTextWrap(false);

    // Clear section
    display.fillRect(LASTFM_X, LASTFM_Y, LASTFM_W, LASTFM_H, WHITE);

    // Truncate long strings to fit on display
    String artist = state->lastFmData.artist;
    if (artist.length() > 45) {
        artist = artist.substring(0, 42) + "...";
    }

    String track = state->lastFmData.track;
    if (track.length() > 45) {
        track = track.substring(0, 42) + "...";
    }

    String album = state->lastFmData.album;
    if (album.length() > 45) {
        album = album.substring(0, 42) + "...";
    }

    // Display track name (largest, most important)
    display.setTextSize(3);
    display.setCursor(LASTFM_X + 20, LASTFM_Y + 3);
    display.println(track);

    // Display artist (medium)
    display.setTextSize(2);
    display.setCursor(LASTFM_X + 20, LASTFM_Y + 32);
    display.println(artist);

    // Display album (medium)
    display.setTextSize(2);
    display.setCursor(LASTFM_X + 20, LASTFM_Y + 54);
    display.println(album);

    // Stale indicator
    if (state->lastFmData.isStale) {
        drawStaleIndicator(LASTFM_X + 570, LASTFM_Y + 5);
    }
}

void DisplayManager::drawGameOfLifeArea() {
    // Clear the Game of Life area
    display.fillRect(GAMEOFLIFE_X, GAMEOFLIFE_Y, GAMEOFLIFE_W, GAMEOFLIFE_H, WHITE);

    // Draw a border around it
    display.drawRect(GAMEOFLIFE_X, GAMEOFLIFE_Y, GAMEOFLIFE_W, GAMEOFLIFE_H, BLACK);
}

void DisplayManager::drawBadukArea() {
    // Clear the Baduk (9x9 Go) display area
    // Board starts at y=385 (overlaps Last.fm by 15px)
    // Stones extend 10px beyond grid boundaries (radius = 10px)
    // So clear from y=370 (385-15px overlap-10px stone radius) to y=600
    // Height: 230px (covers board + overlap + stone diameter on all sides)
    display.fillRect(GAMEOFLIFE_X, GAMEOFLIFE_Y - 30, GAMEOFLIFE_W, GAMEOFLIFE_H + 30, WHITE);
}

void DisplayManager::drawStaleIndicator(int x, int y) {
    // Draw a small "!" indicator for stale data
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(x, y);
    display.print("!");
}

void DisplayManager::drawSection(int x, int y, int w, int h, const char* title) {
    // Draw a simple rectangular section with a title
    display.drawRect(x, y, w, h, BLACK);

    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(x + 5, y + 5);
    display.println(title);
}

void DisplayManager::drawLoadingScreen() {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(BLACK);
    display.setCursor(150, 250);
    display.println("Initializing...");
    display.display();
}

void DisplayManager::drawWiFiErrorScreen() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(50, 200);
    display.println("WiFi Connection");
    display.setCursor(100, 250);
    display.println("Failed!");
    display.setTextSize(1);
    display.setCursor(50, 350);
    display.println("Check SSID and password in config.h");
    display.display();
}

void DisplayManager::getCenteredTextPosition(const char* text, int areaX, int areaW,
                                             int areaY, int areaH, int& outX, int& outY) {
    // This is a placeholder for centering text within an area
    // In a full implementation, you'd use display.getTextBounds()
    outX = areaX + 10;
    outY = areaY + 10;
}
