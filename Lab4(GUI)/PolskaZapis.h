#ifndef POLSKAZAPIS_H
#define POLSKAZAPIS_H
#include <string>
using namespace std;
bool find_digit(char s);
bool find_useless(char s);
bool isopen(char s);
bool isoperator(char s);
bool check(string s);
string transform(string s);
bool search_math_errors_open(string s);
bool search_math_errors_closed(string s);
bool no_operator(string s);
string clear_string(string s);
int what(string s);
double solve(string s);
bool two_operators(string s);
string getPolskaZapis(string string_first);
#endif // POLSKAZAPIS_H
