#include "RTC.h"

RTC::RTC()
{
    // Constructor - står tom da der ikke er nogle parametre
}
//opstart af RTC-modul
void RTC::begin()
{
    Wire.begin();
    clock.begin();
    Serial.println("RTC klar");
    //clock.setDateTime(2025, 12, 9, 14, 17, 20);
}

String RTC::getTimestamp()
{
    clock.forceConversion();       // Opdaterer intern temperatur/time | sikring af præcision i måling
    dt = clock.getDateTime();      // Hent dato/tid

    char buffer[25]; // Reserverer 25 bytes til den string der indeholder timestamp
    snprintf(buffer, sizeof(buffer),
             "%04d-%02d-%02d %02d:%02d:%02d",
             dt.year, dt.month, dt.day,
             dt.hour, dt.minute, dt.second);

    return String(buffer);
}

float RTC::getTemperature()
{
    clock.forceConversion();       // Opdatering af tid og temp internt på modul | sikring af præcision i måling
    return clock.readTemperature();
}
