#ifndef DATE_H
#define DATE_H
#include <bits/stdc++.h>

class date
{
private:
    int year, month, day; // 年、月、日三个私有成员
public:
    date(void)
    {
        year = 1980;
        month = 1;
        day = 1;
    }
    void set_date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    } // 完成成员函数的定义
    int get_year(void)
    {
        return year;
    } // 完成成员函数的定义
    int get_month(void)
    {
        return month;
    } // 完成成员函数的定义
    int get_day(void)
    {
        return day;
    } // 完成成员函数的定义
};

#endif