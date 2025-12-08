#pragma once
#include <Arduino.h>
#include <dhtnew.h>
// deklarering af klassen til temp og fugt sensorer
class TempSensor1
{
public:
    DHTNEW sensor;

    TempSensor1(int pin);

    float readTemperature();
    float readHumidity();
};
