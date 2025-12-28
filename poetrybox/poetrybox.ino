/*
 * Poetrybox - e-ink poetry display for my beloved
 */

#include "events_data.h"
#include "poems_data.h"
#include <Inkplate.h>

/*
class PageBuffer {
private:
    char* buffer_;
    size_t size_;

public:
    // Constructor: Acquire resource
    explicit PageBuffer(size_t size)
        : buffer_(static_cast<char*>(malloc(size)))
        , size_(size) {}

    // Destructor: Release resource (ALWAYS called when object goes out of
scope) ~PageBuffer() { if (buffer_ != nullptr) { free(buffer_);
        }
    }

    // Delete copy operations (prevent accidental double-free)
    PageBuffer(const PageBuffer&) = delete;
    PageBuffer& operator=(const PageBuffer&) = delete;

    // Accessors
    char* data() { return buffer_; }
    const char* data() const { return buffer_; }
    size_t size() const { return size_; }

    // Check if allocation succeeded
    explicit operator bool() const { return buffer_ != nullptr; }
};
*/

Inkplate display(INKPLATE_1BIT);

// temperature calibration offset
constexpr float BME688_TEMP_OFFSET = -4.0f;

// display modes
enum class DisplayMode : uint8_t { Poem = 0, Events = 1 };

// display layout
constexpr int SCREEN_WIDTH = 600;
constexpr int SCREEN_HEIGHT = 600;

// header area for time/temperature
constexpr int HEADER_HEIGHT = 50;
constexpr int HEADER_Y = 0;

// poetry area
constexpr int POETRY_Y = HEADER_HEIGHT + 10;
constexpr int POETRY_WIDTH = SCREEN_WIDTH - 40;
constexpr int POETRY_X = 40;

// display state
constexpr unsigned long DISPLAY_DURATION_MS = 30000; // 30 seconds per screen
DisplayMode displayMode = DisplayMode::Poem;
uint8_t currentPoemId = 0;
uint16_t currentPageIdx = 0;
unsigned long lastDisplayChangeTime = 0;

// sensor state
constexpr unsigned long SENSOR_READ_INTERVAL_MS =
    60000; // read sensor every 60 seconds
float currentTemp = 0.0;
unsigned long lastSensorReadTime = 0;

// serial command state
String serialBuffer = {};

// backlight state
uint8_t backlightLevel = 20; // 0-63

uint16_t getCurrentPoemPageCount() {
  uint16_t firstPage = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);
  uint16_t nextPoemFirstPage =
      (currentPoemId < POEM_COUNT - 1)
          ? pgm_read_word(&POEM_FIRST_PAGE[currentPoemId + 1])
          : TOTAL_PAGES;
  return nextPoemFirstPage - firstPage;
}

uint16_t getCurrentPageNumber() {
  uint16_t poemFirstPage = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);
  return currentPageIdx - poemFirstPage + 1; // 1-indexed for display
}

bool isOnLastPageOfPoem() {
  uint16_t nextPoemFirstPage =
      (currentPoemId < POEM_COUNT - 1)
          ? pgm_read_word(&POEM_FIRST_PAGE[currentPoemId + 1])
          : TOTAL_PAGES;
  return currentPageIdx + 1 >= nextPoemFirstPage;
}

void goToPoem(uint8_t poemId) {
  if (poemId < POEM_COUNT) {
    currentPoemId = poemId;
    currentPageIdx = pgm_read_word(&POEM_FIRST_PAGE[poemId]);
    Serial.printf("jumped to poem %d, page %d/%d\n", currentPoemId,
                  getCurrentPageNumber(), getCurrentPoemPageCount());
  }
}

