#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "OLED.h"



OledDisplay::OledDisplay()
: display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1)
{
}

void OledDisplay::begin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Skærm virker ikke");
        for(;;);
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
}

void OledDisplay::showData(const char* date,
                           const char* time,
                           float temp1,
                           float hum1,
                           float temp2,
                           float hum2,
                           String soundLevel)
{
        display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);

    display.print("Dato:      ");
    display.println(date);

    display.print("Tid:         ");
    display.println(time);

    display.print("Temp. inde:    ");
    display.print(temp1, 1);
    display.println(" C");

    display.print("Fugt inde:     ");
    display.print(hum1, 1);
    display.println(" %");

    display.print("Temp. ude:     ");
    display.print(temp2, 1);
    display.println(" C");

    display.print("Fugt ude:      ");
    display.print(hum2, 1);
    display.println(" %");

    display.println(" ");
    display.print("Lyd: ");
    display.println(soundLevel);

    display.display();
}
