#include "Network.h"

Network::Network() {}

void Network::begin(const char* ssid, const char* password, int timeout) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi: ");
    Serial.println(ssid);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < timeout) {
        delay(1000);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println();
        Serial.print("WiFi connected! IP address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println();
        Serial.println("Failed to connect to WiFi");
    }
}

bool Network::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void Network::reconnect(const char* ssid, const char* password, int timeout) {
    if (!isConnected()) {
        Serial.println("WiFi disconnected, reconnecting...");
        begin(ssid, password, timeout);
    }
}

String Network::makeHTTPRequest(const char* url) {
    HTTPClient http;
    String response = "";

    // Disable SSL certificate verification for Weatherbit HTTPS
    // In production, you should verify certificates properly
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    http.getStream().setTimeout(10);
    http.getStream().flush();

    Serial.print("Making request to: ");
    Serial.println(url);

    if (!http.begin(url)) {
        Serial.println("Failed to connect to server");
        http.end();
        return "";
    }

    int httpCode = http.GET();
    Serial.print("HTTP response code: ");
    Serial.println(httpCode);

    if (httpCode == 200) {
        // Use getString() to properly handle chunked encoding and other HTTP protocol details
        response = http.getString();
        Serial.print("Response length: ");
        Serial.println(response.length());

        // Log response (truncate if too long)
        Serial.println("Response content:");
        if (response.length() > 1000) {
            Serial.println(response.substring(0, 1000));
            Serial.println("... (truncated)");
        } else {
            Serial.println(response);
        }
    } else {
        Serial.print("HTTP request failed with code: ");
        Serial.println(httpCode);
    }

    http.end();
    return response;
}

bool Network::parseJSONFromResponse(const String& response, JsonDocument& doc) {
    if (response.length() == 0) {
        Serial.println("Empty response");
        return false;
    }

    // Log response info
    Serial.print("Response length: ");
    Serial.println(response.length());
    Serial.println("Response preview (first 300 chars):");
    if (response.length() > 300) {
        Serial.println(response.substring(0, 300));
        Serial.println("[... truncated ...]");
    } else {
        Serial.println(response);
    }

    DeserializationError error = deserializeJson(doc, response);

    if (error) {
        Serial.print("JSON parse error: ");
        Serial.println(error.c_str());
        Serial.print("Error code: ");
        Serial.println((int)error.code());
        Serial.print("Error string: ");
        switch (error.code()) {
            case DeserializationError::InvalidInput: Serial.println("InvalidInput"); break;
            case DeserializationError::NoMemory: Serial.println("NoMemory"); break;
            case DeserializationError::IncompleteInput: Serial.println("IncompleteInput"); break;
            default: Serial.println("Other error"); break;
        }
        return false;
    }

    Serial.print("JSON deserialized successfully. Doc is: ");
    if (doc.is<JsonObject>()) {
        Serial.println("Object");
    } else if (doc.is<JsonArray>()) {
        Serial.println("Array");
    } else {
        Serial.println("Unknown type");
    }
    Serial.print("Doc size: ");
    Serial.println(doc.size());

    // Log all keys and their types if document is an object
    if (doc.is<JsonObject>()) {
        Serial.println("Available keys in document:");
        for (JsonPairConst kv : doc.as<JsonObjectConst>()) {
            Serial.print("  \"");
            Serial.print(kv.key().c_str());
            Serial.print("\" => ");

            if (kv.value().is<JsonObject>()) {
                Serial.println("Object");
            } else if (kv.value().is<JsonArray>()) {
                Serial.println("Array");
            } else if (kv.value().is<const char*>()) {
                Serial.print("String: \"");
                Serial.print(kv.value().as<const char*>());
                Serial.println("\"");
            } else if (kv.value().is<float>()) {
                Serial.print("Float: ");
                Serial.println(kv.value().as<float>());
            } else if (kv.value().is<int>()) {
                Serial.print("Int: ");
                Serial.println(kv.value().as<int>());
            } else if (kv.value().isNull()) {
                Serial.println("NULL");
            } else {
                Serial.println("Unknown type");
            }
        }
    }

    return true;
}

