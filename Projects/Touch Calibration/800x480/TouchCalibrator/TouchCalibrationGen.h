//Automatically generated header file by G2

#include <SPI.h>
#include "G2bAdaFruitRA8875.h"

#define ada_RA8875_CS      10
class TouchCalibrationGen{
public:G2bAdaFruitRA8875* tft;

//G2 created struct for Indicator_Light
struct Indicator_Light{
    G2bAdaFruitRA8875* ltft;
    int ObjectState;
    String UName;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int OnColor;
    int OffColor;
    int DisabledColor;
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
            case 3:
                draw3();
                break;
        }
    }
//G2 generated function for method Clear
      void draw0()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,Background);
      }
//G2 generated function for method On
      void draw1()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,OnColor);
      }
//G2 generated function for method Off
      void draw2()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,OffColor);
      }
//G2 generated function for method Disabled
      void draw3()
      {
          ltft->DrawFillCircle(XPos+Width/2,YPos+Width/2,Width/2,DisabledColor);
      }
};

//G2 created struct for Label
struct Label{
    G2bAdaFruitRA8875* ltft;
    int ObjectState;
    String UName;
    int UID;
    int XPos;
    int YPos;
    int clickWidth;
    int clickHeight;
    int Width;
    int Height;
    int TextEnlarge;
    int TextColor;
    int Background;
    int TextJustification;
    String Text;
    const tFont* FontName;
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
          ltft->DrawText(XPos,YPos,Width,Height,Text,TextColor,FontName,TextEnlarge,TextJustification,Background);
      }
};

Indicator_Light Indicator_Light_inst[3];
Label Label_inst[9];

char Indicator_Light_wstate[3][1];
char Label_wstate[9][1];
int prevClickID=0;
int confirmClickID=0;
int PointIndex=0;
int PointIndex_prev=PointIndex;
int X1;
int X2;
int X3;
int Y1;
int Y1_prev=Y1;
int Y2;
int Y2_prev=Y2;
int Y3;
int Y3_prev=Y3;

//Function Definitions
void initTFT(G2bAdaFruitRA8875* tft2, int DefaultState=0);
void initObjects();
void stateUpdateObjects(int NewState);
int clickChecker();
int clickHandler(int objUID);
int displayScan();
int variableScan();
};
