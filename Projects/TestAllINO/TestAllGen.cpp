#include "TestAllGen.h"
//Automatically generated code file by G2

//Basic Init function
void TestAllGen::initTFT(G2bAdaFruitRA8875_800x480* tft2, int DefaultState)
{
    tft=tft2;
    pinMode(RA8875_INT, INPUT);
    digitalWrite(RA8875_INT, HIGH);
    tft->fillScreen(61277);
    initObjects();
    stateUpdateObjects(DefaultState);
}

int TestAllGen::displayScan()
{
     int ClickID = clickChecker();
     if (ClickID!=prevClickID&&confirmClickID==ClickID)
     {
         int ReturnID;
         if (ClickID>0)
         {
             if (prevClickID>0)
                clickHandler(-prevClickID);
             ReturnID=clickHandler(ClickID);
         }
         else
             ReturnID=clickHandler(-prevClickID);
         prevClickID=ClickID;
         if (ReturnID!=0)
             return ReturnID;
     }
     confirmClickID=ClickID;
     return variableScan();
}

int TestAllGen::clickHandler(int objUID)
{
    switch (objUID){
        case 1:     //click Push_Button_1
            Push_Button_inst[0].ObjectState=2;
            Push_Button_inst[0].drawByState();
            break;
        case 2:     //click Radio_Button_2
            Radio_Button_inst[0].ObjectState=Radio_Button_inst[0].ObjectState%2+1;
            Radio_Button_inst[0].drawByState();
            break;
        case 3:     //click Side_Toggle_3
            Side_Toggle_inst[0].ObjectState=Side_Toggle_inst[0].ObjectState%2+1;
            Side_Toggle_inst[0].drawByState();
            break;
        case 4:     //click Toggle_Button_4
            Toggle_Button_inst[0].ObjectState=Toggle_Button_inst[0].ObjectState%2+1;
            Toggle_Button_inst[0].drawByState();
            break;
        case 11:     //click Push_Button_11
            Push_Button_inst[1].ObjectState=2;
            Push_Button_inst[1].drawByState();
            break;
    //unclick commands are indexed by the -ve UID for simplicity
        case -1:     //unclick Push_Button_1
            Push_Button_inst[0].ObjectState=1;
            Push_Button_inst[0].drawByState();
            break;
        case -11:     //unclick Push_Button_11
            Push_Button_inst[1].ObjectState=1;
            Push_Button_inst[1].drawByState();
            break;
    }
    return 0;
}

//variable change handler, performs display/general functions when a display variable is changed
int TestAllGen::variableScan()
{
     return 0;
}

