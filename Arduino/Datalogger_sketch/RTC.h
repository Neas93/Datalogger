#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <DS3231.h>

class RTC
{
public:
    DS3231 clock;
    RTCDateTime dt;

    RTC();          
    void begin();   
    String getTimestamp();  
    float getTemperature(); 
};
