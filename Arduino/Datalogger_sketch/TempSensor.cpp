#include "TempSensor.h"

//construcor til sensorerne, klargøring til hvilken digital pin den monteres | deklareres i ino
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
