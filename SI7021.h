/*
  Copyright 2014 Marcus Sorensen <marcus@electron14.com>

This program is licensed under the GNU GPL v2
*/
#ifndef si7021_h
#define si7021_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#ifdef __AVR_ATtiny85__
 #include "TinyWireM.h"
 #define Wire TinyWireM
#else
 #include <Wire.h>
#endif

typedef struct si7021_env {
    int celsiusHundredths;
    int fahrenheitHundredths;
    unsigned int humidityBasisPoints;
} si7021_env;

class SI7021
{
  public:
    SI7021();
#ifdef ARDUINO_ARCH_ESP8266
    bool begin(int sda, int scl);
#else
	bool begin();
#endif
    bool sensorExists();
    int getFahrenheitHundredths();
    int getCelsiusHundredths();
    unsigned int getHumidityPercent();
    unsigned int getHumidityBasisPoints();
    struct si7021_env getHumidityAndTemperature();
    int getSerialBytes(byte * buf);
    int getDeviceId();
    void setHeater(bool on);
  private:
    void _command(byte * cmd, byte cmdsize, byte * buf, byte bufsize );
    void _writeReg(byte * reg, int reglen);
    int _readReg(byte * reg, int reglen);
    int _getCelsiusPostHumidity();
};

#endif

