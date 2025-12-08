#pragma once
#include <Arduino.h>

class MikrofonSensor
{
public:
    int pin;

    MikrofonSensor(int p);

    // Måler amplitude (mx–mn) over et antal samples
    int readAmplitude(int samples = 10000);

    // Returnerer tekst baseret på hvor meget aktivitet der er
    String classifyActivity(int amplitude);
};