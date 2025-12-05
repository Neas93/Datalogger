#include "SD_log.h"

SD_log::SD_log(int cs, const char* name)
{
    csPin = cs;
    fileName = name;
}

void SD_log::begin()
{
    Serial.print("Indlæser SD... ");
    if (!SD.begin(csPin)) {
        Serial.println("FEJL!");
        return;
    }
    Serial.println("OK");

    File file = SD.open(fileName, FILE_WRITE);
    if (file) {
        file.println("Starter logføring:");
        file.println("Format: Timestamp | S1 Temp | S1 Hum | S2 Temp | S2 Hum");
        file.close();
    }
}

void SD_log::log(String timestamp, float temp1, float hum1, float temp2, float hum2)
{
    File file = SD.open(fileName, FILE_WRITE);
    if (!file) {
        Serial.println("Fejl i åbning af logfil!");
        return;
    }

    file.print(timestamp);
    file.print("|S1Temp:"); file.print(temp1, 1);
    file.print("|S1Hum:"); file.print(hum1, 1);
    file.print("%|S2Temp:"); file.print(temp2, 1);
    file.print("|S2Hum:"); file.print(hum2, 1);
    file.println("%");

    file.close();
    Serial.println("Data indskrevet på SD");
}
