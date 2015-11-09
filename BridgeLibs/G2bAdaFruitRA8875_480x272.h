#ifndef _G2bAdaFruitRA8875_480x272_H
#define _G2bAdaFruitRA8875_480x272_H

#include <Adafruit_RA8875.h>
#include <Adafruit_GFX.h>



class G2bAdaFruitRA8875_480x272 {

 public:
  G2bAdaFruitRA8875_480x272(Adafruit_RA8875* GlobalTFT); // Constructor

  //class variables
  Adafruit_RA8875* AdaTFT;

  void initBridge();
  
  void    fillScreen(uint16_t color);
  boolean touched(void);
  boolean touchRead(uint16_t *x, uint16_t *y);


  void    DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background);
  void    DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor);
  void    DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder);
  void    DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor);
  void	  DrawFillCircle(int16_t XPos, int16_t YPos, int16_t Radius, uint16_t Color);
  void	  DrawCircle(int16_t XPos, int16_t YPos, int16_t Radius, uint16_t Color);
  void    DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t Color);
};

#endif