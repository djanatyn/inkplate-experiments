/*
   Baduk (Go) Game Viewer for Inkplate 4 TEMPERA

   This sketch displays Go game records on the Inkplate 4 TEMPERA e-ink display.
   Games are compressed and stored in PROGMEM, and played move-by-move.

   For use with the ogs-fetch Rust CLI tool to download and compress games.
*/

#include "Inkplate.h"
#include "config.h"
#include "StateManager.h"
#include "DisplayManager.h"
#include "games_data.h"

// Create display object
Inkplate display(INKPLATE_1BIT);

// Create state manager and display manager
StateManager stateManager;
DisplayManager displayManager(display);

void setup() {
    Serial.begin(115200);
    display.begin();
    display.setTextColor(BLACK);

    // Initialize frontlight
    display.frontlight(true);
    display.setFrontlight(INITIAL_FRONTLIGHT);
    Serial.print("Frontlight enabled at level: ");
    Serial.println(INITIAL_FRONTLIGHT);

    Serial.println("Baduk Game Viewer Starting...");

    // Initialize state and load first game
    stateManager.init();

    Serial.print("Total games: ");
    Serial.println(stateManager.totalGames);

    // Draw initial board
    displayManager.drawAll(&stateManager);
    display.display();
}

void loop() {
    unsigned long currentMillis = millis();

    // Check if it's time to play next move
    if (stateManager.shouldPlayNextMove(currentMillis)) {
        stateManager.advanceMove();

        // Check if game is over
        if (stateManager.currentMoveIndex >= stateManager.moveCount) {
            Serial.println("Game finished, moving to next game...");
            delay(5000);  // Pause before next game
            stateManager.nextGame();
        }

        // Redraw board with new move
        displayManager.drawAll(&stateManager);

        stateManager.lastMoveUpdate = currentMillis;
    }

    // Small delay to avoid busy-waiting
    delay(100);
}
