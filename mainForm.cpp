//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

double DistanceOfTwoPoints(double lat1, double lng1, double lat2, double lng2)
{
    double radLng1 = lng1 * M_PI / 180.0;
    double radLng2 = lng2 * M_PI / 180.0;
    double a = radLng1 - radLng2;
    double b = (lat1-lat2) * M_PI / 180.0;
    double s = 2 * asin(sqrt(pow(sin(a/2), 2) +
        cos(radLng1) * cos(radLng2) * pow(sin(b/2), 2)))* 6378.137;
    s =s * 10000 / 10000;



    return s;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x1,y1,x2,y2;
    x1 = StrToFloat(Edit1->Text);
    y1 = StrToFloat(Edit2->Text);
    x2 = StrToFloat(Edit3->Text);
    y2 = StrToFloat(Edit4->Text);
    Edit5->Text = FloatToStr(DistanceOfTwoPoints(x1,y1,x2,y2));
}
//---------------------------------------------------------------------------
