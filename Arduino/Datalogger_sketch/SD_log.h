#pragma once
#include <Arduino.h>
#include <SD.h>

class SD_log
{
public:
    int csPin;
    const char* fileName;

    bool lastWriteSuccess; // Status for sidste logforsøg | opdateres hver gang der tjekkes for om logfilen er åben eller ej

    SD_log(int cs, const char* name);

    void begin();
    void log(String timestamp, float temp1, float hum1, float temp2, float hum2, String soundLevel, String dayOrNight, int light);

    bool isLastWriteOK() { return lastWriteSuccess; } // check på sidste SD-skrivning
};