void TestAllGen::initObjects()
{
  Push_Button_inst[0].ltft=tft;
  Push_Button_inst[0].ObjectState=-1;
  Push_Button_inst[0].UID=1;
  Push_Button_inst[0].XPos=15;
  Push_Button_inst[0].YPos=13;
  Push_Button_inst[0].clickWidth=100;
  Push_Button_inst[0].clickHeight=24;
  Push_Button_inst[0].Width=100;
  Push_Button_inst[0].Height=24;
  Push_Button_inst[0].CornerRadius=5;
  Push_Button_inst[0].ButtonColor=21130;
  Push_Button_inst[0].ButtonBorder=21130;
  Push_Button_inst[0].TextSize=10;
  Push_Button_inst[0].TextColor=65535;
  Push_Button_inst[0].PressedTextColor=33808;
  Push_Button_inst[0].PressedButtonColor=8452;
  Push_Button_inst[0].PressedBorderColor=25388;
  Push_Button_inst[0].Background=61277;
  Push_Button_inst[0].Text="Push Button";
  Push_Button_inst[0].drawByState();
  Push_Button_wstate[0][0]=1;
  Radio_Button_inst[0].ltft=tft;
  Radio_Button_inst[0].ObjectState=-1;
  Radio_Button_inst[0].UID=2;
  Radio_Button_inst[0].XPos=137;
  Radio_Button_inst[0].YPos=10;
  Radio_Button_inst[0].clickWidth=28;
  Radio_Button_inst[0].clickHeight=28;
  Radio_Button_inst[0].Width=28;
  Radio_Button_inst[0].Height=28;
  Radio_Button_inst[0].CircleColor=21130;
  Radio_Button_inst[0].OnCircleColor=8452;
  Radio_Button_inst[0].Background=61277;
  Radio_Button_inst[0].drawByState();
  Radio_Button_wstate[0][0]=1;
  Side_Toggle_inst[0].ltft=tft;
  Side_Toggle_inst[0].ObjectState=-1;
  Side_Toggle_inst[0].UID=3;
  Side_Toggle_inst[0].XPos=192;
  Side_Toggle_inst[0].YPos=13;
  Side_Toggle_inst[0].clickWidth=50;
  Side_Toggle_inst[0].clickHeight=28;
  Side_Toggle_inst[0].Width=50;
  Side_Toggle_inst[0].Height=28;
  Side_Toggle_inst[0].SlideSize=22;
  Side_Toggle_inst[0].CornerRadius=3;
  Side_Toggle_inst[0].SlideColor=65535;
  Side_Toggle_inst[0].OnColor=21130;
  Side_Toggle_inst[0].OffColor=8452;
  Side_Toggle_inst[0].Background=61277;
  Side_Toggle_inst[0].drawByState();
  Side_Toggle_wstate[0][0]=1;
  Toggle_Button_inst[0].ltft=tft;
  Toggle_Button_inst[0].ObjectState=-1;
  Toggle_Button_inst[0].UID=4;
  Toggle_Button_inst[0].XPos=307;
  Toggle_Button_inst[0].YPos=50;
  Toggle_Button_inst[0].clickWidth=100;
  Toggle_Button_inst[0].clickHeight=24;
  Toggle_Button_inst[0].Width=100;
  Toggle_Button_inst[0].Height=24;
  Toggle_Button_inst[0].CornerRadius=5;
  Toggle_Button_inst[0].ButtonColor=21130;
  Toggle_Button_inst[0].ButtonBorder=21130;
  Toggle_Button_inst[0].TextSize=10;
  Toggle_Button_inst[0].TextColor=65535;
  Toggle_Button_inst[0].PressedTextColor=33808;
  Toggle_Button_inst[0].PressedButtonColor=8452;
  Toggle_Button_inst[0].PressedBorderColor=25388;
  Toggle_Button_inst[0].Background=61277;
  Toggle_Button_inst[0].Unpressed_Text="TGL OFF";
  Toggle_Button_inst[0].Pressed_Text="TGL ON";
  Toggle_Button_inst[0].drawByState();
  Toggle_Button_wstate[0][0]=1;
  Bar_Fill_Vert_inst[0].ltft=tft;
  Bar_Fill_Vert_inst[0].ObjectState=-1;
  Bar_Fill_Vert_inst[0].UID=5;
  Bar_Fill_Vert_inst[0].XPos=23;
  Bar_Fill_Vert_inst[0].YPos=108;
  Bar_Fill_Vert_inst[0].clickWidth=40;
  Bar_Fill_Vert_inst[0].clickHeight=100;
  Bar_Fill_Vert_inst[0].Width=40;
  Bar_Fill_Vert_inst[0].Height=100;
  Bar_Fill_Vert_inst[0].CornerRadius=2;
  Bar_Fill_Vert_inst[0].FillColor=21130;
  Bar_Fill_Vert_inst[0].BorderColor=21130;
  Bar_Fill_Vert_inst[0].FillPercentage=50;
  Bar_Fill_Vert_inst[0].UnFillColor=8452;
  Bar_Fill_Vert_inst[0].Background=61277;
  Bar_Fill_Vert_inst[0].drawByState();
  Bar_Fill_Vert_wstate[0][0]=1;
  Horizontal_Progress_inst[0].ltft=tft;
  Horizontal_Progress_inst[0].ObjectState=-1;
  Horizontal_Progress_inst[0].UID=6;
  Horizontal_Progress_inst[0].XPos=136;
  Horizontal_Progress_inst[0].YPos=139;
  Horizontal_Progress_inst[0].clickWidth=100;
  Horizontal_Progress_inst[0].clickHeight=20;
  Horizontal_Progress_inst[0].Width=100;
  Horizontal_Progress_inst[0].Height=20;
  Horizontal_Progress_inst[0].LineHeight=2;
  Horizontal_Progress_inst[0].FillColor=21130;
  Horizontal_Progress_inst[0].FillPercentage=50;
  Horizontal_Progress_inst[0].UnFillColor=8452;
  Horizontal_Progress_inst[0].Background=61277;
  Horizontal_Progress_inst[0].drawByState();
  Horizontal_Progress_wstate[0][0]=1;
  Label_inst[0].ltft=tft;
  Label_inst[0].ObjectState=-1;
  Label_inst[0].UID=7;
  Label_inst[0].XPos=290;
  Label_inst[0].YPos=124;
  Label_inst[0].clickWidth=100;
  Label_inst[0].clickHeight=24;
  Label_inst[0].Width=100;
  Label_inst[0].Height=24;
  Label_inst[0].TextSize=10;
  Label_inst[0].TextColor=65535;
  Label_inst[0].Background=61277;
  Label_inst[0].Text="Label";
  Label_inst[0].drawByState();
  Label_wstate[0][0]=1;
  Circle_inst[0].ltft=tft;
  Circle_inst[0].ObjectState=-1;
  Circle_inst[0].UID=8;
  Circle_inst[0].XPos=30;
  Circle_inst[0].YPos=276;
  Circle_inst[0].clickWidth=0;
  Circle_inst[0].clickHeight=0;
  Circle_inst[0].Width=50;
  Circle_inst[0].Height=50;
  Circle_inst[0].Radius=24;
  Circle_inst[0].CircleColor=21130;
  Circle_inst[0].CircleBorder=21130;
  Circle_inst[0].Background=61277;
  Circle_inst[0].drawByState();
  Circle_wstate[0][0]=1;
  Line_inst[0].ltft=tft;
  Line_inst[0].ObjectState=-1;
  Line_inst[0].UID=9;
  Line_inst[0].XPos=133;
  Line_inst[0].YPos=284;
  Line_inst[0].clickWidth=0;
  Line_inst[0].clickHeight=0;
  Line_inst[0].Width=60;
  Line_inst[0].Height=20;
  Line_inst[0].LineColor=21130;
  Line_inst[0].Background=61277;
  Line_inst[0].drawByState();
  Line_wstate[0][0]=1;
  Panel_inst[0].ltft=tft;
  Panel_inst[0].ObjectState=-1;
  Panel_inst[0].UID=10;
  Panel_inst[0].XPos=271;
  Panel_inst[0].YPos=274;
  Panel_inst[0].clickWidth=0;
  Panel_inst[0].clickHeight=0;
  Panel_inst[0].Width=150;
  Panel_inst[0].Height=60;
  Panel_inst[0].CornerRadius=5;
  Panel_inst[0].PanelColor=21130;
  Panel_inst[0].PanelBorder=21130;
  Panel_inst[0].Background=61277;
  Panel_inst[0].drawByState();
  Panel_wstate[0][0]=1;
  Push_Button_inst[1].ltft=tft;
  Push_Button_inst[1].ObjectState=-1;
  Push_Button_inst[1].UID=11;
  Push_Button_inst[1].XPos=497;
  Push_Button_inst[1].YPos=145;
  Push_Button_inst[1].clickWidth=100;
  Push_Button_inst[1].clickHeight=24;
  Push_Button_inst[1].Width=200;
  Push_Button_inst[1].Height=150;
  Push_Button_inst[1].CornerRadius=5;
  Push_Button_inst[1].ButtonColor=63488;
  Push_Button_inst[1].ButtonBorder=21130;
  Push_Button_inst[1].TextSize=10;
  Push_Button_inst[1].TextColor=65535;
  Push_Button_inst[1].PressedTextColor=33808;
  Push_Button_inst[1].PressedButtonColor=65504;
  Push_Button_inst[1].PressedBorderColor=25388;
  Push_Button_inst[1].Background=61277;
  Push_Button_inst[1].Text="Push Button";
  Push_Button_inst[1].drawByState();
  Push_Button_wstate[1][0]=1;
}

