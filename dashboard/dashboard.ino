/*
  Inkplate 4 TEMPERA Dashboard

  Features:
  - Weather display from Weatherbit API
  - Indoor temperature and humidity from BME688 sensor
  - Decimal and binary time displays
  - Last.fm now playing track
  - Frontlight control via touchscreen
  - Conway's Game of Life simulation

  Board: Inkplate 4 TEMPERA
  Display: 600x600 pixels, e-ink
  Author: User
  Date: 2024
*/

// Include all necessary libraries and headers
#include <Inkplate.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <time.h>

// Include project headers
#include "config.h"
#include "StateManager.h"
#include "Network.h"
#include "DisplayManager.h"
#include "GameOfLife.h"

// ============================================================================
// Global Objects
// ============================================================================

Inkplate display(INKPLATE_1BIT);
StateManager stateManager;
Network network;
DisplayManager displayManager(display);
GameOfLife gameOfLife;

// ============================================================================
// Timing Variables
// ============================================================================

unsigned long lastBinaryClockUpdate = 0;
unsigned long lastTempSensorUpdate = 0;
unsigned long lastWeatherAPIUpdate = 0;
unsigned long lastLastFmUpdate = 0;
unsigned long lastGameOfLifeUpdate = 0;

// ============================================================================
// Setup Function
// ============================================================================

void setup() {
    // 1. Initialize Serial for debugging
    Serial.begin(115200);
    delay(100);

    Serial.println("\n=== Inkplate 4 TEMPERA Dashboard Starting ===\n");

    // 2. Initialize display
    Serial.println("Initializing display...");
    display.begin();
    display.clearDisplay();
    display.display();

    // 3. Show loading screen
    displayManager.drawLoadingScreen();

    // 4. Initialize peripherals
    Serial.println("Initializing peripherals...");

    // BME688 sensor
    display.wakePeripheral(INKPLATE_BME688);
    if (!display.bme688.begin()) {
        Serial.println("ERROR: BME688 initialization failed!");
    } else {
        Serial.println("BME688 initialized successfully");
    }

    // Touchscreen
    if (!display.tsInit(true)) {
        Serial.println("ERROR: Touchscreen initialization failed!");
    } else {
        Serial.println("Touchscreen initialized successfully");
    }

    // Frontlight
    display.frontlight(true);
    display.setFrontlight(INITIAL_FRONTLIGHT);
    stateManager.frontlightLevel = INITIAL_FRONTLIGHT;
    Serial.print("Frontlight enabled at level: ");
    Serial.println(INITIAL_FRONTLIGHT);

    // 5. Connect to WiFi
    Serial.println("\nConnecting to WiFi...");
    network.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_TIMEOUT);

    if (!network.isConnected()) {
        Serial.println("ERROR: WiFi connection failed!");
        displayManager.drawWiFiErrorScreen();
        display.display();
        while (true) {
            delay(1000);  // Halt
        }
    }

    // 6. Synchronize time via NTP
    Serial.println("Synchronizing time via NTP...");
    configTime(TIMEZONE_OFFSET * 3600, 0, "pool.ntp.org");

    // Wait for time to be set
    int timeRetries = 0;
    time_t now = time(nullptr);
    while (now < 24 * 3600 && timeRetries < 10) {
        delay(500);
        Serial.print(".");
        now = time(nullptr);
        timeRetries++;
    }
    Serial.println();

    if (now < 24 * 3600) {
        Serial.println("WARNING: Time sync may have failed");
    } else {
        Serial.println("Time synchronized successfully");
    }

    // 7. Fetch initial data
    Serial.println("\nFetching initial data...");

    // Weather
    Serial.println("Fetching weather data...");
    network.fetchWeather(&stateManager.weatherData, WEATHER_LATITUDE, WEATHER_LONGITUDE);

    // Last.fm
    Serial.println("Fetching Last.fm data...");
    network.fetchLastFm(&stateManager.lastFmData, LASTFM_API_KEY, LASTFM_USERNAME);

    // Read initial sensor data
    float temp = display.bme688.readTemperature() + BME688_TEMP_OFFSET;
    // Convert to Fahrenheit
    temp = (temp * 9.0 / 5.0) + 32.0;
    float humidity = display.bme688.readHumidity();
    stateManager.updateSensorReadings(temp, humidity);

    Serial.println("Initial data fetch complete");

    // 8. Initialize Game of Life
    Serial.println("Initializing Game of Life...");
    gameOfLife.init();

    // 9. Initialize state manager
    Serial.println("Initializing state manager...");
    stateManager.init();

    // 10. Draw initial screen
    Serial.println("Drawing initial screen...");
    stateManager.updateTimeFromRTC();
    displayManager.drawAll(&stateManager);
    gameOfLife.draw(display);
    display.display();

    Serial.println("\n=== Setup Complete ===\n");
}

