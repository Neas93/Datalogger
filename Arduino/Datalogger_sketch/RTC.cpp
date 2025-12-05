#include "RTC.h"

RTC::RTC()
{
    // Constructor - intet nødvendigt
}

void RTC::begin()
{
    Wire.begin();
    clock.begin();
    Serial.println("RTC klar");
}

String RTC::getTimestamp()
{
    clock.forceConversion();       // Opdaterer temperatur/time internt
    dt = clock.getDateTime();      // Hent dato/tid

    char buffer[25];
    snprintf(buffer, sizeof(buffer),
             "%04d-%02d-%02d %02d:%02d:%02d",
             dt.year, dt.month, dt.day,
             dt.hour, dt.minute, dt.second);

    return String(buffer);
}

float RTC::getTemperature()
{
    clock.forceConversion();       // Opdatering
    return clock.readTemperature();
}
