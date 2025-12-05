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
        file.println("Ved fejl i måling skrives NAN");
        file.close();
    }
}

void SD_log::log(float temp1, float hum1, float temp2, float hum2)
{
    File file = SD.open(fileName, FILE_WRITE);

    if (!file) {
        Serial.println("Fejl i åbning af logfil!");
        return;
    }

    file.print("S1 Temp: ");
    file.print(temp1, 1);
    file.print(" C| S1 Hum: ");
    file.print(hum1, 1);
    file.print("% | ");

    file.print("S2 Temp: ");
    file.print(temp2, 1);
    file.print(" C| S2 Hum: ");
    file.print(hum2, 1);
    file.println("%");

    file.close();

    Serial.println("Data indskrevet på SD");
}
