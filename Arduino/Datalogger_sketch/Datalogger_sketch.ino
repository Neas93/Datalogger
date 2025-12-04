#include "TempSensor1.h"
#include "TempSensor2.h"


TempSensor1 sensor1(7);
TempSensor2 sensor2(6);

void setup()
{
    Serial.begin(9600);
    delay(3000);
}

void loop()
{
    // Læs værdier fra Sensor 1
    float temp1 = sensor1.readTemperature();
    float hum1  = sensor1.readHumidity();

    // Læs værdier fra Sensor 2
    float temp2 = sensor2.readTemperature();
    float hum2  = sensor2.readHumidity();

    // Print Sensor 1
    if (temp1 > -30)
    {
    Serial.print("Sensor 1 - Temperatur: ");
    Serial.print(temp1, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(hum1, 1);
    Serial.println("%");
    }
    // Print Sensor 2
    if (temp2 > -30)
    {
    Serial.print("Sensor 2 - Temperatur: ");
    Serial.print(temp2, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(hum2, 1);
    Serial.println("%");
    }

    delay(2000); 
}
