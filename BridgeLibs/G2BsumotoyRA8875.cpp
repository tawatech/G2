#include "G2BsumotoyRA8875.h"

G2BsumotoyRA8875::G2BsumotoyRA8875(RA8875* GlobalTFT, enum sumoRA8875sizes s)
{
    sumoTFT=GlobalTFT;
	ScreenSize=s;
}

void G2BsumotoyRA8875::initBridge()
{
    sumoTFT->begin(ScreenSize);
    sumoTFT->displayOn(true);
    //sumoTFT->GPIOX(true);
    //sumoTFT->PWM1config(true, RA8875_PWM_CLK_DIV1024);
    sumoTFT->brightness(255); 
    sumoTFT->touchBegin();
}

void G2BsumotoyRA8875::fillScreen(uint16_t color)
{
    sumoTFT->fillWindow(color);
}

boolean G2BsumotoyRA8875::touched(void)
{
   return sumoTFT->_checkInterrupt(2);
}

boolean G2BsumotoyRA8875::touchRead(uint16_t *x, uint16_t *y)
{
  sumoTFT->touchReadAdc(x, y);
  *x=1024-*x;
  *y=1024-*y;
  if (*x>=0&&*y>=0)
    return true;
  return false;
}

void    G2BsumotoyRA8875::DrawFillRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,uint16_t Background)
{
  sumoTFT->fillRect(XPos, YPos, Width, Height, Background);
}

void    G2BsumotoyRA8875::DrawCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  sumoTFT->drawCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2BsumotoyRA8875::DrawFillCircle(int16_t XCen,int16_t YCen,int16_t Radius,uint16_t Color)
{
  sumoTFT->fillCircle(XCen+1, YCen+1, Radius, Color);
}

void    G2BsumotoyRA8875::DrawRoundedFilledRectangle(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonColor,uint16_t CornersToSkip)
{
    //always draw the fully rounded version, then just fill in the squared corners
    sumoTFT->fillRoundRect(XPos, YPos, Width, Height, CornerRadius, ButtonColor);
    if (CornersToSkip&1)  //top left
      sumoTFT->fillRect(XPos  , YPos    , CornerRadius, CornerRadius,ButtonColor);
    if (CornersToSkip&2)  //top right
      sumoTFT->fillRect(XPos+CornerRadius  , YPos    , Width-CornerRadius,CornerRadius, ButtonColor);
    if (CornersToSkip&4)  //bottom right
      sumoTFT->fillRect(XPos+CornerRadius  , YPos +CornerRadius   , Width-CornerRadius, Height-CornerRadius, ButtonColor);
    if (CornersToSkip&8)  //bottom left
      sumoTFT->fillRect(XPos , YPos +CornerRadius, CornerRadius, Height-CornerRadius, ButtonColor);
      
}

void    G2BsumotoyRA8875::DrawRoundedRect(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t CornerRadius,uint16_t ButtonBorder,uint16_t CornersToSkip)
{
  if (CornersToSkip==0)
    sumoTFT->drawRoundRect(XPos, YPos, Width, Height, CornerRadius, ButtonBorder);
  else
  {
      //draw in lines from rounded corner to rounded corner
      sumoTFT->drawFastHLine(XPos+CornerRadius  , YPos    , Width-2*CornerRadius, ButtonBorder); // Top
      sumoTFT->drawFastHLine(XPos+CornerRadius  , YPos+Height-1, Width-2*CornerRadius, ButtonBorder); // Bottom
      sumoTFT->drawFastVLine(XPos    , YPos+CornerRadius  , Height-2*CornerRadius, ButtonBorder); // Left
      sumoTFT->drawFastVLine(XPos+Width-1, YPos+CornerRadius  , Height-2*CornerRadius, ButtonBorder); // Right
      
      if (CornersToSkip&1)  //top left
      {
        sumoTFT->drawFastHLine(XPos  , YPos    , CornerRadius, ButtonBorder); // Top
        sumoTFT->drawFastVLine(XPos, YPos  , Height-CornerRadius-1, ButtonBorder); // Left
      }
      else
      {
        drawCircleHelper(XPos+CornerRadius, YPos+CornerRadius    ,CornerRadius,1, ButtonBorder);
      }
      
      if (CornersToSkip&2)  //top right
      {
        sumoTFT->drawFastHLine(XPos+CornerRadius  , YPos    , Width-CornerRadius-1, ButtonBorder); // Top
        sumoTFT->drawFastVLine(XPos+Width-1, YPos  , Height-CornerRadius-1, ButtonBorder); // Right
      }
      else
      {
        drawCircleHelper(XPos+Width-CornerRadius-1, YPos+CornerRadius    , CornerRadius, 2, ButtonBorder);
      }

      if (CornersToSkip&4)  //bottom right
      {
        sumoTFT->drawFastHLine(XPos+CornerRadius  , YPos +Height   , Width-CornerRadius-1, ButtonBorder); // Bottom
        sumoTFT->drawFastVLine(XPos+Width-1, YPos +CornerRadius, Height-CornerRadius-1, ButtonBorder); // Right
      }
      else
      {
        drawCircleHelper(XPos+Width-CornerRadius-1, YPos+Height-CornerRadius-1    , CornerRadius, 4, ButtonBorder);
      }

      if (CornersToSkip&8)  //bottom left
      {
        sumoTFT->drawFastHLine(XPos , YPos +Height, Width-CornerRadius-1, ButtonBorder); // Bottom
        sumoTFT->drawFastVLine(XPos, YPos +CornerRadius, Height-CornerRadius-1, ButtonBorder); // Left
      }
      else
      {
        drawCircleHelper(XPos+CornerRadius, YPos+Height-CornerRadius-1    , CornerRadius, 8, ButtonBorder);
      }
  }
}

