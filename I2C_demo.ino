/*============================================================
                          I2C DEMO
==============================================================
Description:
  This program demonstrates I2C protocol signaling.
  A logic analyzer connected to SDA and SCL captures and
  displays the transmitted data (START, address, R/W, ACK/NACK,
  data bytes, STOP).

  No external pull-up resistors needed — the ESP32's internal
  weak pull-ups (enabled by Wire.begin()) are sufficient for
  this low-speed demo.

Programmer:
  Felicity M. De Asis
  Shanna Dale R. Dela Torre
  Rhile L. Galpo

Date:
  10 Nov 2026
-------------------------------------------------------------*/
#include <Wire.h>

// GPIOs
const uint8_t SDA_PIN = 21;
const uint8_t SCL_PIN = 22;
const uint8_t SLAVE_ADDR = 0x27;

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);    // enables internal pull-ups
  Wire.setClock(100'000);          // 100kHz standard mode      
}

void loop() {
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.print("Hi");
  Wire.endTransmission();   
}