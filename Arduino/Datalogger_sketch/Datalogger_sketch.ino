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
    // Læs sensorer
    float temp1 = sensor1.readTemperature();
    float hum1  = sensor1.readHumidity();

    float temp2 = sensor2.readTemperature();
    float hum2  = sensor2.readHumidity();

    // Udskriv til Serial
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

    // Log til SD med timestamp
    String timestamp = clock1.getTimestamp();

    if (temp1 > -30 && temp2 > -30)
{
    sdlog.log(timestamp, temp1, hum1, temp2, hum2);
}
else if (temp1 < -30 && temp2 > -30)
{
    sdlog.log(timestamp, NAN, NAN, temp2, hum2);
}
else if (temp1 > -30 && temp2 < -30)
{
    sdlog.log(timestamp, temp1, hum1, NAN, NAN);  
}

    // Tilføj timestamp i Serial (valgfrit)
    Serial.print("Tidspunkt: ");
    Serial.println(timestamp);

    delay(5000); // 5 sekunder; ændr til 10 min = 600000 ms
}
