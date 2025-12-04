#include "TempSensor2.h"

TempSensor::TempSensor(int pin) : sensor(pin) { }


float TempSensor::readTemperature() 
{
    sensor.read(); 
    return sensor.getTemperature();
}


float TempSensor::readHumidity()
{
    sensor.read();
    return sensor.getHumidity();
}