void nextPage() {
  uint16_t nextPoemFirstPage =
      (currentPoemId < POEM_COUNT - 1)
          ? pgm_read_word(&POEM_FIRST_PAGE[currentPoemId + 1])
          : TOTAL_PAGES;

  if (currentPageIdx + 1 < nextPoemFirstPage) {
    currentPageIdx++;
    Serial.printf("next page: %d/%d in poem %d\n", getCurrentPageNumber(),
                  getCurrentPoemPageCount(), currentPoemId);
  } else {
    Serial.println("already at last page of poem");
  }
}

void prevPage() {
  uint16_t poemFirstPage = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);

  if (currentPageIdx > poemFirstPage) {
    currentPageIdx--;
    Serial.printf("previous page: %d/%d in poem %d\n", getCurrentPageNumber(),
                  getCurrentPoemPageCount(), currentPoemId);
  } else {
    Serial.println("already at first page of poem");
  }
}

void nextPoem() {
  if (currentPoemId < POEM_COUNT - 1) {
    currentPoemId++;
    currentPageIdx = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);
    Serial.printf("next poem: %d (%d pages)\n", currentPoemId,
                  getCurrentPoemPageCount());
  } else {
    // wrap to first poem
    currentPoemId = 0;
    currentPageIdx = 0;
    Serial.printf("wrapped to first poem: %d\n", currentPoemId);
  }
}

void prevPoem() {
  if (currentPoemId > 0) {
    currentPoemId--;
    currentPageIdx = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);
    Serial.printf("previous poem: %d (%d pages)\n", currentPoemId,
                  getCurrentPoemPageCount());
  } else {
    // wrap to last poem
    currentPoemId = POEM_COUNT - 1;
    currentPageIdx = pgm_read_word(&POEM_FIRST_PAGE[currentPoemId]);
    Serial.printf("wrapped to last poem: %d\n", currentPoemId);
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  display.begin();
  display.clearDisplay();
  display.display();

  Serial.println("\n\n=== Poetrybox ===");
  Serial.printf("total poems: %d\n", POEM_COUNT);
  Serial.printf("total pages: %d\n", TOTAL_PAGES);

  // init sensor
  Serial.println("initializing BME688 sensor...");
  display.wakePeripheral(INKPLATE_BME688);
  if (!display.bme688.begin()) {
    Serial.println("ERROR: BME688 initialization failed!");
  } else {
    Serial.println("BME688 initialized successfully");
    // read initial temperature
    currentTemp = readTemperature();
  }

  // allow setting clock
  Serial.println("\nRTC Setup:");
  Serial.println("send 'set HH:MM [YYYY-MM-DD]' to set time and date");
  Serial.println("> set 14:32 2025-12-17");
  Serial.println("press enter to skip");

  // wait 30 seconds for user input
  unsigned long waitStart = millis();
  String input = "";
  // is this an appropriate way to wait?
  while (millis() - waitStart < (30 * 1000)) {
    if (Serial.available()) {
      char c = Serial.read();
      if (c == '\n') {
        break;
      }
      input += c;
    }
  }

  if (input.startsWith("set ")) {
    parseAndSetTime(input);
  } else {
    Serial.println("skipping time setup");
  }

  Serial.println("\nstarting display...");

  // Set initial backlight
  display.frontlight(true);
  display.setFrontlight(backlightLevel);
  Serial.printf("backlight set to: %d\n", backlightLevel);

  drawScreen();
  lastDisplayChangeTime = millis();
  lastSensorReadTime = millis();

  Serial.println("\n=== commands ===");
  Serial.println("set HH:MM [YYYY-MM-DD] - set time/date");
  Serial.println("backlight N            - set backlight (0-63)");
  Serial.println("list                   - list all poems");
  Serial.println("poem N                 - jump to poem N");
  Serial.println("next                   - next poem");
  Serial.println("prev                   - previous poem");
  Serial.println("page next              - next page");
  Serial.println("page prev              - previous page");
  Serial.println(
      "events [N]             - list N upcoming events (default 10)");
  Serial.println("allevents              - list all events in calendar");
  Serial.println("mode [poem|events]     - switch display mode");
  Serial.println("================\n");
}

