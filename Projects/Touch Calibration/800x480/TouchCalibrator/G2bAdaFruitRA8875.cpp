#include "G2bAdaFruitRA8875.h"

G2bAdaFruitRA8875::G2bAdaFruitRA8875(Adafruit_RA8875* GlobalTFT, enum RA8875sizes s)
{
    AdaTFT=GlobalTFT;
	ScreenSize=s;
}

void G2bAdaFruitRA8875::initBridge()
{
    AdaTFT->begin(ScreenSize);
    AdaTFT->displayOn(true);
    AdaTFT->GPIOX(true);
    AdaTFT->PWM1config(true, RA8875_PWM_CLK_DIV1024);
    AdaTFT->PWM1out(255);
    AdaTFT->touchEnable(true);    
}

void G2bAdaFruitRA8875::fillScreen(uint16_t color)
{
    AdaTFT->fillScreen(color);
}

boolean G2bAdaFruitRA8875::touched(void)
{
   return AdaTFT->touched();
}

boolean G2bAdaFruitRA8875::touchRead(uint16_t *x, uint16_t *y)
{
  return AdaTFT->touchRead(x, y);
}

void    G2bAdaFruitRA8875::DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background)
{
  AdaTFT->fillRect(XPos, YPos, Width, Height, Background);
}

void    G2bAdaFruitRA8875::DrawCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  AdaTFT->drawCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2bAdaFruitRA8875::DrawFillCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  AdaTFT->fillCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2bAdaFruitRA8875::DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor,uint16_t CornersToSkip)
{
    //always draw the fully rounded version, then just fill in the squared corners
    AdaTFT->fillRoundRect(XPos, YPos, Width, Height, CornerRadius, ButtonColor);

    if (CornersToSkip&1)  //top left
      AdaTFT->fillRect(XPos  , YPos    , CornerRadius, CornerRadius,ButtonColor);
    if (CornersToSkip&2)  //top right
      AdaTFT->fillRect(XPos+CornerRadius  , YPos    , Width-CornerRadius-1,CornerRadius, ButtonColor);
    if (CornersToSkip&4)  //bottom right
      AdaTFT->fillRect(XPos+CornerRadius  , YPos +CornerRadius   , Width-CornerRadius-1, Height-CornerRadius, ButtonColor);
    if (CornersToSkip&8)  //bottom left
      AdaTFT->fillRect(XPos , YPos +CornerRadius, CornerRadius, Height-CornerRadius, ButtonColor);
}