void    G2BsumotoyRA8875::DrawLine(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,int16_t LineColor, int16_t LineDirection)
{
  if (LineDirection>0)
  {
    sumoTFT->drawLine(XPos,YPos+Height,XPos+Width,YPos,LineColor);
  }
  else
  {
    sumoTFT->drawLine(XPos,YPos,XPos+Width,YPos+Height,LineColor);
  }
}

void    G2BsumotoyRA8875::DrawCenteredText(int16_t XPos,int16_t YPos,int16_t Width,int16_t Height,String Text,int16_t TextSize,uint16_t TextColor)
{
  sumoTFT->setFont(INT);
  int TextScale=0;
  TextScale=TextSize/10-1;
  if (TextScale<0) TextScale=0;
  int PXwidth=8*Text.length()*(TextScale+1);
  int PXHeight=TextSize*(TextScale+1);
  writeText(XPos,YPos,Width,Height,Text,TextColor,TextScale,1,PXwidth,PXHeight,0);
  /*sumoTFT->textMode();  

  sumoTFT->tft.setFontScale(TextScale);
  sumoTFT->textSetCursor(XPos+XPad, YPos+YPad);
  sumoTFT->textTransparent(TextColor);
  char* buf = new char[Text.length()+1];
  Text.toCharArray(buf, Text.length()+1);
  sumoTFT->textWrite(buf, Text.length()+1);
  
  sumoTFT->textEnlarge(0);
  sumoTFT->graphicsMode();
  */
}

void    G2BsumotoyRA8875::DrawText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,const tFont *font,int16_t TextEnlarge,int16_t TextAlignment, uint16_t BGColor)
{
  int PXwidth,PXHeight;
  if (font==NULL)
  {
    sumoTFT->setFont(INT);
    PXwidth=8*(TextEnlarge+1);
    PXHeight=14*(TextEnlarge+1)*Text.length();
  }
  else
  {
    sumoTFT->setFont(font);
    PXwidth=font->font_width*Text.length();
    PXHeight=font->font_height;
  }
  
  writeText(XPos,YPos,boxWidth,boxHeight,Text,TextColor,TextEnlarge,TextAlignment,PXwidth,PXHeight,BGColor);
}

//private text function to write text based on parameter count methods for either internal, or software fonts, or deprecated method call

void    G2BsumotoyRA8875::writeText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,int16_t TextEnlarge,int16_t TextAlignment, int16_t TextWidth, int16_t TextHeight, uint16_t BGColor)
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
    //Text=Text+'\0'; //seems to help stop over-run printing background
    sumoTFT->setFontScale(TextEnlarge);
    sumoTFT->setCursor(XPos+XPad,YPos+YPad);
    sumoTFT->setTextColor(TextColor,BGColor);
    sumoTFT->print(Text);
}

//internal draw functions to replicate functionality in other libraries

void G2BsumotoyRA8875::drawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) 
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      sumoTFT->drawPixel(x0 + x, y0 + y, color);
      sumoTFT->drawPixel(x0 + y, y0 + x, color);
    }
    if (cornername & 0x2) {
      sumoTFT->drawPixel(x0 + x, y0 - y, color);
      sumoTFT->drawPixel(x0 + y, y0 - x, color);
    }
    if (cornername & 0x8) {
      sumoTFT->drawPixel(x0 - y, y0 + x, color);
      sumoTFT->drawPixel(x0 - x, y0 + y, color);
    }
    if (cornername & 0x1) {
      sumoTFT->drawPixel(x0 - y, y0 - x, color);
      sumoTFT->drawPixel(x0 - x, y0 - y, color);
    }
  }
}