void loop() {
  unsigned long currentTime = millis();
  processSerialCommands();
  handleTouchInput();

  // change display?
  if (currentTime - lastDisplayChangeTime >= DISPLAY_DURATION_MS) {
    // mode toggle check
    if (displayMode == DisplayMode::Poem) {
      // only switch on last page of poem
      if (isOnLastPageOfPoem()) {
        displayMode = DisplayMode::Events;
        lastDisplayChangeTime = currentTime;
        drawScreen();
      } else {
        // not on last page, advance to next page instead
        nextPage();
        lastDisplayChangeTime = currentTime;
        drawScreen();
      }
    } else {
      // switch back to poems after showing events
      displayMode = DisplayMode::Poem;
      nextPoem();
      lastDisplayChangeTime = currentTime;
      drawScreen();
    }
  }

  // read temperature sensor periodically
  if (currentTime - lastSensorReadTime >= SENSOR_READ_INTERVAL_MS) {
    currentTemp = readTemperature();
    lastSensorReadTime = currentTime;
    drawScreen(); // update display with new temperature
  }

  delay(1000); // loop once per second
}

void drawScreen() {
  display.clearDisplay();

  drawHeader();
  if (displayMode == DisplayMode::Poem) {
    drawPoem();
  } else if (displayMode == DisplayMode::Events) {
    drawEvents();
  }

  display.display();
}

void drawHeader() {
  display.setTextColor(BLACK);
  display.setTextSize(2);

  // get time from RTC
  display.rtcGetRtcData();
  uint8_t hour = display.rtcGetHour();
  uint8_t minute = display.rtcGetMinute();

  // draw time on left
  display.setCursor(20, 15);
  char timeStr[6];
  sprintf(timeStr, "%02d:%02d", hour, minute);
  display.print(timeStr);

  // draw temperature on right
  display.setCursor(SCREEN_WIDTH - 150, 15);
  display.printf("%.1fF", currentTemp);

  // draw separator line
  display.drawLine(0, HEADER_HEIGHT, SCREEN_WIDTH, HEADER_HEIGHT, BLACK);
}

void drawPoem() {
  // initialize state
  char *pageText = nullptr;
  const char *pagePtr = nullptr;
  size_t pageLength = 0;
  char title[50];
  uint16_t pageCount = 0;

  // read page pointer from PROGMEM
  pagePtr =
      reinterpret_cast<const char *>(pgm_read_ptr(&PAGES[currentPageIdx]));

  // get string length from PROGMEM
  pageLength = strlen_P(pagePtr);

  // allocate buffer for page text
  pageText = static_cast<char *>(malloc(pageLength + 1));
  if (pageText == nullptr) {
    Serial.println("ERROR: failed to allocate memory for page text");
    goto cleanup;
  }

  // copy page text from PROGMEM
  strcpy_P(pageText, pagePtr);

  // draw page text
  display.setTextColor(BLACK);
  display.setTextSize(2);

  {
    int y = POETRY_Y;
    int x = POETRY_X;
    // size 2 text pixel dimensions is 12x20
    constexpr int lineHeight = 20;
    constexpr int charWidth = 12;

    // render each character
    // TODO: what if we did this over time instead of all at once?
    for (size_t i{0}; pageText[i] != '\0'; ++i) {
      const char ch = pageText[i];

      if (ch == '\n') {
        x = POETRY_X;
        y += lineHeight;
      } else {
        display.setCursor(x, y);
        display.print(ch);
        x += charWidth;
      }
    }
  }

  // poem title and page info at bottom
  display.setTextSize(2);
  display.setCursor(POETRY_X, SCREEN_HEIGHT - 30);

  // read title from PROGMEM
  strcpy_P(title, (char *)pgm_read_ptr(&POEM_TITLES[currentPoemId]));
  display.print(title);

  // show page number if multi-page (all poems?)
  pageCount = getCurrentPoemPageCount();
  if (pageCount > 1) {
    display.setCursor(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 30);
    display.printf("%d/%d", getCurrentPageNumber(), pageCount);
  }

cleanup:
  if (pageText != nullptr) {
    free(pageText);
  }
}

