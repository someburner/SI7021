#include <Wire.h>
#include <SI7021.h>


SI7021 sensor;
int led1 = 3;
int led2 = 4;

void setup() {
  Serial.begin(9600);
  sensor.begin();

  // this driver should work for SI7020 and SI7021, this returns 20 or 21
  int deviceid = sensor.getDeviceId();
  Serial.print("Sensor is SI70");
  Serial.println(deviceid);
}


void loop() {
  // temperature is an integer in hundredths
  float temperature = sensor.getCelsiusHundredths() / 100.0;

  // humidity is an integer representing percent
  int humidity = sensor.getHumidityPercent();

  Serial.print ("Temperature = ");
  Serial.print (temperature, 2);
  Serial.print (", Humidity = ");
  Serial.print (humidity);
  Serial.println ("%");
}
