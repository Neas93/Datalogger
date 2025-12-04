#include "TempSensor1.h"

// Konstruktør
TempSensor1::TempSensor1(int pin) : sensor(pin) { }

float TempSensor1::readTemperature() 
{
    sensor.read();
    return sensor.getTemperature();
}

float TempSensor1::readHumidity()
{
    sensor.read();
    return sensor.getHumidity();
}