void drawEvents() {
  display.rtcGetRtcData();
  uint8_t currentDay = display.rtcGetDay();
  uint8_t currentMonth = display.rtcGetMonth();
  uint8_t currentYear = display.rtcGetYear(); // 2-digit year (2025 == 25)
  uint32_t fullYear = 2000 + currentYear;     // add a couple millenia

  Serial.printf("current date: %d/%d/%d (year=%d, fullYear=%d)\n", currentMonth,
                currentDay, currentYear, currentYear, fullYear);
  Serial.printf("total events in data: %d\n", ASTRO_EVENT_COUNT);

  display.setTextColor(BLACK);
  display.setTextSize(2);

  int y = POETRY_Y;
  int eventsShown = 0;
  const int maxEventsToShow = 3;

  // display title
  display.setCursor(POETRY_X, y);
  display.print("upcoming Events:");
  y += 30;

  // events are already sorted chronologically
  Serial.println("scanning events...");
  for (int i{0}; i < ASTRO_EVENT_COUNT && eventsShown < maxEventsToShow; i++) {
    // PROGMEM -> RAM
    AstroEventDate eventDate;
    memcpy_P(&eventDate, &ASTRO_EVENTS[i], sizeof(AstroEventDate));

    // debug first 5 events
    if (i < 5) {
      Serial.printf("- event %d: %d/%d/%d\n", i, eventDate.month, eventDate.day,
                    eventDate.year);
    }

    // check if event is today or in the future
    bool isCurrentOrUpcoming = false;
    if (eventDate.year > fullYear) {
      isCurrentOrUpcoming = true;
    } else if (eventDate.year == fullYear) {
      if (eventDate.month > currentMonth) {
        isCurrentOrUpcoming = true;
      } else if (eventDate.month == currentMonth &&
                 eventDate.day >= currentDay) {
        isCurrentOrUpcoming = true;
      }
    }

    if (isCurrentOrUpcoming) {
      Serial.printf("found upcoming event at index %d: %d/%d/%d\n", i,
                    eventDate.month, eventDate.day, eventDate.year);
      char name[100];
      strcpy_P(name, (char *)pgm_read_ptr(&ASTRO_NAMES[i]));

      // display date and name
      display.setTextSize(2);
      display.setCursor(POETRY_X, y);
      display.printf("%d/%d/%d", eventDate.month, eventDate.day,
                     eventDate.year);
      y += 25;

      display.setTextSize(2);
      display.setCursor(POETRY_X, y);
      display.print(name);
      y += 20;

      // lookup description
      char desc[400]; // TODO: move max length to constexpr
      strcpy_P(desc, (char *)pgm_read_ptr(&ASTRO_DESCS[i]));

      // render description
      display.setTextSize(2);
      int x = POETRY_X;
      int lineHeight = 20; // Line height for size 2

      for (int j{0}; desc[j] != '\0' && y < SCREEN_HEIGHT - 80; j++) {
        if (desc[j] == '\n') {
          x = POETRY_X;
          y += lineHeight;
        } else {
          display.setCursor(x, y);
          display.print(desc[j]);
          x += 12; // 12x20 characters at size 2
        }
      }
      y += 30; // add padding between events

      eventsShown++;
    }

    if (y >= SCREEN_HEIGHT - 80)
      break; // abandon if out of room
  }

  if (eventsShown == 0) {
    Serial.println("no upcoming events found!");
    display.setTextSize(2);
    display.setCursor(POETRY_X, y);
    display.print("no upcoming events");
  } else {
    Serial.printf("displayed %d events\n", eventsShown);
  }
}