void    G2bAdaFruitRA8875::DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder,uint16_t CornersToSkip)
{
  if (CornersToSkip==0)
    AdaTFT->drawRoundRect(XPos, YPos, Width, Height, CornerRadius, ButtonBorder);
  else
  {
      //draw in lines from rounded corner to rounded corner
      AdaTFT->drawFastHLine(XPos+CornerRadius  , YPos    , Width-2*CornerRadius, ButtonBorder); // Top
      AdaTFT->drawFastHLine(XPos+CornerRadius  , YPos+Height-1, Width-2*CornerRadius, ButtonBorder); // Bottom
      AdaTFT->drawFastVLine(XPos    , YPos+CornerRadius  , Height-2*CornerRadius, ButtonBorder); // Left
      AdaTFT->drawFastVLine(XPos+Width-1, YPos+CornerRadius  , Height-2*CornerRadius, ButtonBorder); // Right
      if (CornersToSkip&1)  //top left
      {
        AdaTFT->drawFastHLine(XPos  , YPos    , CornerRadius, ButtonBorder); // Top
        AdaTFT->drawFastVLine(XPos, YPos  , Height-CornerRadius-1, ButtonBorder); // Left
      }
      else
      {
        AdaTFT->drawCircleHelper(XPos+CornerRadius, YPos+CornerRadius    , CornerRadius, 1, ButtonBorder);
      }
      
      if (CornersToSkip&2)  //top right
      {
        AdaTFT->drawFastHLine(XPos+CornerRadius  , YPos    , Width-CornerRadius-1, ButtonBorder); // Top
        AdaTFT->drawFastVLine(XPos+Width-1, YPos  , Height-CornerRadius-1, ButtonBorder); // Right
      }
      else
      {
        AdaTFT->drawCircleHelper(XPos+Width-CornerRadius-1, YPos+CornerRadius    , CornerRadius, 2, ButtonBorder);
      }

      if (CornersToSkip&4)  //bottom right
      {
        AdaTFT->drawFastHLine(XPos+CornerRadius  , YPos +Height   , Width-CornerRadius-1, ButtonBorder); // Bottom
        AdaTFT->drawFastVLine(XPos+Width-1, YPos +CornerRadius, Height-CornerRadius-1, ButtonBorder); // Right
      }
      else
      {
        AdaTFT->drawCircleHelper(XPos+Width-CornerRadius-1, YPos+Height-CornerRadius-1    , CornerRadius, 4, ButtonBorder);
      }

      if (CornersToSkip&8)  //bottom left
      {
        AdaTFT->drawFastHLine(XPos , YPos +Height, Width-CornerRadius-1, ButtonBorder); // Bottom
        AdaTFT->drawFastVLine(XPos, YPos +CornerRadius, Height-CornerRadius-1, ButtonBorder); // Left
      }
      else
      {
        AdaTFT->drawCircleHelper(XPos+CornerRadius, YPos+Height-CornerRadius-1    , CornerRadius, 8, ButtonBorder);
      }
  }
}

void    G2bAdaFruitRA8875::DrawLine(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t LineColor, int16_t LineDirection)
{
  if (LineDirection>0)
  {
    AdaTFT->drawLine(XPos,YPos+Height,XPos+Width,YPos,LineColor);
  }
  else
  {
    AdaTFT->drawLine(XPos,YPos,XPos+Width,YPos+Height,LineColor);
  }
}

void    G2bAdaFruitRA8875::DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor)
{
  int TextScale=0;
  TextScale=TextSize/10-1;
  if (TextScale<0) TextScale=0;
  int PXwidth=8*Text.length()*(TextScale+1);
  int PXHeight=TextSize*(TextScale+1);
  writeText(XPos,YPos,Width,Height,Text,TextColor,TextScale,1,PXwidth,PXHeight,0);
}

void    G2bAdaFruitRA8875::DrawText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,const tFont *font,int16_t TextEnlarge,int16_t TextAlignment, uint16_t BGColor)
{
  int PXwidth,PXHeight;
  PXwidth=8*(TextEnlarge+1)*Text.length();
  PXHeight=14*(TextEnlarge+1);
  
  writeText(XPos,YPos,boxWidth,boxHeight,Text,TextColor,TextEnlarge,TextAlignment,PXwidth,PXHeight,BGColor);
}

//private text function to write text based on parameter count methods for either internal, or software fonts, or deprecated method call

void    G2bAdaFruitRA8875::writeText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,int16_t TextEnlarge,int16_t TextAlignment, int16_t TextWidth, int16_t TextHeight, uint16_t BGColor)
{    
    int XPad=0, YPad=0;

    switch (TextAlignment)
    {
      case 0:
        XPad=0;
        break;
      case 1:
        XPad=(boxWidth-TextWidth)/2;
        break;
      case 2:
        XPad=boxWidth-TextWidth-5;  //minus 5 for safety when using non constant width fonts
        break;
    }   
    YPad=(boxHeight-TextHeight)/2;
 
  AdaTFT->textMode();
  AdaTFT->textEnlarge(TextEnlarge);
  AdaTFT->textSetCursor(XPos+XPad, YPos+YPad);
  AdaTFT->textTransparent(TextColor);
  char* buf = new char[Text.length()+1];
  Text.toCharArray(buf, Text.length()+1);
  AdaTFT->textWrite(buf, Text.length()+1);
  AdaTFT->textEnlarge(0);
  AdaTFT->graphicsMode();
}
