#pragma once
#include <Arduino.h>
#include <dhtnew.h>

class TempSensor1
{
public:
    DHTNEW sensor;

    TempSensor1(int pin);

    float readTemperature();
    float readHumidity();
};