// ============================================================================
// Main Loop
// ============================================================================

void loop() {
    unsigned long currentMillis = millis();
    bool needsDisplayUpdate = false;

    // 1. Update binary clock and decimal time (every 1 second)
    if (stateManager.shouldUpdateBinaryClock(currentMillis)) {
        Serial.println("Updating time display...");
        stateManager.updateTimeFromRTC();
        displayManager.drawDecimalTime(&stateManager);
        displayManager.drawBinaryClock(&stateManager);
        stateManager.markBinaryClockUpdated(currentMillis);
        needsDisplayUpdate = true;
    }

    // 2. Read BME688 sensor (every 30 seconds)
    if (stateManager.shouldUpdateTempSensor(currentMillis)) {
        Serial.println("Reading BME688 sensor...");
        float temp = display.bme688.readTemperature() + BME688_TEMP_OFFSET;
        // Convert to Fahrenheit
        temp = (temp * 9.0 / 5.0) + 32.0;
        float humidity = display.bme688.readHumidity();
        stateManager.updateSensorReadings(temp, humidity);
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print("F, Humidity: ");
        Serial.print(humidity);
        Serial.println("%");
        displayManager.drawIndoorTemp(&stateManager);
        stateManager.markTempSensorUpdated(currentMillis);
        needsDisplayUpdate = true;
    }

    // 3. Fetch weather data (every 10 minutes)
    if (stateManager.shouldUpdateWeather(currentMillis)) {
        Serial.println("Fetching weather data...");
        if (network.isConnected()) {
            network.fetchWeather(&stateManager.weatherData, WEATHER_LATITUDE, WEATHER_LONGITUDE);
        } else {
            Serial.println("WiFi disconnected, skipping weather fetch");
            stateManager.weatherData.isStale = true;
        }
        displayManager.drawWeather(&stateManager);
        stateManager.markWeatherUpdated(currentMillis);
        needsDisplayUpdate = true;
    }

    // 4. Fetch Last.fm data (every 10 minutes)
    if (stateManager.shouldUpdateLastFm(currentMillis)) {
        Serial.println("Fetching Last.fm data...");
        if (network.isConnected()) {
            network.fetchLastFm(&stateManager.lastFmData, LASTFM_API_KEY, LASTFM_USERNAME);
        } else {
            Serial.println("WiFi disconnected, skipping Last.fm fetch");
            stateManager.lastFmData.isStale = true;
        }
        displayManager.drawLastFm(&stateManager);
        stateManager.markLastFmUpdated(currentMillis);
        needsDisplayUpdate = true;
    }

    // 5. Update Game of Life (every 200ms)
    if (stateManager.shouldUpdateGameOfLife(currentMillis)) {
        gameOfLife.step();
        gameOfLife.draw(display);
        stateManager.markGameOfLifeUpdated(currentMillis);
        needsDisplayUpdate = true;
    }

    // 6. Handle touchscreen input for frontlight control
    handleTouchInput();

    // 7. Perform display update if needed
    if (needsDisplayUpdate) {
        stateManager.partialUpdateCount++;

        if (stateManager.partialUpdateCount >= FULL_REFRESH_EVERY) {
            Serial.println("Performing full display refresh...");
            display.display();
            stateManager.partialUpdateCount = 0;
        } else {
            display.partialUpdate();
        }
    }

    // Small delay to prevent tight loop and allow other tasks
    delay(10);
}

// ============================================================================
// Helper Functions
// ============================================================================

void handleTouchInput() {
    // Check if top half of screen is touched (increase brightness)
    if (display.touchInArea(0, 0, 600, 300)) {
        Serial.println("Touch detected in top half (increase brightness)");
        stateManager.increaseFrontlight();
        display.setFrontlight(stateManager.frontlightLevel);
        Serial.print("Frontlight level: ");
        Serial.println(stateManager.frontlightLevel);
        delay(200);  // Debounce
    }

    // Check if bottom half of screen is touched (decrease brightness)
    if (display.touchInArea(0, 300, 600, 300)) {
        Serial.println("Touch detected in bottom half (decrease brightness)");
        stateManager.decreaseFrontlight();
        display.setFrontlight(stateManager.frontlightLevel);
        Serial.print("Frontlight level: ");
        Serial.println(stateManager.frontlightLevel);
        delay(200);  // Debounce
    }
}
