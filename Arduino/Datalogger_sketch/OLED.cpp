/*
#include "OLED.h"

OledDisplay::OledDisplay():
display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1){}

void OledDisplay::begin(){
    if (!display.begin(SSD1306_SWITCHAPVCC, 0x3C)){
        serial.println("Skærm virker ikke");
        for(;;);
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
}
void OledDisplay::showData(const char* date, const char* time, float temp1, float hum1, float temp2, float hum2)
{
    display.clearDisplay();
    
    // TITEL er fjernet, da der ikke er plads på OLED displayet til al information.
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("Datalogger");

    display.setTextSize(1);
    display.setCursor(0,35);
    display.print("dato:");
    display.print(dt.day);
    display.print("/");
    display.print(dt.month)
    display.print("-");
    display.print(dt.year);

    diasply.print("\nTid:");
    display.print(dt.hour);
    display.print(":");
    display.print(dt.minute);
    display.print(":");
    display.print(dt.second);

    display.print("\nTemp. inde");
    display.print(temp1, 1);
    display.print(" C");

    display.println("\nFugt inde");
    display.print(hum1, 1);
    display.print("%");


    display.print("\nTemp. ude");
    display.print(temp2, 1);
    display.print(" C");

    display.println("\nFugt ude");
    display.print(hum2, 1);
    display.print("%");

    display.display();
}
*/