#pragma once
#include <Arduino.h>
#include <dhtnew.h>
// deklarering af klassen til temp og fugt sensorer
class TempSensor
{
public:
    DHTNEW sensor;

    TempSensor(int pin);

    float readTemperature();
    float readHumidity();
};
