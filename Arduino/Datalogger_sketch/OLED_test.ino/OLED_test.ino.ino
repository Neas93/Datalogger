#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 failed");
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  // display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setTextSize(2);

  display.setCursor(0, 0);
  display.println("Datalogger");
  
  display.setTextSize(1);
  display.println("\nDato:      05/12-2025");
  display.println("Tid:         10:37:XX");
  display.println("Temperatur:    25.0 C");
  display.println("Fugtighed:        36%");
  display.println("Lyd:            65 dB");
  
  display.display();
}

void loop() {}
