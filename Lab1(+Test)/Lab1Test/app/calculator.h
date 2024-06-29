#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once

class Calculator
{
public:
    Calculator();

    double sum(double a, double b) const;
    double dif(double a, double b) const;
    double mul(double a, double b) const;
    double div(double a, double b) const;
};


#endif // CALCULATOR_H
