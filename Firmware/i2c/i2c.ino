// SPDX-FileCopyrightText: 2023 Carter Nelson for Adafruit Industries
//
// SPDX-License-Identifier: MIT
// --------------------------------------
// i2c_scanner
//
// Modified from https://playground.arduino.cc/Main/I2cScanner/
// --------------------------------------

#include <Wire.h>

// Set I2C bus to use: Wire, Wire1, etc.
#define WIRE Wire

void setup() {
  WIRE.begin();

  Serial1.begin(9600);
  Serial1.println("\nI2C Scanner");

  pinMode(4, OUTPUT);
}


void loop() {
  byte error, address;
  int nDevices;

  Serial1.println("Scanning...");
  nDevices = 0;
  digitalWrite(4, HIGH);
  for(address = 1; address < 255; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    WIRE.beginTransmission(address);
    error = WIRE.endTransmission();

    if (error == 0)
    {
      Serial1.print("I2C device found at address 0x");
      if (address<16)
        Serial1.print("0");
      Serial1.print(address,HEX);
      Serial1.println("  !");

      nDevices++;
    }
    else if (error==4)
    {
      Serial1.print("Unknown error at address 0x");
      if (address<16)
        Serial1.print("0");
      Serial1.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial1.println("No I2C devices found\n");
  else
    Serial1.println("done\n");
  delay(5000);           // wait 5 seconds for next scan
}
