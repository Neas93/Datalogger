#pragma once
#include <Arduino.h>

class LysSensor
{
public:
    int pin;

    LysSensor(int p);

    int readLight();

    String getDayOrNight();
};

