#include "SD_log.h"

SD_log::SD_log(int cs, const char* name)
{
    csPin = cs;
    fileName = name;
    lastWriteSuccess = true; // default til OK
}

void SD_log::begin()
{
    Serial.print("Indlæser SD... ");
    if (!SD.begin(csPin)) {
        Serial.println("FEJL!");
        lastWriteSuccess = false;
        return;
    }
    Serial.println("OK");

    File file = SD.open(fileName, FILE_WRITE);
    if (file) {
        file.println("Starter logføring:");
        file.println("Ved måling skubbes måling 2 sek");
        file.println("Format: Tid | S1 Temp | S1 Fugt | S2 Temp | S2 Fugt");
        file.close();
    } else {
        Serial.println("FEJL: Kan ikke åbne logfil ved start");
        lastWriteSuccess = false;
    }
}

void SD_log::log(String timestamp, float temp1, float hum1, float temp2, float hum2, String soundLevel, String dayOrNight, int light)
{
    File file = SD.open(fileName, FILE_WRITE);
    if (!file) 
    {
        Serial.println("Fejl i åbning af logfil!");
        lastWriteSuccess = false;
        return;
    }

    file.print(timestamp);
    file.print("|S1Temp:"); file.print(temp1, 1);
    file.print("|S1Fugt:"); file.print(hum1, 1);
    file.print("%|S2Temp:"); file.print(temp2, 1);
    file.print("|S2Fugt:"); file.print(hum2, 1);
    file.print("%|"); file.print(soundLevel+"|"); file.print(dayOrNight+"|");
    file.print("Lys:"); file.print(light); file.print("\n");

    file.close();
    Serial.println("Data indskrevet på SD");

    lastWriteSuccess = true;
}
