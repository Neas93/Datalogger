#pragma once
#include <Arduino.h>
#include <SD.h>

class SD_log
{
public:
    int csPin;
    const char* fileName;

    SD_log(int cs, const char* name);

    void begin();
    void log(String timestamp, float temp1, float hum1, float temp2, float hum2, String dayOrNight);
};