bool Network::parseWeatherJSON(const JsonDocument& doc, WeatherData* data) {
    Serial.println("\n=== Parsing Weather JSON (Open-Meteo) ===");

    if (!doc.containsKey("current")) {
        Serial.println("ERROR: missing 'current' field");
        return false;
    }

    if (!doc["current"].containsKey("temperature_2m")) {
        Serial.println("ERROR: missing 'temperature_2m' field");
        return false;
    }

    // Extract temperature (already in Celsius)
    float tempCelsius = doc["current"]["temperature_2m"].as<float>();
    Serial.print("Temperature (Celsius): ");
    Serial.println(tempCelsius);

    // Convert to Fahrenheit
    data->temperature = (tempCelsius * 9.0 / 5.0) + 32.0;

    // Extract humidity
    data->humidity = 0;
    if (doc["current"].containsKey("relative_humidity_2m")) {
        data->humidity = doc["current"]["relative_humidity_2m"].as<float>();
    }
    Serial.print("Humidity: ");
    Serial.println(data->humidity);

    // Extract weather code and convert to description
    int weatherCode = 0;
    if (doc["current"].containsKey("weather_code")) {
        weatherCode = doc["current"]["weather_code"].as<int>();
    }
    Serial.print("Weather Code: ");
    Serial.println(weatherCode);

    // Map WMO weather codes to descriptions
    data->description = "";
    if (weatherCode == 0 || weatherCode == 1) {
        data->description = "Clear";
    } else if (weatherCode == 2) {
        data->description = "Mostly Clear";
    } else if (weatherCode == 3) {
        data->description = "Overcast";
    } else if (weatherCode >= 45 && weatherCode <= 48) {
        data->description = "Foggy";
    } else if (weatherCode >= 51 && weatherCode <= 67) {
        data->description = "Drizzle";
    } else if (weatherCode >= 71 && weatherCode <= 77) {
        data->description = "Snow";
    } else if (weatherCode >= 80 && weatherCode <= 82) {
        data->description = "Rain";
    } else if (weatherCode >= 85 && weatherCode <= 86) {
        data->description = "Snow Showers";
    } else if (weatherCode >= 80 && weatherCode <= 99) {
        data->description = "Thunderstorm";
    } else {
        data->description = "Unknown";
    }

    Serial.print("=== Final Weather Data ===");
    Serial.print(data->temperature);
    Serial.print("F, ");
    Serial.println(data->description);
    Serial.println("===========================\n");

    return true;
}

