#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledDisplay {
public:
    OledDisplay();

    void begin();

    void showData(const char* date,
                  const char* time,
                  float temp1,
                  float hum1,
                  float temp2,
                  float hum2);

private:
    static const int SCREEN_WIDTH  = 128;
    static const int SCREEN_HEIGHT = 64;

    Adafruit_SSD1306 display;
};

#endif
