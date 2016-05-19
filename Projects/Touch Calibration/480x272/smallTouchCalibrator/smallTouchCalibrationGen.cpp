#include "smallTouchCalibrationGen.h"
//Automatically generated code file by G2

//Basic Init function
void smallTouchCalibrationGen::initTFT(G2bAdaFruitRA8875* tft2, int DefaultState)
{
    tft=tft2;
    tft->fillScreen(65535);
    initObjects();
    stateUpdateObjects(DefaultState);
}

int smallTouchCalibrationGen::displayScan()
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
             if (prevClickID>0)
                 ReturnID=clickHandler(-prevClickID);
             else
                 if (ClickID==-1)
                     ReturnID=-1;
         prevClickID=ClickID;
         if (ReturnID!=0)
             return ReturnID;
     }
     confirmClickID=ClickID;
     return variableScan();
}

int smallTouchCalibrationGen::clickHandler(int objUID)
{
    switch (objUID){
    //unclick commands are indexed by the -ve UID for simplicity
    }
    return 0;
}

//variable change handler, performs display/general functions when a display variable is changed
int smallTouchCalibrationGen::variableScan()
{
   if (PointIndex!=PointIndex_prev)
   {
         PointIndex_prev=PointIndex;
         if (PointIndex==1) {Label_inst[0].Text="X"+String(Indicator_Light_inst[0].XPos+Indicator_Light_inst[0].Width/2)+" Y"+String(Indicator_Light_inst[0].YPos+Indicator_Light_inst[0].Width/2);
         Label_inst[0].drawByState();
         Label_inst[1].Text="X"+String(Indicator_Light_inst[1].XPos+Indicator_Light_inst[1].Width/2)+" Y"+String(Indicator_Light_inst[1].YPos+Indicator_Light_inst[1].Width/2);
         Label_inst[1].drawByState();
         Label_inst[2].Text="X"+String(Indicator_Light_inst[2].XPos+Indicator_Light_inst[2].Width/2)+" Y"+String(Indicator_Light_inst[2].YPos+Indicator_Light_inst[2].Width/2);
         Label_inst[2].drawByState();
         Indicator_Light_inst[0].selectiveUpdateState(3);
         } if (PointIndex==2) {Indicator_Light_inst[0].selectiveUpdateState(1);
         Indicator_Light_inst[1].selectiveUpdateState(3);
         } if (PointIndex==3) {Indicator_Light_inst[1].selectiveUpdateState(1);
         Indicator_Light_inst[2].selectiveUpdateState(3);
         } if (PointIndex==4){ Indicator_Light_inst[2].selectiveUpdateState(1);
         PointIndex=0;
         };
   }
   if (Y1!=Y1_prev)
   {
         Y1_prev=Y1;
         Label_inst[3].Text="X"+String(X1)+" Y"+String(Y1);
         Label_inst[3].drawByState();
   }
   if (Y2!=Y2_prev)
   {
         Y2_prev=Y2;
         Label_inst[4].Text="X"+String(X2)+" Y"+String(Y2);
         Label_inst[4].drawByState();
   }
   if (Y3!=Y3_prev)
   {
         Y3_prev=Y3;
         Label_inst[5].Text="X"+String(X3)+" Y"+String(Y3);
         Label_inst[5].drawByState();
   }
     return 0;
}