bool Network::parseLastFmJSON(const JsonDocument& doc, LastFmData* data) {
    Serial.println("\n=== Parsing Last.fm JSON ===");
    Serial.print("Document size: ");
    Serial.println(doc.size());

    if (!doc.containsKey("recenttracks")) {
        Serial.println("ERROR: missing 'recenttracks' field");
        return false;
    }

    if (!doc["recenttracks"].containsKey("track")) {
        Serial.println("ERROR: missing 'track' field");
        return false;
    }

    Serial.print("Track type: ");
    if (doc["recenttracks"]["track"].is<JsonArray>()) {
        Serial.println("Array");
    } else if (doc["recenttracks"]["track"].is<JsonObject>()) {
        Serial.println("Object");
    } else {
        Serial.println("Unknown");
    }

    // Last.fm returns track as an array or single object, we want the first element if array
    int trackIndex = 0;
    if (doc["recenttracks"]["track"].is<JsonArray>()) {
        size_t trackSize = doc["recenttracks"]["track"].size();
        Serial.print("Track array size: ");
        Serial.println(trackSize);
        if (trackSize == 0) {
            Serial.println("ERROR: Track array is empty");
            return false;
        }
        trackIndex = 0;  // Access first element below
    }

    Serial.println("Track object data:");
    if (doc["recenttracks"]["track"][trackIndex].containsKey("name")) {
        Serial.print("  name: ");
        Serial.println(doc["recenttracks"]["track"][trackIndex]["name"].as<const char*>());
    }
    if (doc["recenttracks"]["track"][trackIndex].containsKey("artist")) {
        Serial.println("  artist: found");
    }
    if (doc["recenttracks"]["track"][trackIndex].containsKey("album")) {
        Serial.println("  album: found");
    }

    // Get artist
    data->artist = "";
    if (doc["recenttracks"]["track"][trackIndex].containsKey("artist")) {
        // Try to get #text field (artist is usually an object with #text field)
        if (doc["recenttracks"]["track"][trackIndex]["artist"].containsKey("#text")) {
            data->artist = String(doc["recenttracks"]["track"][trackIndex]["artist"]["#text"].as<const char*>());
        }
        // Fallback: try direct string conversion
        if (data->artist.length() == 0) {
            const char* artistStr = doc["recenttracks"]["track"][trackIndex]["artist"].as<const char*>();
            if (artistStr != nullptr) {
                data->artist = String(artistStr);
            }
        }
    }
    Serial.print("Artist: ");
    Serial.println(data->artist);

    // Get track name
    data->track = "";
    if (doc["recenttracks"]["track"][trackIndex].containsKey("name")) {
        data->track = String(doc["recenttracks"]["track"][trackIndex]["name"].as<const char*>());
    }
    Serial.print("Track: ");
    Serial.println(data->track);

    // Get album
    data->album = "";
    if (doc["recenttracks"]["track"][trackIndex].containsKey("album")) {
        // Try to get #text field (album is usually an object with #text field)
        if (doc["recenttracks"]["track"][trackIndex]["album"].containsKey("#text")) {
            data->album = String(doc["recenttracks"]["track"][trackIndex]["album"]["#text"].as<const char*>());
        }
        // Fallback: try direct string conversion
        if (data->album.length() == 0) {
            const char* albumStr = doc["recenttracks"]["track"][trackIndex]["album"].as<const char*>();
            if (albumStr != nullptr) {
                data->album = String(albumStr);
            }
        }
    }
    Serial.print("Album: ");
    Serial.println(data->album);

    Serial.println("============================\n");

    return true;
}

bool Network::fetchWeather(WeatherData* data, float latitude, float longitude) {
    if (!isConnected()) {
        Serial.println("Not connected to WiFi, cannot fetch weather");
        data->isStale = true;
        return false;
    }

    char url[256];
    snprintf(url, sizeof(url),
             "http://api.open-meteo.com/v1/forecast?latitude=%.4f&longitude=%.4f&current=temperature_2m,weather_code,relative_humidity_2m",
             latitude, longitude);

    String response = makeHTTPRequest(url);

    if (response.length() == 0) {
        data->isStale = true;
        Serial.println("Weather fetch failed");
        return false;
    }

    JsonDocument doc;  // ArduinoJson 7 auto-allocates with elastic memory

    if (!parseJSONFromResponse(response, doc)) {
        data->isStale = true;
        Serial.println("Weather JSON parse failed");
        return false;
    }

    if (!parseWeatherJSON(doc, data)) {
        data->isStale = true;
        Serial.println("Weather data extraction failed");
        return false;
    }

    data->isStale = false;
    data->lastUpdate = millis();

    doc.clear();
    return true;
}

bool Network::fetchLastFm(LastFmData* data, const char* apiKey, const char* username) {
    if (!isConnected()) {
        Serial.println("Not connected to WiFi, cannot fetch Last.fm data");
        data->isStale = true;
        return false;
    }

    char url[512];
    snprintf(url, sizeof(url),
             "http://ws.audioscrobbler.com/2.0/?method=user.getrecenttracks&user=%s&limit=1&api_key=%s&format=json",
             username, apiKey);

    String response = makeHTTPRequest(url);

    if (response.length() == 0) {
        data->isStale = true;
        Serial.println("Last.fm fetch failed");
        return false;
    }

    JsonDocument doc;  // ArduinoJson 7 auto-allocates with elastic memory

    if (!parseJSONFromResponse(response, doc)) {
        data->isStale = true;
        Serial.println("Last.fm JSON parse failed");
        return false;
    }

    if (!parseLastFmJSON(doc, data)) {
        data->isStale = true;
        Serial.println("Last.fm data extraction failed");
        return false;
    }

    data->isStale = false;
    data->lastUpdate = millis();

    doc.clear();
    return true;
}
