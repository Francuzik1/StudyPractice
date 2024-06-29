#include <stack>
#include <string>
#include <windows.h>
#include <math.h>
#include "CalculatePolska.h"
using namespace std;

stack<double> locals;
int counter = 0;

string GetStringNumber(string expr, int & pos)
{
    string strNumber = "";
    for (; pos < expr.length(); pos++)
    {
        char num = expr[pos];
        if (isdigit(num))
            strNumber += num;
        else
        {
            pos--;
            break;
        }
    }
    return strNumber;
}

double Execute(char op, double first, double second)
{
    switch (op)
    {
        case('+'): return first + second;
        case('-'): return first - second;
        case('*'): return first * second;
        case('/'): return first / second;
        case('^'): return pow(first, second);
    };
    return 0;
}


double CalculatePolskaZapis(string postfixExpr)
{
    for (int i = 0; i < postfixExpr.length(); i++)
    {
        char c = postfixExpr[i];
        if (isdigit(c))
        {
            string number = GetStringNumber(postfixExpr, i);
            locals.push(stod(number));
        }
        else if (c=='+' or c=='-' or c=='*' or c=='/' or c=='^')
        {
            counter += 1;
            double second = !locals.empty() ? locals.top() : 0;
            locals.pop();
            double first  = !locals.empty() ? locals.top() : 0;
            locals.pop();
            locals.push(Execute(c, first, second));
        }
    }
    double result = locals.top();
    locals.pop();
    return result;
}
