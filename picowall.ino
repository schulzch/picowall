#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "cat.h"
#include "visus.h"

// Pins.
#define LED_BUILTIN 1
#define BUTTON_PIN 12

// I2C (SDA, SCL pins).
#define SDA1 17
#define SCL1 16
#define SDA2 21
#define SCL2 22
TwoWire wireA = TwoWire(1);
TwoWire wireB = TwoWire(0);

// SSD1306 display connected to I2C.
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_GAP 16 // Estimated
Adafruit_SSD1306 displayA(SCREEN_WIDTH, SCREEN_HEIGHT, &wireA, OLED_RESET);
Adafruit_SSD1306 displayB(SCREEN_WIDTH, SCREEN_HEIGHT, &wireB, OLED_RESET);

struct Talk
{
  const char *strA;
  const char *strB;
};

#define TURRET_TALK_SIZE 10
const Talk TURRET_TALK[]{
    {"hey, hey, hey,", "put me down"},
    {"who", "are you?"},
    {"please", "put me down"},
    {"I don't", "hate you"},
    {"sleep mode", "activated"},
    {"hibernating", "good night"},
    {"resting", "naptime"},
    {"are you", "still there?"},
    {"self test", "error unknown error "},
    {"malfunctioning", "malfunctioning"}};

uint8_t appState = 0;
uint8_t talkIndex = 0;

struct Cat
{
  int16_t x;
  int16_t y;
  int8_t frame;
};
Cat cat;

void panic()
{
  while (true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void IRAM_ATTR isr()
{
  if (appState == 0)
  {
    appState = 1;
  }
  else if (appState == 2)
  {
    appState = 3;
  }
}

void setup()
{
  // Activate LED during setup.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // Configure button with internal pullup.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(BUTTON_PIN, isr, FALLING);

  // Setup IC2.
  wireA.begin(SDA1, SCL1, 400000UL);
  wireB.begin(SDA2, SCL2, 400000UL);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!displayA.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    panic();
  }
  if (!displayB.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    panic();
  }

  // Reset screens.
  displayA.clearDisplay();
  displayB.clearDisplay();
  displayA.display();
  displayB.display();

  // Disable LED with some delay for visiblity when setup is complete.
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  if (appState == 0)
  {
    talkIndex = (talkIndex + 1) % TURRET_TALK_SIZE;
    drawText(TURRET_TALK[talkIndex].strA, TURRET_TALK[talkIndex].strB);
    delay(4000);
    // Test again (skip if interrupt occured).
    if (appState == 0)
    {
      clearDisplays();
      delay(3000);
    }
  }
  else if (appState == 1)
  {
    // Display bootup logo.
    drawLogo(displayA);
    drawLogo(displayB);
    delay(2000);
    // Switch state.
    cat.x = (displayA.width() - 16) / 2;
    cat.y = (displayA.height() - 16) / 2;
    appState = 2;
  }
  else if (appState == 2)
  {
    displayA.clearDisplay();
    displayB.clearDisplay();
    if (cat.x < SCREEN_WIDTH)
    {
      drawCat(displayA, cat.x, cat.y, cat.frame);
    }
    if (cat.x + CAT_RECTS[cat.frame].aW >= SCREEN_WIDTH + SCREEN_GAP)
    {
      drawCat(displayB, cat.x - SCREEN_WIDTH - SCREEN_GAP, cat.y, cat.frame);
    }
    cat.x = (cat.x + CAT_SPEEDS[cat.frame] * 3) % (SCREEN_WIDTH * 2);
    cat.frame = (cat.frame + 1) % 57;
    displayA.display();
    displayB.display();
    delay(250);
  }
  else if (appState == 3)
  {
    drawText("whooooaa,", "illegal operation");
    delay(3000);
    talkIndex = 7;
    appState = 0;
  }
}

void clearDisplays()
{
  displayA.clearDisplay();
  displayB.clearDisplay();
  displayA.display();
  displayB.display();
}
void drawLogo(Adafruit_SSD1306 &display)
{
  display.clearDisplay();
  display.drawBitmap(
      (display.width() - VISUS_WIDTH) / 2,
      (display.height() - VISUS_HEIGHT) / 2,
      VISUS_PIXELS, VISUS_WIDTH, VISUS_HEIGHT, SSD1306_WHITE);
  display.display();
}

void drawCat(Adafruit_SSD1306 &display, int16_t x, int16_t y, uint16_t index)
{
  const AtlasRect rect = CAT_RECTS[index];
  const uint16_t bytesPerLine = (CAT_WIDTH + 7) / 8;
  display.startWrite();
  for (int16_t yy = 0; yy < rect.aH; yy++)
  {
    for (int16_t xx = 0; xx < rect.aW; xx++)
    {
      /*
      if ((xx & 7) != 0) {
        b <<= 1;
        }       else{
         const uint16_t byteIndex = (rect.aY + yy) * bytePerLine + (rect.aX + xx) / 8;
        b = CAT_PIXELS[byteIndex];
      }
      if ((b & 0x80) != 0) {
          display.writePixel(x + xx, y + yy, SSD1306_WHITE); //TODO: use offset from rect.sX, rect.sY
      }
       */
      const uint16_t byteIndex = (rect.aY + yy) * bytesPerLine + (rect.aX + xx) / 8;
      const uint16_t bitInByteIndex = 7 - (rect.aX + xx) % 8;
      const uint8_t bitMask = (uint8_t)(1 << bitInByteIndex);
      if ((CAT_PIXELS[byteIndex] & bitMask) != 0)
      {
        display.writePixel(x + xx, y + yy, SSD1306_WHITE); // TODO: use offset from rect.sX, rect.sY
      }
    }
  }
  display.endWrite();
}

void drawText(const char *textA, const char *textB)
{
  int16_t x;
  int16_t y;
  uint16_t widthA;
  uint16_t heightA;
  uint16_t widthB;
  uint16_t heightB;

  displayA.clearDisplay();
  displayA.setTextSize(1);
  displayA.setTextColor(SSD1306_WHITE);
  displayA.getTextBounds(textA, 0, 0, &x, &y, &widthA, &heightA);
  displayA.setCursor((SCREEN_WIDTH - widthA) / 2, (SCREEN_HEIGHT - heightA) / 2);
  displayA.print(textA);

  displayB.clearDisplay();
  displayB.setTextSize(1);
  displayB.setTextColor(SSD1306_WHITE);
  displayB.getTextBounds(textB, 0, 0, &x, &y, &widthB, &heightB);
  displayB.setCursor((SCREEN_WIDTH - widthB) / 2, (SCREEN_HEIGHT - heightB) / 2);
  displayB.print(textB);

  displayA.display();
  displayB.display();
}