void smallTouchCalibrationGen::initObjects()
{
  Indicator_Light_inst[0].ltft=tft;
  Indicator_Light_inst[0].ObjectState=-2;
  Indicator_Light_inst[0].UName="Indicator_Light_1";
  Indicator_Light_inst[0].UID=1;
  Indicator_Light_inst[0].XPos=32;
  Indicator_Light_inst[0].YPos=32;
  Indicator_Light_inst[0].clickWidth=0;
  Indicator_Light_inst[0].clickHeight=0;
  Indicator_Light_inst[0].Width=16;
  Indicator_Light_inst[0].Height=16;
  Indicator_Light_inst[0].OnColor=21824;
  Indicator_Light_inst[0].OffColor=63488;
  Indicator_Light_inst[0].DisabledColor=65504;
  Indicator_Light_inst[0].Background=65535;
  Indicator_Light_inst[0].drawByState();
  Indicator_Light_wstate[0][0]=1;
  Indicator_Light_inst[1].ltft=tft;
  Indicator_Light_inst[1].ObjectState=-2;
  Indicator_Light_inst[1].UName="Indicator_Light_2";
  Indicator_Light_inst[1].UID=2;
  Indicator_Light_inst[1].XPos=232;
  Indicator_Light_inst[1].YPos=234;
  Indicator_Light_inst[1].clickWidth=0;
  Indicator_Light_inst[1].clickHeight=0;
  Indicator_Light_inst[1].Width=16;
  Indicator_Light_inst[1].Height=16;
  Indicator_Light_inst[1].OnColor=21824;
  Indicator_Light_inst[1].OffColor=63488;
  Indicator_Light_inst[1].DisabledColor=65504;
  Indicator_Light_inst[1].Background=65535;
  Indicator_Light_inst[1].drawByState();
  Indicator_Light_wstate[1][0]=1;
  Indicator_Light_inst[2].ltft=tft;
  Indicator_Light_inst[2].ObjectState=-2;
  Indicator_Light_inst[2].UName="Indicator_Light_3";
  Indicator_Light_inst[2].UID=3;
  Indicator_Light_inst[2].XPos=442;
  Indicator_Light_inst[2].YPos=128;
  Indicator_Light_inst[2].clickWidth=0;
  Indicator_Light_inst[2].clickHeight=0;
  Indicator_Light_inst[2].Width=16;
  Indicator_Light_inst[2].Height=16;
  Indicator_Light_inst[2].OnColor=21824;
  Indicator_Light_inst[2].OffColor=63488;
  Indicator_Light_inst[2].DisabledColor=65504;
  Indicator_Light_inst[2].Background=65535;
  Indicator_Light_inst[2].drawByState();
  Indicator_Light_wstate[2][0]=1;
  Label_inst[0].ltft=tft;
  Label_inst[0].ObjectState=-1;
  Label_inst[0].UName="LblPt1";
  Label_inst[0].UID=4;
  Label_inst[0].XPos=5;
  Label_inst[0].YPos=80;
  Label_inst[0].clickWidth=0;
  Label_inst[0].clickHeight=0;
  Label_inst[0].Width=100;
  Label_inst[0].Height=24;
  Label_inst[0].TextEnlarge=0;
  Label_inst[0].TextColor=0;
  Label_inst[0].Background=65535;
  Label_inst[0].TextJustification=1;
  Label_inst[0].Text="Screen Point";
  Label_inst[0].FontName=NULL;
  Label_inst[0].drawByState();
  Label_wstate[0][0]=1;
  Label_inst[1].ltft=tft;
  Label_inst[1].ObjectState=-1;
  Label_inst[1].UName="LblPt2";
  Label_inst[1].UID=5;
  Label_inst[1].XPos=185;
  Label_inst[1].YPos=178;
  Label_inst[1].clickWidth=0;
  Label_inst[1].clickHeight=0;
  Label_inst[1].Width=100;
  Label_inst[1].Height=24;
  Label_inst[1].TextEnlarge=0;
  Label_inst[1].TextColor=0;
  Label_inst[1].Background=65535;
  Label_inst[1].TextJustification=1;
  Label_inst[1].Text="Screen Point";
  Label_inst[1].FontName=NULL;
  Label_inst[1].drawByState();
  Label_wstate[1][0]=1;
  Label_inst[2].ltft=tft;
  Label_inst[2].ObjectState=-1;
  Label_inst[2].UName="LblPt3";
  Label_inst[2].UID=6;
  Label_inst[2].XPos=375;
  Label_inst[2].YPos=149;
  Label_inst[2].clickWidth=0;
  Label_inst[2].clickHeight=0;
  Label_inst[2].Width=100;
  Label_inst[2].Height=24;
  Label_inst[2].TextEnlarge=0;
  Label_inst[2].TextColor=0;
  Label_inst[2].Background=65535;
  Label_inst[2].TextJustification=1;
  Label_inst[2].Text="Screen Point";
  Label_inst[2].FontName=NULL;
  Label_inst[2].drawByState();
  Label_wstate[2][0]=1;
  Label_inst[3].ltft=tft;
  Label_inst[3].ObjectState=-1;
  Label_inst[3].UName="LblTp1";
  Label_inst[3].UID=9;
  Label_inst[3].XPos=4;
  Label_inst[3].YPos=104;
  Label_inst[3].clickWidth=100;
  Label_inst[3].clickHeight=24;
  Label_inst[3].Width=100;
  Label_inst[3].Height=24;
  Label_inst[3].TextEnlarge=0;
  Label_inst[3].TextColor=0;
  Label_inst[3].Background=65535;
  Label_inst[3].TextJustification=1;
  Label_inst[3].Text="Touch Point";
  Label_inst[3].FontName=NULL;
  Label_inst[3].drawByState();
  Label_wstate[3][0]=1;
  Label_inst[4].ltft=tft;
  Label_inst[4].ObjectState=-1;
  Label_inst[4].UName="LblTp2";
  Label_inst[4].UID=10;
  Label_inst[4].XPos=183;
  Label_inst[4].YPos=201;
  Label_inst[4].clickWidth=100;
  Label_inst[4].clickHeight=24;
  Label_inst[4].Width=100;
  Label_inst[4].Height=24;
  Label_inst[4].TextEnlarge=0;
  Label_inst[4].TextColor=0;
  Label_inst[4].Background=65535;
  Label_inst[4].TextJustification=1;
  Label_inst[4].Text="Touch Point";
  Label_inst[4].FontName=NULL;
  Label_inst[4].drawByState();
  Label_wstate[4][0]=1;
  Label_inst[5].ltft=tft;
  Label_inst[5].ObjectState=-1;
  Label_inst[5].UName="LblTp3";
  Label_inst[5].UID=11;
  Label_inst[5].XPos=375;
  Label_inst[5].YPos=176;
  Label_inst[5].clickWidth=100;
  Label_inst[5].clickHeight=24;
  Label_inst[5].Width=100;
  Label_inst[5].Height=24;
  Label_inst[5].TextEnlarge=0;
  Label_inst[5].TextColor=0;
  Label_inst[5].Background=65535;
  Label_inst[5].TextJustification=1;
  Label_inst[5].Text="Touch Point";
  Label_inst[5].FontName=NULL;
  Label_inst[5].drawByState();
  Label_wstate[5][0]=1;
  Label_inst[6].ltft=tft;
  Label_inst[6].ObjectState=-1;
  Label_inst[6].UName="Label_12";
  Label_inst[6].UID=12;
  Label_inst[6].XPos=72;
  Label_inst[6].YPos=7;
  Label_inst[6].clickWidth=0;
  Label_inst[6].clickHeight=0;
  Label_inst[6].Width=400;
  Label_inst[6].Height=24;
  Label_inst[6].TextEnlarge=0;
  Label_inst[6].TextColor=0;
  Label_inst[6].Background=65535;
  Label_inst[6].TextJustification=1;
  Label_inst[6].Text="Tap Dots as they turn Yellow";
  Label_inst[6].FontName=NULL;
  Label_inst[6].drawByState();
  Label_wstate[6][0]=1;
  Label_inst[7].ltft=tft;
  Label_inst[7].ObjectState=-1;
  Label_inst[7].UName="Label_13";
  Label_inst[7].UID=13;
  Label_inst[7].XPos=72;
  Label_inst[7].YPos=33;
  Label_inst[7].clickWidth=0;
  Label_inst[7].clickHeight=0;
  Label_inst[7].Width=400;
  Label_inst[7].Height=24;
  Label_inst[7].TextEnlarge=0;
  Label_inst[7].TextColor=0;
  Label_inst[7].Background=65535;
  Label_inst[7].TextJustification=1;
  Label_inst[7].Text="Tap screen to begin or repeat";
  Label_inst[7].FontName=NULL;
  Label_inst[7].drawByState();
  Label_wstate[7][0]=1;
  Label_inst[8].ltft=tft;
  Label_inst[8].ObjectState=-1;
  Label_inst[8].UName="Label_14";
  Label_inst[8].UID=14;
  Label_inst[8].XPos=76;
  Label_inst[8].YPos=57;
  Label_inst[8].clickWidth=100;
  Label_inst[8].clickHeight=24;
  Label_inst[8].Width=400;
  Label_inst[8].Height=24;
  Label_inst[8].TextEnlarge=0;
  Label_inst[8].TextColor=0;
  Label_inst[8].Background=65535;
  Label_inst[8].TextJustification=1;
  Label_inst[8].Text="Enter data into G2 hardware configuration and save";
  Label_inst[8].FontName=NULL;
  Label_inst[8].drawByState();
  Label_wstate[8][0]=1;
}

