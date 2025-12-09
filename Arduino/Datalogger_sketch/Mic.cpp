#include "Mic.h"

// Konstruktor: gem hvilken pin mikrofonens analogsignal er på
MikrofonSensor::MikrofonSensor(int p)
{
    pin = p;  // gem pin-nummeret (fx A0)
}

// readAmplitude(): læs mikrofon og mål hvor høj lyden er
int MikrofonSensor::readAmplitude(int samples)
{
    int mn = 1024;  // mindste værdi - start høj
    int mx = 0;     // største værdi - start lav

    // Tag flere målinger og find min + max
    for (int i = 0; i < samples; i++)
    {
        int val = analogRead(pin);  // læs analogsignal fra mikrofon
        if (val < mn) mn = val;      // gem hvis det er mindre end tidligere min
        if (val > mx) mx = val;      // gem hvis det er større end tidligere max
    }

    return mx - mn;  // returner forskel (amplitude = hvor høj lyden er)
}

// classifyActivity(): bestem hvilken type lyd det er ud fra amplitude
String MikrofonSensor::classifyActivity(int amplitude)
{
    // Sammenlign amplitude med trin og returner tekst
    if (amplitude < 10) 
        return "Lav_aktivitet";           // meget stille
    else if (amplitude < 40) 
        return "Normal_aktivitet";       // normal lyd
    else 
        return "Høj_aktivitet";         // meget lyd
}
