#include "SD_log.h"

SD_log::SD_log(int cs, const char* name)
{
    csPin = cs;
    fileName = name;
}
//Start af SD-modul
void SD_log::begin()
{
    Serial.print("Indlæser SD... ");
    if (!SD.begin(csPin)) {
        Serial.println("FEJL!");
        return;
    }
    Serial.println("OK");
// Indskrivning på SD + første indskrivning
    File file = SD.open(fileName, FILE_WRITE);
    if (file) {
        file.println("Starter logføring:");
        file.println("Ved måling skubbes måling 2 sek");
        file.println("Format: Timestamp | S1 Temp | S1 Hum | S2 Temp | S2 Hum");
        file.close();
    }
}

void SD_log::log(String timestamp, float temp1, float hum1, float temp2, float hum2, String dayOrNight)
{
    File file = SD.open(fileName, FILE_WRITE);
    if (!file) {
        Serial.println("Fejl i åbning af logfil!");
        return;
    }
//opsætning og indskrivning af data i fil samt færdigmelding
    file.print(timestamp);
    file.print("|S1Temp:"); file.print(temp1, 1);
    file.print("|S1Hum:"); file.print(hum1, 1);
    file.print("%|S2Temp:"); file.print(temp2, 1);
    file.print("|S2Hum:"); file.print(hum2, 1); file.print("%");
    file.print(dayOrNight);

    file.close();
    Serial.println("Data indskrevet på SD");
}