void smallTouchCalibrationGen::stateUpdateObjects(int NewState)
{
   if(Label_wstate[0][NewState]==0)       Label_inst[0].selectiveUpdateState(-abs(Label_inst[0].ObjectState));
   if(Label_wstate[1][NewState]==0)       Label_inst[1].selectiveUpdateState(-abs(Label_inst[1].ObjectState));
   if(Label_wstate[2][NewState]==0)       Label_inst[2].selectiveUpdateState(-abs(Label_inst[2].ObjectState));
   if(Label_wstate[3][NewState]==0)       Label_inst[3].selectiveUpdateState(-abs(Label_inst[3].ObjectState));
   if(Label_wstate[4][NewState]==0)       Label_inst[4].selectiveUpdateState(-abs(Label_inst[4].ObjectState));
   if(Label_wstate[5][NewState]==0)       Label_inst[5].selectiveUpdateState(-abs(Label_inst[5].ObjectState));
   if(Label_wstate[6][NewState]==0)       Label_inst[6].selectiveUpdateState(-abs(Label_inst[6].ObjectState));
   if(Label_wstate[7][NewState]==0)       Label_inst[7].selectiveUpdateState(-abs(Label_inst[7].ObjectState));
   if(Label_wstate[8][NewState]==0)       Label_inst[8].selectiveUpdateState(-abs(Label_inst[8].ObjectState));
   if(Indicator_Light_wstate[0][NewState]==0)       Indicator_Light_inst[0].selectiveUpdateState(-abs(Indicator_Light_inst[0].ObjectState));
   if(Indicator_Light_wstate[1][NewState]==0)       Indicator_Light_inst[1].selectiveUpdateState(-abs(Indicator_Light_inst[1].ObjectState));
   if(Indicator_Light_wstate[2][NewState]==0)       Indicator_Light_inst[2].selectiveUpdateState(-abs(Indicator_Light_inst[2].ObjectState));
   if(Indicator_Light_wstate[0][NewState]==1)       Indicator_Light_inst[0].selectiveUpdateState(abs(Indicator_Light_inst[0].ObjectState));
   if(Indicator_Light_wstate[1][NewState]==1)       Indicator_Light_inst[1].selectiveUpdateState(abs(Indicator_Light_inst[1].ObjectState));
   if(Indicator_Light_wstate[2][NewState]==1)       Indicator_Light_inst[2].selectiveUpdateState(abs(Indicator_Light_inst[2].ObjectState));
   if(Label_wstate[0][NewState]==1)       Label_inst[0].selectiveUpdateState(abs(Label_inst[0].ObjectState));
   if(Label_wstate[1][NewState]==1)       Label_inst[1].selectiveUpdateState(abs(Label_inst[1].ObjectState));
   if(Label_wstate[2][NewState]==1)       Label_inst[2].selectiveUpdateState(abs(Label_inst[2].ObjectState));
   if(Label_wstate[3][NewState]==1)       Label_inst[3].selectiveUpdateState(abs(Label_inst[3].ObjectState));
   if(Label_wstate[4][NewState]==1)       Label_inst[4].selectiveUpdateState(abs(Label_inst[4].ObjectState));
   if(Label_wstate[5][NewState]==1)       Label_inst[5].selectiveUpdateState(abs(Label_inst[5].ObjectState));
   if(Label_wstate[6][NewState]==1)       Label_inst[6].selectiveUpdateState(abs(Label_inst[6].ObjectState));
   if(Label_wstate[7][NewState]==1)       Label_inst[7].selectiveUpdateState(abs(Label_inst[7].ObjectState));
   if(Label_wstate[8][NewState]==1)       Label_inst[8].selectiveUpdateState(abs(Label_inst[8].ObjectState));
}

