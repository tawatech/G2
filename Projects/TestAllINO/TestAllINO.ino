#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_RA8875.h>

#include "G2bAdaFruitRA8875_800x480.h"
#include "TestAllGen.h"

TestAllGen screenClass;
Adafruit_RA8875 AdafruitTFT=Adafruit_RA8875(RA8875_CS, RA8875_RESET);
G2bAdaFruitRA8875_800x480 LCD= G2bAdaFruitRA8875_800x480(&AdafruitTFT);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:  
  LCD.initBridge();
  screenClass.initTFT(&LCD,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  screenClass.displayScan();
  delay(10);
}
