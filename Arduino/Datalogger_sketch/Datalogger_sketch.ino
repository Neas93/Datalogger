#include "TempSensor1.h"
#include "TempSensor2.h"
#include "SD_log.h"

TempSensor1 sensor1(7);
TempSensor2 sensor2(6);
SD_log sdlog(53, "Hive_Log.txt");

void setup()
{
    Serial.begin(9600);
    delay(3000);

    sdlog.begin();
}

void loop()
{
    float temp1 = sensor1.readTemperature();
    float hum1  = sensor1.readHumidity();

    float temp2 = sensor2.readTemperature();
    float hum2  = sensor2.readHumidity();

    if (temp1 > -30)
    {
        Serial.print("Sensor 1 - Temperatur: ");
        Serial.print(temp1, 1);
        Serial.print(" °C, Fugtighed: ");
        Serial.print(hum1, 1);
        Serial.println("%");
    }

    if (temp2 > -30)
    {
        Serial.print("Sensor 2 - Temperatur: ");
        Serial.print(temp2, 1);
        Serial.print(" °C, Fugtighed: ");
        Serial.print(hum2, 1);
        Serial.println("%");
    }
    if (temp1 > -30 && temp2 > -30 )
    {
        sdlog.log(temp1, hum1, temp2, hum2);
    }

    else if (temp1 < -30 && temp2 > -30)
    {
        sdlog.log(NAN, NAN, temp2, hum2);
    }

    else if (temp1 > -30 && temp2 < -30)
    {
        sdlog.log(temp1, hum1, NAN, NAN);  
    }
    delay(5000); // 10 minutter
}
