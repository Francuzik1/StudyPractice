#ifndef COMNUM_H
#define COMNUM_H

#include <QString>
class ComNum
{
private:
    double Re;
    double Im;
public:
    ComNum();
    ComNum(double re, double im);
    double GetRe();
    double GetIm();
    double GetDeg();
    double GetMax();
    void SetRe(double newRe);
    void SetIm(double newIm);
    QString ShowLikeQStr();
    QString ShowDegreeLikeQStr();
};

#endif // COMNUM_H
