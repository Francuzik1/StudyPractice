#include "date.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Date::Date()
{
    d = 0; m = 0; y = 0;
}
Date::Date(int n_d, int n_m, int n_y)
{
    d = n_d; m = n_m; y = n_y;
}
Date::Date(const Date& rhs)  // Вывод даты сейчас дд.мм.гггг
{
    d = rhs.d; m = rhs.m; y = rhs.y;
}
Date Date::operator +(int day) const
{
    if (day < 0)
        return *this - (-day);
    Date NewDate(*this);
    while (NewDate.AddYear(day));
    while (NewDate.AddMonth(day));
    while (NewDate.AddDay(day));
    return NewDate;
}
Date Date::operator-(int day) const
{ if (day < 0)
        return *this + (-day);
    Date NewDate(*this);
    while (NewDate.SubYear(day));
    while (NewDate.SubMonth(day));
    while (NewDate.SubDay(day));
    return NewDate;
}
int Date::operator-(const Date& rhs) const
{
    return this->GetFromBegin() - rhs.GetFromBegin();
}
Date& Date::operator+=(int rhs)
{
    Date NewDate = *this + rhs; return NewDate;
}
Date& Date::operator-=(int rhs)
{
    Date NewDate = *this - rhs; return NewDate;
}
bool Date::operator!=(const Date& rhs) const
{
    return !(*this == rhs);
}
bool Date::operator==(const Date& rhs) const
{
    return (this->d == rhs.d) && (this->m == rhs.m) && (this->y == rhs.y);
}
bool Date::operator<(const Date& rhs) const
{
    if (this->y == rhs.y)
    {
        if (this->m == rhs.m)
        {
            return this->d < rhs.d;
        }
        else
        {
            return this->m < rhs.m;
        }
    }
    else
    {
        return this->y < rhs.y;
    }
}
bool Date::operator<=(const Date& rhs) const //Не больше ли дата чем дата справа
{
    return (*this == rhs) || (*this < rhs);
}
bool Date::operator>(const Date& rhs) const // Больше ли дата чем дата справа
{
    if (this->y == rhs.y)
    {
        if (this->m == rhs.m)
        {
            return this->d > rhs.d;
        }
        else
        {
            return this->m > rhs.m;
        }
    }
    else
    {
        return this->y > rhs.y;
    }
}
bool Date::operator>=(const Date& rhs) const // Не меньше ли дата даты справа
{
    return (*this == rhs) || (*this > rhs);
}
Date& Date::operator=(const Date& rhs) // Присваивает данные даты справа искомой дате
{
    if (this == &rhs)
        return (*this);
    this->d = rhs.d;
    this->m = rhs.m;
    this->y = rhs.y;
    return (*this);
}
Date::~Date() // Деструктор с выводом информации о удалении даты
{
}

int Date::GetDay()
{
    return this->d;
}
int Date::GetMonth()
{
    return this->m;
}
int Date::GetYear()
{
    return this->y;
}
string Date::ToString()
{
    return (to_string(this->d) + "." + to_string(this->m) + "." + to_string(this->y));
}
void Date::SetDay(int newDay)
{
    this->d = newDay;
}
void Date::SetMonth(int newMonth)
{
    this->m = newMonth;
}
void Date::SetYear(int newYear)
{
    this->y = newYear;
}
int Date::GetFromBegin() const //Количество дней от 0 даты
{
    int days = 0;
    for (int i = 1; i < this->y; i++)
        days += 365 + int(IsLeapYear(i));
    for (int i = 1; i < this->m; i++)
        days += day_count[i - 1] + int((i == 2) && IsLeapYear());
    days += d;
    return days;
}

Date Date::LocalTime()
{
    time_t rawtime;
    tm* Time = new tm;
    time(&rawtime);
    localtime_s(Time, &rawtime);
    return Date(Time->tm_mday, Time->tm_mon + 1, Time->tm_year + 1900);
}

bool Date::AddDay(int& day) // Доабвить к дате число дней day
{
    if (day > 0)
    {
        day = day - 1;
        int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
        d = d + 1;
        if (d > day_cnt_in_this_mounth)
            d = 1, m = m + 1;
        if (m > 12)
            m = 1, y = y + 1;
        return true;
    }
    return false;
}
bool Date::AddMonth(int& day) // Добавить число меясцев к дате равное day
{
    while (d != 1 && AddDay(day));
    int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
    if (day >= day_cnt_in_this_mounth)
    {
        day = day - day_cnt_in_this_mounth;
        m = m + 1;
        if (m > 12)
            m = 1, y = y + 1;
        return true;
    } return false;
}
bool Date::AddYear(int& day)  // Добавить к дате day лет
{
    while (d != 1 && AddDay(day));
    while (m != 1 && AddMonth(day));
    int day_in_this_year = 365 + int(IsLeapYear());
    if (day >= day_in_this_year)
    {
        day = day - day_in_this_year;
        y = y + 1;
        return true;
    }
    return false;
}
bool Date::SubYear(int& day)
{
    while (d != day_count[m - 1] + int((m == 2) && IsLeapYear()) && SubDay(day));
    while (m != 12 && SubMonth(day));
    int day_in_this_year = 365 + int(IsLeapYear());
    if (day >= day_in_this_year)
    {
        day = day - day_in_this_year;
        y = y - 1;
        return true;
    }
    return false;
}
bool Date::SubMonth(int& day)
{
    while (d != day_count[m - 1] + int((m == 2) && IsLeapYear()) && SubDay(day));
    int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
    if (day >= day_cnt_in_this_mounth)
    {
        day = day - day_cnt_in_this_mounth;
        m = m - 1;
        if (m < 1)
            m = 12, y = y - 1;
        d = day_count[m - 1] + int((m == 2) && IsLeapYear());
        return true;
    }
    return false;
}
bool Date::SubDay(int& day)
{
    if (day > 0)
    {
        day = day - 1;
        d = d - 1;
        if (d < 1)
        {
            m = m - 1;
            if (m - 1 < 1)
                m = 12, y = y - 1;
            int day_cnt_in_month = day_count[m - 1] + int((m == 2) && IsLeapYear());
            d = day_cnt_in_month;
        } return true;
    }
    return false;
}
bool Date::IsLeapYear(int year) const // Проверка на високосный год
{
    if (year == -1)
        year = this->y;
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
ostream& operator<<(ostream& outp__, const Date& date__)
{
    outp__ << setw(2) << setfill('0') << date__.d << ".";
    outp__ << setw(2) << setfill('0') << date__.m << ".";
    outp__ << setw(4) << setfill('0') << date__.y;
    return outp__;
}
