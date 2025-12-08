#include "TempSensor.h"
#include "SD_log.h"
#include "RTC.h"
#include "SensorData.h"
#include "Lys_Sensor.h"
#include "Mic.h"
#include "OLED.h"

// Komponenter & pins
TempSensor sensor1(7);
TempSensor sensor2(6);
LysSensor ldr(A0);
MikrofonSensor mic(A1);
SD_log sdlog(53, "HiveLog1.txt");
RTC clock1; //dedikerede pins til RTC digital 20 & 21
OledDisplay oled;

void setup()
{
    Serial.begin(9600);
    delay(3000);

// Start SD og RTC
    sdlog.begin();
    clock1.begin();
    oled.begin();
}

void loop()
{
    SensorData d;

    // Loop for at undgå ugyldige data | ingen log ved fejlmåling
    while (true)
    {
        // Aflæsning af sensorer
        d.temp1 = sensor1.readTemperature();
        d.hum1  = sensor1.readHumidity();

        d.temp2 = sensor2.readTemperature();
        d.hum2  = sensor2.readHumidity();

        d.light = ldr.readLight();

        // Stop loopet hvis data er gyldig
        if (d.temp1 > -40 && d.temp2 > -40)
        {
            break;
        }

        Serial.println("Fejl i måling, prøver igen");
        delay(2000); // 2 sek interval mellem fejlmålinger
    }

    // Udskriv til Serial / PC
    Serial.print("Sensor 1 - Temperatur: ");
    Serial.print(d.temp1, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(d.hum1, 1);
    Serial.println("%");

    Serial.print("Sensor 2 - Temperatur: ");
    Serial.print(d.temp2, 1);
    Serial.print(" °C, Fugtighed: ");
    Serial.print(d.hum2, 1);
    Serial.println("%");

    int amplitude = mic.readAmplitude(2000); // 2000 samples er nok
    String soundLevel = mic.classifyActivity(amplitude);

    Serial.print("Aktivitet: ");
    Serial.print(soundLevel);

    String dayOrNight = ldr.getDayOrNight();
    Serial.println(" | "+dayOrNight);

    String timestamp = clock1.getTimestamp();

    // Logging til SD
    sdlog.log(timestamp, d.temp1, d.hum1, d.temp2, d.hum2,soundLevel, dayOrNight);

    Serial.print("Tidspunkt: ");
    Serial.println(timestamp);

    String dateStr = timestamp.substring(0, 10);
    String timeStr = timestamp.substring(11, 19);

    oled.showData(
      dateStr.c_str(),
      timeStr.c_str(),
      d.temp1,
      d.hum1,
      d.temp2,
      d.hum2, soundLevel);

    delay(3000); // 10 min interval mellem korrekte målinger
}
