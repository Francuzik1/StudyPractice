#include "comnum.h"
#include "math.h"
#include "stdlib.h"

ComNum::ComNum()
{
    Re = 0;
    Im = 0;
}

ComNum::ComNum(double re, double im)
{
    Re = round(re*100)/100;
    Im = round(im*100)/100;
}

double ComNum::GetRe()
{
    return Re;
}

double ComNum::GetIm()
{
    return Im;
}

double ComNum::GetDeg()
{
    double degrees;
    if(Re != 0 && Im != 0)
    {
        degrees = 180.0*atan(Im/Re)/M_PI;
        if (degrees < 0)
            degrees += 360;
    }
    else if(Im == 0 && Re !=0)
    {
        if (Re > 0)
            degrees = 0;
        else
            degrees = 180;
    }
    else if(Im != 0 && Re == 0)
    {
        if (Im >0)
            degrees = 90;
        else
            degrees = 270;
    }
    else
    {
        degrees = 361;
    }
    degrees = round(degrees*100)/100;
    return degrees;
}

double ComNum::GetMax()
{
    if (abs(Im) > abs(Re))
        return abs(Im);
    else
        return abs(Re);
}

void ComNum::SetIm(double newIm)
{
    Im = round(newIm*100)/100;
}

void ComNum::SetRe(double newRe)
{
    Re = round(newRe*100)/100;
}

QString ComNum::ShowDegreeLikeQStr()
{
    if (GetDeg() != 361)
        return QString::number(GetDeg()) + "°";
    else
        return QString("Не определен");
}

QString ComNum::ShowLikeQStr()
{
    QString num;
    if (Re == 0 && Im == 0)
        return QString("0");
    else
    {
        if(Re != 0)
        {
            num += QString::number(Re);
        }
        if (Im != 0)
        {
            if(Re != 0 && Im > 0)
                num += "+";
            num += QString::number(Im) + "i";
        }
    }
    return num;
}

ComNum operator + (ComNum& n1, ComNum& n2)
{
    return ComNum{n1.GetRe() + n2.GetRe(), n1.GetIm() + n2.GetIm()};
}

ComNum operator - (ComNum& n1, ComNum& n2)
{
    return ComNum{n1.GetRe() - n2.GetRe(), n1.GetIm() - n2.GetIm()};
}

