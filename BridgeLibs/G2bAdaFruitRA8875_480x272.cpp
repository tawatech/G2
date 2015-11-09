#include "G2bAdaFruitRA8875_480x272.h"

G2bAdaFruitRA8875_480x272::G2bAdaFruitRA8875_480x272(Adafruit_RA8875* GlobalTFT)
{
    AdaTFT=GlobalTFT;
}

void G2bAdaFruitRA8875_480x272::initBridge()
{
    AdaTFT->begin(RA8875_480x272);
    AdaTFT->displayOn(true);
    AdaTFT->GPIOX(true);
    AdaTFT->PWM1config(true, RA8875_PWM_CLK_DIV1024);
    AdaTFT->PWM1out(255);
    AdaTFT->touchEnable(true);    
}

void G2bAdaFruitRA8875_480x272::fillScreen(uint16_t color)
{
    AdaTFT->fillScreen(color);
}

boolean G2bAdaFruitRA8875_480x272::touched(void)
{
   return AdaTFT->touched();
}

boolean G2bAdaFruitRA8875_480x272::touchRead(uint16_t *x, uint16_t *y)
{
  return AdaTFT->touchRead(x, y);
}

void    G2bAdaFruitRA8875_480x272::DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background)
{
  AdaTFT->fillRect(XPos, YPos, Width, Height, Background);
}

void    G2bAdaFruitRA8875_480x272::DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor)
{
  AdaTFT->fillRoundRect(XPos, YPos, Width, Height, CornerRadius, ButtonColor);
}

void    G2bAdaFruitRA8875_480x272::DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder)
{
  AdaTFT->drawRoundRect(XPos, YPos, Width, Height+1, CornerRadius, ButtonBorder);
}

void    G2bAdaFruitRA8875_480x272::DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor)
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

void	  G2bAdaFruitRA8875_480x272::DrawFillCircle(int16_t XPos, int16_t YPos, int16_t Radius, uint16_t Color)
{
	AdaTFT->fillCircle(XPos, YPos, Radius, Color);
}

void	  G2bAdaFruitRA8875_480x272::DrawCircle(int16_t XPos, int16_t YPos, int16_t Radius, uint16_t Color)
{
	AdaTFT->drawCircle(XPos, YPos, Radius, Color);
}

void    G2bAdaFruitRA8875_480x272::DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t Color)
{
	AdaTFT->drawLine(x0, y0, x1, y1, Color);
}
