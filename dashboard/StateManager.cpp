#include "StateManager.h"
#include "config.h"

StateManager::StateManager()
    : lastBinaryClockUpdate(0),
      lastTempSensorUpdate(0),
      lastWeatherAPIUpdate(0),
      lastLastFmUpdate(0),
      lastGameOfLifeUpdate(0),
      indoorTemp(0),
      indoorHumidity(0),
      currentHour(0),
      currentMinute(0),
      currentSecond(0),
      partialUpdateCount(0),
      frontlightLevel(INITIAL_FRONTLIGHT) {}

void StateManager::init() {
    unsigned long now = millis();
    lastBinaryClockUpdate = now;
    lastTempSensorUpdate = now;
    lastWeatherAPIUpdate = now;
    lastLastFmUpdate = now;
    lastGameOfLifeUpdate = now;
    partialUpdateCount = 0;
    frontlightLevel = INITIAL_FRONTLIGHT;
}

bool StateManager::shouldUpdateBinaryClock(unsigned long currentMillis) {
    return (currentMillis - lastBinaryClockUpdate >= BINARY_CLOCK_INTERVAL);
}

bool StateManager::shouldUpdateTempSensor(unsigned long currentMillis) {
    return (currentMillis - lastTempSensorUpdate >= TEMP_SENSOR_INTERVAL);
}

bool StateManager::shouldUpdateWeather(unsigned long currentMillis) {
    return (currentMillis - lastWeatherAPIUpdate >= WEATHER_API_INTERVAL);
}

bool StateManager::shouldUpdateLastFm(unsigned long currentMillis) {
    return (currentMillis - lastLastFmUpdate >= LASTFM_API_INTERVAL);
}

bool StateManager::shouldUpdateGameOfLife(unsigned long currentMillis) {
    return (currentMillis - lastGameOfLifeUpdate >= GAME_OF_LIFE_INTERVAL);
}

void StateManager::markBinaryClockUpdated(unsigned long currentMillis) {
    lastBinaryClockUpdate = currentMillis;
}

void StateManager::markTempSensorUpdated(unsigned long currentMillis) {
    lastTempSensorUpdate = currentMillis;
}

void StateManager::markWeatherUpdated(unsigned long currentMillis) {
    lastWeatherAPIUpdate = currentMillis;
}

void StateManager::markLastFmUpdated(unsigned long currentMillis) {
    lastLastFmUpdate = currentMillis;
}

void StateManager::markGameOfLifeUpdated(unsigned long currentMillis) {
    lastGameOfLifeUpdate = currentMillis;
}

void StateManager::updateTimeFromRTC() {
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);

    currentHour = timeinfo->tm_hour;
    currentMinute = timeinfo->tm_min;
    currentSecond = timeinfo->tm_sec;
}

void StateManager::updateSensorReadings(float temp, float humidity) {
    indoorTemp = temp;
    indoorHumidity = humidity;
}

void StateManager::increaseFrontlight() {
    if (frontlightLevel < 63) {
        frontlightLevel++;
    }
}

void StateManager::decreaseFrontlight() {
    if (frontlightLevel > 0) {
        frontlightLevel--;
    }
}

void StateManager::setFrontlightLevel(int level) {
    if (level >= 0 && level <= 63) {
        frontlightLevel = level;
    }
}

String StateManager::getTemperatureString() {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%.1fF", indoorTemp);
    return String(buffer);
}

String StateManager::getHumidityString() {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%.1f%%", indoorHumidity);
    return String(buffer);
}

String StateManager::getTimeString() {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d",
             currentHour, currentMinute, currentSecond);
    return String(buffer);
}

void StateManager::printState() {
    Serial.println("=== StateManager State ===");
    Serial.print("Time: ");
    Serial.println(getTimeString());
    Serial.print("Temperature: ");
    Serial.println(getTemperatureString());
    Serial.print("Humidity: ");
    Serial.println(getHumidityString());
    Serial.print("Frontlight Level: ");
    Serial.println(frontlightLevel);
    Serial.print("Weather (stale): ");
    Serial.println(weatherData.isStale ? "Yes" : "No");
    Serial.print("Last.fm (stale): ");
    Serial.println(lastFmData.isStale ? "Yes" : "No");
    Serial.println("========================");
}
