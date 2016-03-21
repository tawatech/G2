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

  void    DrawCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color);
  void    DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background);
  void    DrawFillCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color);
  void    DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor, uint16_t CornersToSkip = 0);
  void    DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder, uint16_t CornersToSkip = 0);
  void    DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor);
 
};

#endif
