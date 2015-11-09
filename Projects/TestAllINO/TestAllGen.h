//Automatically generated header file by G2

#include <SPI.h>
#include "G2bAdaFruitRA8875_800x480.h"

#define RA8875_INT     3
#define RA8875_CS      10
#define RA8875_RESET   9

class TestAllGen{
public:G2bAdaFruitRA8875_800x480* tft;

//G2 created struct for Bar_Fill_Vert
struct Bar_Fill_Vert{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int CornerRadius;
    int FillColor;
    int BorderColor;
    int FillPercentage;
    int UnFillColor;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,UnFillColor);
          ltft->DrawRoundedFilledRectangle(XPos+0,YPos+Height-FillPercentage*Height/100,Width,FillPercentage*Height/100,CornerRadius,FillColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,BorderColor);
      }
};

//G2 created struct for Circle
struct Circle{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int Radius;
    int CircleColor;
    int CircleBorder;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawFillCircle(XPos+Radius,YPos+Radius,Radius,CircleColor);
          ltft->DrawCircle(XPos+Radius,YPos+Radius,Radius,CircleBorder);
      }
};

//G2 created struct for Line
struct Line{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int LineColor;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawLine(XPos,YPos,XPos+Width,YPos+Height,LineColor);
      }
};

//G2 created struct for Horizontal_Progress
struct Horizontal_Progress{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int LineHeight;
    int FillColor;
    int FillPercentage;
    int UnFillColor;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
          ltft->DrawRoundedFilledRectangle(XPos+0,YPos+(Height-LineHeight)/2,Width,LineHeight,0,UnFillColor);
          ltft->DrawRoundedFilledRectangle(XPos+0,YPos+(Height-LineHeight)/2,(Width*FillPercentage)/100,LineHeight,0,FillColor);
          ltft->DrawFillCircle(XPos+Height/2+((Width-Height)*FillPercentage)/100,YPos+Height/2+0,Height/2,FillColor);
      }
};

//G2 created struct for Label
struct Label{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int TextSize;
    int TextColor;
    int Background;
    String Text;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
          ltft->DrawCenteredText(XPos,YPos,Width,Height,Text,TextSize,TextColor);
      }
};

//G2 created struct for Panel
struct Panel{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int CornerRadius;
    int PanelColor;
    int PanelBorder;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,PanelColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,PanelBorder);
      }
};

//G2 created struct for Push_Button
struct Push_Button{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int CornerRadius;
    int ButtonColor;
    int ButtonBorder;
    int TextSize;
    int TextColor;
    int PressedTextColor;
    int PressedButtonColor;
    int PressedBorderColor;
    int Background;
    String Text;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
            case 2:
                draw2();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,ButtonColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,ButtonBorder);
          ltft->DrawCenteredText(XPos,YPos,Width,Height,Text,TextSize,TextColor);
      }
//G2 generated function for method Pressed
      void draw2()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,PressedButtonColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,PressedBorderColor);
          ltft->DrawCenteredText(XPos,YPos,Width,Height,Text,TextSize,PressedTextColor);
      }
};

//G2 created struct for Radio_Button
struct Radio_Button{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int CircleColor;
    int OnCircleColor;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
            case 2:
                draw2();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,CircleColor);
      }
//G2 generated function for method Pressed
      void draw2()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,CircleColor);
          ltft->DrawFillCircle(XPos+Width/4+Width/4,YPos+Width/4+Height/4,Width/4,OnCircleColor);
      }
};

//G2 created struct for Side_Toggle
struct Side_Toggle{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int SlideSize;
    int CornerRadius;
    int SlideColor;
    int OnColor;
    int OffColor;
    int Background;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
            case 2:
                draw2();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,OnColor);
          ltft->DrawRoundedFilledRectangle(XPos+(Height-SlideSize)/2,YPos+(Height-SlideSize)/2,SlideSize,SlideSize,CornerRadius,SlideColor);
      }
//G2 generated function for method Pressed
      void draw2()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,OffColor);
          ltft->DrawRoundedFilledRectangle(XPos+Width-SlideSize-(Height-SlideSize)/2,YPos+(Height-SlideSize)/2,SlideSize,SlideSize,CornerRadius,SlideColor);
      }
};

//G2 created struct for Toggle_Button
struct Toggle_Button{
    G2bAdaFruitRA8875_800x480* ltft;
    int ObjectState;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int CornerRadius;
    int ButtonColor;
    int ButtonBorder;
    int TextSize;
    int TextColor;
    int PressedTextColor;
    int PressedButtonColor;
    int PressedBorderColor;
    int Background;
    String Unpressed_Text;
    String Pressed_Text;
    void selectiveUpdateState(int StateID)
    {
        if (StateID==ObjectState)
            return;
        else
        {
            ObjectState=StateID;
            drawByState();
        }
    }
    void drawByState()
    {
        switch (ObjectState){
            default:
                draw0();
                break;
            case 1:
                draw1();
                break;
            case 2:
                draw2();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillRect(XPos,YPos,Width,Height,Background);
      }
//G2 generated function for method Default
      void draw1()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,ButtonColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,ButtonBorder);
          ltft->DrawCenteredText(XPos,YPos,Width,Height,Unpressed_Text,TextSize,TextColor);
      }
//G2 generated function for method Pressed
      void draw2()
      {
          ltft->DrawRoundedFilledRectangle(XPos,YPos,Width,Height,CornerRadius,PressedButtonColor);
          ltft->DrawRoundedRect(XPos,YPos,Width,Height,CornerRadius,PressedBorderColor);
          ltft->DrawCenteredText(XPos,YPos,Width,Height,Pressed_Text,TextSize,PressedTextColor);
      }
};

Bar_Fill_Vert Bar_Fill_Vert_inst[1];
Circle Circle_inst[1];
Line Line_inst[1];
Horizontal_Progress Horizontal_Progress_inst[1];
Label Label_inst[1];
Panel Panel_inst[1];
Push_Button Push_Button_inst[2];
Radio_Button Radio_Button_inst[1];
Side_Toggle Side_Toggle_inst[1];
Toggle_Button Toggle_Button_inst[1];

char Bar_Fill_Vert_wstate[1][1];
char Circle_wstate[1][1];
char Line_wstate[1][1];
char Horizontal_Progress_wstate[1][1];
char Label_wstate[1][1];
char Panel_wstate[1][1];
char Push_Button_wstate[2][1];
char Radio_Button_wstate[1][1];
char Side_Toggle_wstate[1][1];
char Toggle_Button_wstate[1][1];
int prevClickID=0;
int confirmClickID=0;

//Function Definitions
void initTFT(G2bAdaFruitRA8875_800x480* tft2, int DefaultState=0);
void initObjects();
void stateUpdateObjects(int NewState);
int clickChecker();
int clickHandler(int objUID);
int displayScan();
int variableScan();
};