void TestAllGen::stateUpdateObjects(int NewState)
{
   if(Toggle_Button_wstate[0][NewState]==0)       Toggle_Button_inst[0].selectiveUpdateState(-abs(Toggle_Button_inst[0].ObjectState));
   if(Side_Toggle_wstate[0][NewState]==0)       Side_Toggle_inst[0].selectiveUpdateState(-abs(Side_Toggle_inst[0].ObjectState));
   if(Radio_Button_wstate[0][NewState]==0)       Radio_Button_inst[0].selectiveUpdateState(-abs(Radio_Button_inst[0].ObjectState));
   if(Push_Button_wstate[0][NewState]==0)       Push_Button_inst[0].selectiveUpdateState(-abs(Push_Button_inst[0].ObjectState));
   if(Push_Button_wstate[1][NewState]==0)       Push_Button_inst[1].selectiveUpdateState(-abs(Push_Button_inst[1].ObjectState));
   if(Label_wstate[0][NewState]==0)       Label_inst[0].selectiveUpdateState(-abs(Label_inst[0].ObjectState));
   if(Horizontal_Progress_wstate[0][NewState]==0)       Horizontal_Progress_inst[0].selectiveUpdateState(-abs(Horizontal_Progress_inst[0].ObjectState));
   if(Bar_Fill_Vert_wstate[0][NewState]==0)       Bar_Fill_Vert_inst[0].selectiveUpdateState(-abs(Bar_Fill_Vert_inst[0].ObjectState));
   if(Line_wstate[0][NewState]==0)       Line_inst[0].selectiveUpdateState(-abs(Line_inst[0].ObjectState));
   if(Circle_wstate[0][NewState]==0)       Circle_inst[0].selectiveUpdateState(-abs(Circle_inst[0].ObjectState));
   if(Panel_wstate[0][NewState]==0)       Panel_inst[0].selectiveUpdateState(-abs(Panel_inst[0].ObjectState));
   if(Panel_wstate[0][NewState]==1)       Panel_inst[0].selectiveUpdateState(abs(Panel_inst[0].ObjectState));
   if(Circle_wstate[0][NewState]==1)       Circle_inst[0].selectiveUpdateState(abs(Circle_inst[0].ObjectState));
   if(Line_wstate[0][NewState]==1)       Line_inst[0].selectiveUpdateState(abs(Line_inst[0].ObjectState));
   if(Bar_Fill_Vert_wstate[0][NewState]==1)       Bar_Fill_Vert_inst[0].selectiveUpdateState(abs(Bar_Fill_Vert_inst[0].ObjectState));
   if(Horizontal_Progress_wstate[0][NewState]==1)       Horizontal_Progress_inst[0].selectiveUpdateState(abs(Horizontal_Progress_inst[0].ObjectState));
   if(Label_wstate[0][NewState]==1)       Label_inst[0].selectiveUpdateState(abs(Label_inst[0].ObjectState));
   if(Push_Button_wstate[0][NewState]==1)       Push_Button_inst[0].selectiveUpdateState(abs(Push_Button_inst[0].ObjectState));
   if(Push_Button_wstate[1][NewState]==1)       Push_Button_inst[1].selectiveUpdateState(abs(Push_Button_inst[1].ObjectState));
   if(Radio_Button_wstate[0][NewState]==1)       Radio_Button_inst[0].selectiveUpdateState(abs(Radio_Button_inst[0].ObjectState));
   if(Side_Toggle_wstate[0][NewState]==1)       Side_Toggle_inst[0].selectiveUpdateState(abs(Side_Toggle_inst[0].ObjectState));
   if(Toggle_Button_wstate[0][NewState]==1)       Toggle_Button_inst[0].selectiveUpdateState(abs(Toggle_Button_inst[0].ObjectState));
}

