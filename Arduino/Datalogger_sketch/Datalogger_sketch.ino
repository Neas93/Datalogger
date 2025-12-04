#include "TempSensor1.h"
#include "TempSensor2.h"

// Opret objekter med unikke navne
TempSensor1 sensor1(7);
TempSensor2 sensor2(6);

void setup()
{
    Serial.begin(9600);
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
    Serial.print("Sensor 1 - Temperatur: ");
    Serial.print(temp1, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.println(hum1, 1);

    // Print Sensor 2
    Serial.print("Sensor 2 - Temperatur: ");
    Serial.print(temp2, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.println(hum2, 1);

    delay(1000); // 1 sekund pause
}
