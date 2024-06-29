#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& rhs);
    static Date LocalTime();
    friend ostream& operator<<(ostream& outp__, const Date& date__);
    friend ostream& operator>>(istream& intp__, const Date& date__);
    int GetDay();
    int GetMonth();
    int GetYear();
    void SetDay(int newDay);
    void SetMonth(int newMonth);
    void SetYear(int newYear);
    string ToString();
    Date operator+(int rhs) const;
    Date operator-(int rhs) const;
    int operator-(const Date& rhs) const;
    Date& operator+=(int rhs);
    Date& operator-=(int rhs);
    bool operator!=(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;
    Date& operator=(const Date& rhs);
    ~Date();
private:
    int GetFromBegin() const;
    bool AddDay(int& day);
    bool AddMonth(int& day);
    bool AddYear(int& day);
    bool SubYear(int& day);
    bool SubMonth(int& day);
    bool SubDay(int& day);
    bool IsLeapYear(int year = -1) const;
    const unsigned char day_count[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d, m, y;
};


#endif // DATE_H
