#include "TempSensor1.h"
#include "TempSensor2.h"
#include "SD_log.h"
#include "RTC.h"

// Opret instanser
TempSensor1 sensor1(7);
TempSensor2 sensor2(6);
SD_log sdlog(53, "HiveLog1.txt");
RTC clock1;

void setup()
{
    Serial.begin(9600);
    delay(3000);

    // Start SD og RTC
    sdlog.begin();
    clock1.begin();
}

void loop()
{
    float temp1 = 0;
    float hum1  = 0;
    float temp2 = 0;
    float hum2  = 0;

    // Fejlsikring: tjek kun temperaturer
    while (true)
    {
        // Læs sensorer (brug eksisterende variabler)
        temp1 = sensor1.readTemperature();
        hum1  = sensor1.readHumidity();

        temp2 = sensor2.readTemperature();
        hum2  = sensor2.readHumidity();

        Serial.print("Temp1: "); Serial.print(temp1);
        Serial.print(" | Temp2: "); Serial.println(temp2);

        // Bryd loopet hvis begge temperaturer er OK
        if (temp1 > -40 && temp2 > -40)
        {
            break;
        }

        Serial.println("Fejl i temperaturmåling, prøver igen...");
        delay(2000);
    }

    // Udskriv til Serial
    Serial.print("Sensor 1 - Temperatur: ");
    Serial.print(temp1, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(hum1, 1);
    Serial.println("%");

    Serial.print("Sensor 2 - Temperatur: ");
    Serial.print(temp2, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(hum2, 1);
    Serial.println("%");

    // Timestamp
    String timestamp = clock1.getTimestamp();

    // Log til SD
    sdlog.log(timestamp, temp1, hum1, temp2, hum2);

    Serial.print("Tidspunkt: ");
    Serial.println(timestamp);

    delay(2000); // 10 min
}
