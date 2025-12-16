#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <Arduino.h>
#include <time.h>

// ============================================================================
// Display Mode Enumeration
// ============================================================================

enum DisplayMode {
    MODE_GAME_OF_LIFE = 0,
    MODE_BADUK = 1
};

// ============================================================================
// Data Structures for Caching API Responses
// ============================================================================

struct WeatherData {
    float temperature;
    String description;
    float humidity;
    bool isStale;
    unsigned long lastUpdate;

    WeatherData() : temperature(0), description(""), humidity(0), isStale(true), lastUpdate(0) {}
};

struct LastFmData {
    String artist;
    String album;
    String track;
    bool isStale;
    unsigned long lastUpdate;

    LastFmData() : artist(""), album(""), track(""), isStale(true), lastUpdate(0) {}
};

// ============================================================================
// System State Manager Class
// ============================================================================

class StateManager {
public:
    // Timing variables for update intervals
    unsigned long lastBinaryClockUpdate;
    unsigned long lastTempSensorUpdate;
    unsigned long lastWeatherAPIUpdate;
    unsigned long lastLastFmUpdate;
    unsigned long lastGameOfLifeUpdate;

    // Cached data from APIs
    WeatherData weatherData;
    LastFmData lastFmData;

    // Sensor data
    float indoorTemp;
    float indoorHumidity;

    // RTC time
    uint8_t currentHour;
    uint8_t currentMinute;
    uint8_t currentSecond;

    // Display state
    int partialUpdateCount;
    int frontlightLevel;

    // Display mode and baduk timing
    DisplayMode displayMode;
    unsigned long lastBadukUpdate;

    // Constructor
    StateManager();

    // Initialize all timing variables to now
    void init();

    // Check if enough time has passed to update each feature
    bool shouldUpdateBinaryClock(unsigned long currentMillis);
    bool shouldUpdateTempSensor(unsigned long currentMillis);
    bool shouldUpdateWeather(unsigned long currentMillis);
    bool shouldUpdateLastFm(unsigned long currentMillis);
    bool shouldUpdateGameOfLife(unsigned long currentMillis);
    bool shouldUpdateBaduk(unsigned long currentMillis);

    // Update timestamps after performing an update
    void markBinaryClockUpdated(unsigned long currentMillis);
    void markTempSensorUpdated(unsigned long currentMillis);
    void markWeatherUpdated(unsigned long currentMillis);
    void markLastFmUpdated(unsigned long currentMillis);
    void markGameOfLifeUpdated(unsigned long currentMillis);
    void markBadukUpdated(unsigned long currentMillis);

    // Display mode management
    void switchDisplayMode(DisplayMode mode);
    void loadDisplayModeFromEEPROM();
    void saveDisplayModeToEEPROM();

    // Update current time from RTC
    void updateTimeFromRTC();

    // Update sensor readings
    void updateSensorReadings(float temp, float humidity);

    // Manage frontlight level (0-63)
    void increaseFrontlight();
    void decreaseFrontlight();
    void setFrontlightLevel(int level);

    // Get formatted strings for display
    String getTemperatureString();
    String getHumidityString();
    String getTimeString();

    // Debug logging
    void printState();
};

#endif
