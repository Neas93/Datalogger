#include "TempSensor2.h"

// Konstruktør
TempSensor2::TempSensor2(int pin) : sensor(pin) { }

float TempSensor2::readTemperature() 
{
    sensor.read();
    return sensor.getTemperature();
}

float TempSensor2::readHumidity()
{
    sensor.read();
    return sensor.getHumidity();
}
