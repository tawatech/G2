#ifndef _G2bAdaFruitRA8875_H
#define _G2bAdaFruitRA8875_H

#include <Adafruit_RA8875.h>
#include <Adafruit_GFX.h>


struct tFont{	//empty struct as placholder (required for standarised function calls)
};


class G2bAdaFruitRA8875 {

 public:
  G2bAdaFruitRA8875(Adafruit_RA8875* GlobalTFT, enum RA8875sizes s); // Constructor

  //class variables
  Adafruit_RA8875* AdaTFT;
  enum RA8875sizes ScreenSize;

  void initBridge();
  
  void    fillScreen(uint16_t color);
  boolean touched(void);
  boolean touchRead(uint16_t *x, uint16_t *y);

  void    DrawCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color);
  void    DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background);
  void    DrawFillCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color);
  void    DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor, uint16_t CornersToSkip = 0);
  void    DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder, uint16_t CornersToSkip = 0);
  void    DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor); //deprecated
  void    DrawText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,const tFont *font,int16_t TextEnlarge=0,int16_t TextAlignment=1,uint16_t BGColor=0);
  void    DrawLine(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t LineColor, int16_t LineDirection);

//internal draw functions to replicate functionality in other libraries
private:
  void    drawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
  void    writeText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,int16_t TextEnlarge,int16_t TextAlignment,int16_t TextWidth, int16_t TextHeight,uint16_t BGColor);
 
};

#endif
