#ifndef CALCULATEPOLSKA_H
#define CALCULATEPOLSKA_H
#include <string>
using namespace std;
string GetStringNumber(string expr, int & pos);
double Execute(char op, double first, double second);
double CalculatePolskaZapis(string postfixExpr);
#endif // CALCULATEPOLSKA_H