void processSerialCommands() {
  // read all available characters
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (serialBuffer.length() > 0) {
        processCommand(serialBuffer);
        serialBuffer = ""; // Clear buffer for next command
      }
    } else {
      serialBuffer += c;
    }
  }
}

void processCommand(String command) {
  command.trim();

  if (command.startsWith("set ")) {
    parseAndSetTime(command);
  } else if (command.startsWith("backlight ")) {
    handleBacklightCommand(command);
  } else if (command.startsWith("poem ")) {
    jumpToPoemCommand(command);
  } else if (command.startsWith("page ")) {
    handlePageCommand(command);
  } else if (command.startsWith("mode ")) {
    switchMode(command);
  } else if (command.startsWith("events")) {
    listUpcomingEvents(command);
  } else if (command == "allevents") {
    listAllEvents();
  } else if (command == "list") {
    listPoems();
  } else if (command == "next") {
    nextPoem();
    drawScreen();
  } else if (command == "prev") {
    prevPoem();
    drawScreen();
  } else if (command.length() > 0) {
    // TODO: move list of commands to constant
    Serial.printf("unknown command: '%s'\n", command.c_str());
    Serial.println("available commands:");
    Serial.println("  set HH:MM [YYYY-MM-DD]");
    Serial.println("  backlight N (0-63)");
    Serial.println("  list");
    Serial.println("  poem N");
    Serial.println("  next / prev");
    Serial.println("  page next / page prev");
    Serial.println("  events [N]");
    Serial.println("  allevents");
    Serial.println("  mode [poem|events]");
  }
}

void handlePageCommand(String command) {
  command.trim();

  if (command == "page next") {
    nextPage();
    drawScreen();
  } else if (command == "page prev") {
    prevPage();
    drawScreen();
  } else {
    Serial.println("error: Use 'page next' or 'page prev'");
  }
}

void handleBacklightCommand(String command) {
  int spacePos = command.indexOf(' ');
  if (spacePos < 0) {
    Serial.println("error: invalid format. use 'backlight N' where N is 0-63");
    return;
  }

  String levelStr = command.substring(spacePos + 1);
  int level = levelStr.toInt();

  if (level < 0 || level > 63) {
    Serial.println("error: backlight level must be 0-63");
    return;
  }

  backlightLevel = level;
  display.setFrontlight(backlightLevel);
  Serial.printf("backlight set to: %d\n", backlightLevel);
}

void listPoems() {
  Serial.println("\n=== poem list ===");
  Serial.printf("total poems: %d\n", POEM_COUNT);
  Serial.printf("total pages: %d\n", TOTAL_PAGES);
  Serial.printf("current: %d (page %d/%d)\n\n", currentPoemId,
                getCurrentPageNumber(), getCurrentPoemPageCount());

  for (uint16_t i = 0; i < POEM_COUNT; i++) {
    char title[100];
    strcpy_P(title, (char *)pgm_read_ptr(&POEM_TITLES[i]));

    // get page count for this poem
    uint16_t firstPage = pgm_read_word(&POEM_FIRST_PAGE[i]);
    uint16_t nextPage = (i < POEM_COUNT - 1)
                            ? pgm_read_word(&POEM_FIRST_PAGE[i + 1])
                            : TOTAL_PAGES;
    uint16_t pageCount = nextPage - firstPage;

    if (i == currentPoemId) {
      Serial.printf(">>> %d: %s (%d pages)\n", i, title, pageCount);
    } else {
      Serial.printf("    %d: %s (%d pages)\n", i, title, pageCount);
    }
  }
  Serial.println("=================\n");
}