int smallTouchCalibrationGen::clickChecker()
{
     if (tft->touched())
     {
         uint16_t RawX;
         uint16_t RawY;
         //if (tft->touched())
         //{
             tft->touchRead(&RawX,&RawY);
             //calibrate the point first, if the screen has registered a touch
             long clickX = ( (326400 * RawX) + (2880 * RawY) + -323775840) / -373338 ;
             long clickY = ( (-1152 * RawX) + (210816 * RawY) + -195031008) / -373338 ;
             //using the calibrated point, check through all visible objects to see if one encompasses the point
             for (int i=0;i<9;i++)
                 if (Label_inst[i].ObjectState>0&&Label_inst[i].XPos<clickX&&Label_inst[i].YPos<clickY&&Label_inst[i].XPos+Label_inst[i].clickWidth>clickX&&Label_inst[i].YPos+Label_inst[i].clickHeight>clickY)
                     return Label_inst[i].UID;
             for (int i=0;i<3;i++)
                 if (Indicator_Light_inst[i].ObjectState>0&&Indicator_Light_inst[i].XPos<clickX&&Indicator_Light_inst[i].YPos<clickY&&Indicator_Light_inst[i].XPos+Indicator_Light_inst[i].clickWidth>clickX&&Indicator_Light_inst[i].YPos+Indicator_Light_inst[i].clickHeight>clickY)
                     return Indicator_Light_inst[i].UID;
             return -1;
         //}
         //else
         //{
         //    tft->touchRead(&RawX,&RawY);
         //    return 0;
         //}
     }
     else
         return 0;
}


