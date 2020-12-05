/* =====================================================================
   __  __      _____  ______  _   _  _______   _____   ____   _____
   \ \ \ \    / ____||  ____|| \ | ||__   __| / ____| / __ \ |  __ \
  __ \ \ \ \  | (___  | |__   |  \| |   | |   | (___  | |  | || |__) |
  \ \ \ \ \_\  \___ \ |  __|  |     |   | |    \___ \ | |  | ||  _  /
  \ \ \ \     ____) || |____ | |\  |   | |    ____) || |__| || | \ \
   \_\ \_\   |_____/ |______||_| \_|   |_|   |_____/  \____/ |_|  \_\

  Project      : Core Board WROOM-32U - SPIFFS Log
  Description  : Log data to internal flash SPIFFS partition
  Author       : SENTSOR
  Note         :

===================================================================== */

#define DEBUG_OUT(msg) Serial.print(msg)
#define onboardLed 2
#define ssPin 5
#define ADC0 36
#define ADC1 39
#define ADC2 34
#define ADC3 35
//Set sampling interval, unit in milliseconds unsigned long
#define SAMPLING_INTERVAL 1000UL

#include <SPIFFS.h>
#include <RTClib.h>

float voltage[4];
String data, filename;

File file;
RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200, SERIAL_8N1);

  pinMode(onboardLed, OUTPUT);
  pinMode(ADC0, INPUT);
  pinMode(ADC1, INPUT);
  pinMode(ADC2, INPUT);
  pinMode(ADC3, INPUT);

  if (!rtc.begin()) {
    DEBUG_OUT(F("DEBUG >> RTC not initialized\n"));
    DEBUG_OUT(F("DEBUG >> Halt program\n"));
    while (1) {
      //Do nothing if RTC failed to initialized
      heartbeat(3);
      delay(500);
    }
  }

  if (!SPIFFS.begin()) {
    DEBUG_OUT(F("DEBUG >> SPIFFS not initialized\n"));
    DEBUG_OUT(F("DEBUG >> Halt program\n"));
    while (1) {
      //Do nothing if SPIFFS failed to initialized
      heartbeat(3);
      delay(500);
    }
  }
}

void loop() {
  static uint32_t lastMillis;

  //Execute sampling and datalogging every SAMPLING_INTERVAL milliseconds
  if (millis() - lastMillis >= SAMPLING_INTERVAL) {
    lastMillis = millis();

    //Read data
    DateTime time = rtc.now();
    voltage[0] = (float)analogRead(ADC0) * 3.3F / 4096.0F;
    voltage[1] = (float)analogRead(ADC1) * 3.3F / 4096.0F;
    voltage[2] = (float)analogRead(ADC2) * 3.3F / 4096.0F;
    voltage[3] = (float)analogRead(ADC3) * 3.3F / 4096.0F;

    //Format the data as comma-separated values (CSV)
    data = String(time.timestamp(DateTime::TIMESTAMP_DATE)) + " " + String(time.timestamp(DateTime::TIMESTAMP_TIME)) + ",";
    const uint8_t n = 2;
    data += String(voltage[0], n) + "," + String(voltage[1], n) + "," + String(voltage[2], n) + "," + String(voltage[3], n);

    //Format variable filename with absolute path (starting with forward slash)
    //Ex: Log data to new file everyday, filename is "/YYYYMMDDdatalog.csv"
    filename = "/" + String(time.year());
    if (time.month() < 10) filename += "0"; filename += String(time.month());
    if (time.day() < 10) filename += "0"; filename += String(time.day()) + "datalog.csv";

    //Write data to SPIFFS
    file = SPIFFS.open(filename.c_str(), FILE_WRITE);
    if (file) {
      file.println(data);
      file.close();
      SPIFFS.end();

      DEBUG_OUT(F("DEBUG >> Writing data OK\n"));
      heartbeat(1);
    }
    else {
      DEBUG_OUT(F("DEBUG >> Writing data FAILED\n"));
      heartbeat(3);
    }
  }
}

void heartbeat(uint8_t n) {
  //Blink indicator LED for n-times
  while (n > 0) {
    digitalWrite(onboardLed, HIGH);
    delay(10);
    digitalWrite(onboardLed, LOW);
    delay(100);
    n--;
  }
}

// End of File [SENTSOR]