void jumpToPoemCommand(String command) {
  int spacePos = command.indexOf(' ');
  if (spacePos < 0) {
    Serial.println("error: Use 'poem N' where N is the poem index");
    return;
  }

  String indexStr = command.substring(spacePos + 1);
  int index = indexStr.toInt();

  if (index < 0 || index >= POEM_COUNT) {
    Serial.printf("error: Poem index must be 0-%d\n", POEM_COUNT - 1);
    return;
  }

  goToPoem(index);
  displayMode = DisplayMode::Poem;
  drawScreen();

  char title[100];
  strcpy_P(title, (char *)pgm_read_ptr(&POEM_TITLES[currentPoemId]));
  Serial.printf("jumped to poem %d: %s\n", currentPoemId, title);
}

void switchMode(String command) {
  int spacePos = command.indexOf(' ');
  if (spacePos < 0) {
    Serial.println("error: Use 'mode poem' or 'mode events'");
    return;
  }

  String mode = command.substring(spacePos + 1);
  mode.trim();
  mode.toLowerCase();

  if (mode == "poem") {
    displayMode = DisplayMode::Poem;
    drawScreen();
    Serial.println("switched to poem mode");
  } else if (mode == "events") {
    displayMode = DisplayMode::Events;
    drawScreen();
    Serial.println("switched to events mode");
  } else {
    Serial.println("error: Mode must be 'poem' or 'events'");
  }
}

// TODO: combine with drawEvents to reduce code duplication
void listUpcomingEvents(String command) {
  // count parameter is optional, default to 10
  int count = 10;
  int spacePos = command.indexOf(' ');
  if (spacePos > 0) {
    String countStr = command.substring(spacePos + 1);
    int parsedCount = countStr.toInt();
    if (parsedCount > 0 && parsedCount <= 100) {
      count = parsedCount;
    }
  }

  display.rtcGetRtcData();
  uint8_t currentDay = display.rtcGetDay();
  uint8_t currentMonth = display.rtcGetMonth();
  uint8_t currentYear = display.rtcGetYear();
  uint32_t fullYear = 2000 + currentYear;

  Serial.println("\n=== upcoming Events ===");
  Serial.printf("current date: %d/%d/%d\n", currentMonth, currentDay, fullYear);
  Serial.printf("showing next %d events:\n\n", count);

  int eventsShown = 0;

  for (int i{0}; i < ASTRO_EVENT_COUNT && eventsShown < count; i++) {
    // PROGMEM -> RAM
    AstroEventDate eventDate;
    memcpy_P(&eventDate, &ASTRO_EVENTS[i], sizeof(AstroEventDate));

    bool isUpcoming = false;
    if (eventDate.year > fullYear) {
      isUpcoming = true;
    } else if (eventDate.year == fullYear) {
      if (eventDate.month > currentMonth) {
        isUpcoming = true;
      } else if (eventDate.month == currentMonth &&
                 eventDate.day >= currentDay) {
        isUpcoming = true;
      }
    }

    if (isUpcoming) {
      char name[100];
      strcpy_P(name, (char *)pgm_read_ptr(&ASTRO_NAMES[i]));

      Serial.printf("%d. %d/%d/%d - %s\n", eventsShown + 1, eventDate.month,
                    eventDate.day, eventDate.year, name);
      eventsShown++;
    }
  }

  if (eventsShown == 0) {
    Serial.println("no upcoming events found.");
  }

  Serial.println("=======================\n");
}

void listAllEvents() {
  Serial.println("\n=== all Events ===");
  Serial.printf("total events: %d\n\n", ASTRO_EVENT_COUNT);

  for (int i{0}; i < ASTRO_EVENT_COUNT; i++) {
    // PROGMEM -> RAM
    AstroEventDate eventDate;
    memcpy_P(&eventDate, &ASTRO_EVENTS[i], sizeof(AstroEventDate));

    char name[100];
    strcpy_P(name, (char *)pgm_read_ptr(&ASTRO_NAMES[i]));

    Serial.printf("%3d. %d/%02d/%02d - %s\n", i, eventDate.year,
                  eventDate.month, eventDate.day, name);
  }

  Serial.println("==================\n");
}

