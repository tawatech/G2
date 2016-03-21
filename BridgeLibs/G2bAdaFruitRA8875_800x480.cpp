#include "G2bAdaFruitRA8875_800x480.h"

G2bAdaFruitRA8875_800x480::G2bAdaFruitRA8875_800x480(Adafruit_RA8875* GlobalTFT)
{
    AdaTFT=GlobalTFT;
}

void G2bAdaFruitRA8875_800x480::initBridge()
{
    AdaTFT->begin(RA8875_800x480);
    AdaTFT->displayOn(true);
    AdaTFT->GPIOX(true);
    AdaTFT->PWM1config(true, RA8875_PWM_CLK_DIV1024);
    AdaTFT->PWM1out(255);
    AdaTFT->touchEnable(true);    
}

void G2bAdaFruitRA8875_800x480::fillScreen(uint16_t color)
{
    AdaTFT->fillScreen(color);
}

boolean G2bAdaFruitRA8875_800x480::touched(void)
{
   return AdaTFT->touched();
}

boolean G2bAdaFruitRA8875_800x480::touchRead(uint16_t *x, uint16_t *y)
{
  return AdaTFT->touchRead(x, y);
}

void    G2bAdaFruitRA8875_800x480::DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background)
{
  AdaTFT->fillRect(XPos, YPos, Width, Height, Background);
}

void    G2bAdaFruitRA8875_800x480::DrawCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  AdaTFT->drawCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2bAdaFruitRA8875_800x480::DrawFillCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  AdaTFT->fillCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2bAdaFruitRA8875_800x480::DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor,uint16_t CornersToSkip)
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

void    G2bAdaFruitRA8875_800x480::DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder,uint16_t CornersToSkip)
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

void    G2bAdaFruitRA8875_800x480::DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor)
{
  AdaTFT->textMode();
  int TextScale=0;
  TextScale=TextSize/10-1;
  if (TextScale<0) TextScale=0;
  AdaTFT->textEnlarge(TextScale);
  int PXwidth=8*Text.length()*(TextScale+1);
  int XPad=(Width-PXwidth)/2;
  int YPad=(Height-TextSize*(TextScale+1))/2-TextSize*(TextScale+1)/2;
  AdaTFT->textSetCursor(XPos+XPad, YPos+YPad);
  AdaTFT->textTransparent(TextColor);
  char* buf = new char[Text.length()+1];
  Text.toCharArray(buf, Text.length()+1);
  AdaTFT->textWrite(buf, Text.length()+1);
  AdaTFT->textEnlarge(0);
  AdaTFT->graphicsMode();
}
