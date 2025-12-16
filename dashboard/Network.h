#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "StateManager.h"

// ============================================================================
// Network Class for API Integration
// ============================================================================

class Network {
public:
    Network();

    // WiFi management
    void begin(const char* ssid, const char* password, int timeout);
    bool isConnected();
    void reconnect(const char* ssid, const char* password, int timeout);

    // API operations
    bool fetchWeather(WeatherData* data, float latitude, float longitude);
    bool fetchLastFm(LastFmData* data, const char* apiKey, const char* username);

private:
    // JSON parsing
    bool parseWeatherJSON(const JsonDocument& doc, WeatherData* data);
    bool parseLastFmJSON(const JsonDocument& doc, LastFmData* data);

    // Helper methods
    String makeHTTPRequest(const char* url);
    bool parseJSONFromResponse(const String& response, JsonDocument& doc);
};

#endif