// TODO: this is buggy, can we call it more often?
void handleTouchInput() {
  // only handle touch in poem mode
  if (displayMode != DisplayMode::Poem) {
    return;
  }

  // left half for previous page
  if (display.touchInArea(0, 0, 300, SCREEN_HEIGHT)) {
    Serial.println("touch detected on left side - previous page");
    prevPage();
    drawScreen();
    lastDisplayChangeTime = millis(); // reset timer
    delay(200);                       // TODO: remove?
  }
  // right half for next page
  else if (display.touchInArea(300, 0, 300, SCREEN_HEIGHT)) {
    Serial.println("touch detected on right side - next page");
    nextPage();
    drawScreen();
    lastDisplayChangeTime = millis(); // reset timer
    delay(200);                       // TODO: remove?
  }
}

// read temperature and convert to fahrenheit
float readTemperature() {
  float tempC = display.bme688.readTemperature() + BME688_TEMP_OFFSET;
  float tempF = (tempC * 9.0 / 5.0) + 32.0; // magic formula
  Serial.printf("temperature: %.1fF (%.1fC)\n", tempF, tempC);
  return tempF;
}

void parseAndSetTime(String input) {
  // expected formats: "set HH:MM" or "set HH:MM YYYY-MM-DD"
  input.trim();

  int colonPos = input.indexOf(':');
  if (colonPos < 0) {
    Serial.println(
        "error: invalid format. use 'set HH:MM' or 'set HH:MM YYYY-MM-DD'");
    return;
  }

  String hourStr = input.substring(4, colonPos); // skip "set "
  int spaceAfterTime = input.indexOf(' ', colonPos);
  String minStr;
  if (spaceAfterTime > 0) {
    minStr = input.substring(colonPos + 1, spaceAfterTime);
  } else {
    minStr = input.substring(colonPos + 1);
  }

  int hour = hourStr.toInt();
  int minute = minStr.toInt();

  if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
    Serial.println("error: Invalid time values");
    return;
  }

  display.rtcSetTime(hour, minute, 0);

  // check for date
  uint8_t weekday, day, month, year;
  bool dateProvided = false;

  if (spaceAfterTime > 0) {
    // Parse date: YYYY-MM-DD
    String dateStr = input.substring(spaceAfterTime + 1);
    dateStr.trim();

    int dash1 = dateStr.indexOf('-');
    int dash2 = dateStr.indexOf('-', dash1 + 1);

    if (dash1 > 0 && dash2 > dash1) {
      int fullYear = dateStr.substring(0, dash1).toInt();
      month = dateStr.substring(dash1 + 1, dash2).toInt();
      day = dateStr.substring(dash2 + 1).toInt();
      year = fullYear - 2000; // Convert to 2-digit year

      // simple weekday calculation (Zeller's congruence simplified)
      // TODO: we should just prompt the user for this over serial instead tbh
      weekday = ((day + (13 * (month + 1)) / 5 + year + year / 4 + 5) % 7);

      if (year >= 0 && year <= 99 && month >= 1 && month <= 12 && day >= 1 &&
          day <= 31) {
        dateProvided = true;
        display.rtcSetDate(weekday, day, month, year);
        Serial.printf("date set to %02d/%02d/%04d\n", month, day, fullYear);
      } else {
        Serial.println("error: Invalid date values");
        return;
      }
    } else {
      Serial.println("error: invalid date format. use YYYY-MM-DD");
      return;
    }
  }

  // set default if needed
  if (!dateProvided) {
    display.rtcGetRtcData();
    year = display.rtcGetYear();

    if (year == 0 || year > 99) {
      weekday = 2; // tuesday
      day = 17;
      month = 12;
      year = 25; // 2025
      display.rtcSetDate(weekday, day, month, year);
      Serial.println("date was not set, defaulting to Tue Dec 17, 2025");
    }
  }

  Serial.printf("time set to %02d:%02d\n", hour, minute);
}
