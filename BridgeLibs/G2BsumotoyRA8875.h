#ifndef _G2BsumotoyRA8875_H
#define _G2BsumotoyRA8875_H

#include <SPI.h>
#include <RA8875.h>

//using sumotoy library it is currently necesary to edit the user settings file to use touchscreen by uncommenting the line '#define USE_RA8875_TOUCH//resistive touch screen'
//it is also required to change the header to move line 'bool              _checkInterrupt(uint8_t _bit,bool _clear=true);' above the protected statement to allow use of software touch press checking
//if using adafruit libraries as well, enum for resolutions must be changed also, suggested add sumo prefix to enum type and all sizes on line 139 of RA8875.h -> enum sumoRA8875sizes { 			sumoRA8875_480x272, sumoRA8875_800x480, sumoRA8875_800x480ALT, sumoAdafruit_480x272, sumoAdafruit_800x480 };
	//additionally line 509, 211 in RA8875 needs sumo prefix added to enum type, corresponding lines 151, and case statements 233-248, and 4726, 5418, 5473
class G2BsumotoyRA8875 {

 public:
  G2BsumotoyRA8875(RA8875* GlobalTFT, enum sumoRA8875sizes s); // Constructor
  enum sumoRA8875sizes ScreenSize;
  //class variables
  RA8875* sumoTFT;

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
  void    writeText(int16_t XPos,int16_t YPos,int16_t boxWidth,int16_t boxHeight,String Text,uint16_t TextColor,const tFont *font,int16_t TextEnlarge,int16_t TextAlignment,int16_t TextWidth, int16_t TextHeight,uint16_t BGColor);
 
};

#endif