int TestAllGen::clickChecker()
{
     if (tft->touched())
     {
         uint16_t RawX;
         uint16_t RawY;
         if (tft->touched())
         {
             tft->touchRead(&RawX,&RawY);
             //calibrate the point first, if the screen has registered a touch
             long clickX = ( (326400 * RawX) + (2880 * RawY) + -323775840) / -373338 ;
             long clickY = ( (-1152 * RawX) + (210816 * RawY) + -195031008) / -373338 ;
             //using the calibrated point, check through all visible objects to see if one encompasses the point
             for (int i=0;i<1;i++)
                 if (Toggle_Button_inst[i].ObjectState>0&&Toggle_Button_inst[i].XPos<clickX&&Toggle_Button_inst[i].YPos<clickY&&Toggle_Button_inst[i].XPos+Toggle_Button_inst[i].clickWidth>clickX&&Toggle_Button_inst[i].YPos+Toggle_Button_inst[i].clickHeight>clickY)
                     return Toggle_Button_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Side_Toggle_inst[i].ObjectState>0&&Side_Toggle_inst[i].XPos<clickX&&Side_Toggle_inst[i].YPos<clickY&&Side_Toggle_inst[i].XPos+Side_Toggle_inst[i].clickWidth>clickX&&Side_Toggle_inst[i].YPos+Side_Toggle_inst[i].clickHeight>clickY)
                     return Side_Toggle_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Radio_Button_inst[i].ObjectState>0&&Radio_Button_inst[i].XPos<clickX&&Radio_Button_inst[i].YPos<clickY&&Radio_Button_inst[i].XPos+Radio_Button_inst[i].clickWidth>clickX&&Radio_Button_inst[i].YPos+Radio_Button_inst[i].clickHeight>clickY)
                     return Radio_Button_inst[i].UID;
             for (int i=0;i<2;i++)
                 if (Push_Button_inst[i].ObjectState>0&&Push_Button_inst[i].XPos<clickX&&Push_Button_inst[i].YPos<clickY&&Push_Button_inst[i].XPos+Push_Button_inst[i].clickWidth>clickX&&Push_Button_inst[i].YPos+Push_Button_inst[i].clickHeight>clickY)
                     return Push_Button_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Label_inst[i].ObjectState>0&&Label_inst[i].XPos<clickX&&Label_inst[i].YPos<clickY&&Label_inst[i].XPos+Label_inst[i].clickWidth>clickX&&Label_inst[i].YPos+Label_inst[i].clickHeight>clickY)
                     return Label_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Horizontal_Progress_inst[i].ObjectState>0&&Horizontal_Progress_inst[i].XPos<clickX&&Horizontal_Progress_inst[i].YPos<clickY&&Horizontal_Progress_inst[i].XPos+Horizontal_Progress_inst[i].clickWidth>clickX&&Horizontal_Progress_inst[i].YPos+Horizontal_Progress_inst[i].clickHeight>clickY)
                     return Horizontal_Progress_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Bar_Fill_Vert_inst[i].ObjectState>0&&Bar_Fill_Vert_inst[i].XPos<clickX&&Bar_Fill_Vert_inst[i].YPos<clickY&&Bar_Fill_Vert_inst[i].XPos+Bar_Fill_Vert_inst[i].clickWidth>clickX&&Bar_Fill_Vert_inst[i].YPos+Bar_Fill_Vert_inst[i].clickHeight>clickY)
                     return Bar_Fill_Vert_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Line_inst[i].ObjectState>0&&Line_inst[i].XPos<clickX&&Line_inst[i].YPos<clickY&&Line_inst[i].XPos+Line_inst[i].clickWidth>clickX&&Line_inst[i].YPos+Line_inst[i].clickHeight>clickY)
                     return Line_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Circle_inst[i].ObjectState>0&&Circle_inst[i].XPos<clickX&&Circle_inst[i].YPos<clickY&&Circle_inst[i].XPos+Circle_inst[i].clickWidth>clickX&&Circle_inst[i].YPos+Circle_inst[i].clickHeight>clickY)
                     return Circle_inst[i].UID;
             for (int i=0;i<1;i++)
                 if (Panel_inst[i].ObjectState>0&&Panel_inst[i].XPos<clickX&&Panel_inst[i].YPos<clickY&&Panel_inst[i].XPos+Panel_inst[i].clickWidth>clickX&&Panel_inst[i].YPos+Panel_inst[i].clickHeight>clickY)
                     return Panel_inst[i].UID;
             return 0;
         }
         else
         {
             tft->touchRead(&RawX,&RawY);
             return 0;
         }
     }
     else
         return 0;
}


