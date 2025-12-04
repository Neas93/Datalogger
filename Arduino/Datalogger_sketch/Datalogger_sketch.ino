#include "TempSensor1.h"
#include "TempSensor2.h"

TempSensor sensor(7);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    float temp = sensor.readTemperature();
    float hum  = sensor.readHumidity();

    Serial.print("Temperatur: ");
    Serial.print(temp, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.println(hum, 1);

    delay(1000);
}
