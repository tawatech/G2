#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_RA8875.h>

#include "G2BAdaFruitRA8875.h"
#include "TouchCalibrationGen.h"


TouchCalibrationGen screenClass;
Adafruit_RA8875 tft = Adafruit_RA8875((uint8_t)A6, (uint8_t)A4);  //high number for second argument to avoid setting mode of in-use pin
G2bAdaFruitRA8875 LCD=G2bAdaFruitRA8875(&tft,RA8875_800x480);

void setup() {
  LCD.initBridge();
  screenClass.initTFT(&LCD,0);
}

void loop() {
  int RetVal=screenClass.displayScan();
  if (RetVal!=0) //screen has been touched
  {
    uint16_t x,y;
    LCD.touchRead(&x,&y); //generally not required to call functions from LCD class, as screenClass should deal with these; in this case we need raw data for calibration though
    switch (screenClass.PointIndex)
    {
      case 1:
        screenClass.X1=x;
        screenClass.Y1=y;
        break;
      case 2:
        screenClass.X2=x;
        screenClass.Y2=y;
        break;
      case 3:
        screenClass.X3=x;
        screenClass.Y3=y;
        break;
    }
    screenClass.PointIndex++;
  }
  delay(10);  //slows down calls to display scan for better results
}
