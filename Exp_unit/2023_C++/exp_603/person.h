#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>
#include <string.h>

using namespace std;

class person
{
protected:
    char name[11];
    char sex[2];
    date birthday;

public:
    person(void); // 无参构造函数
    void set_person(char *na, char *s, int y, int m, int d);
    char *get_name(void)
    {
        return name;
    } // 完成成员函数的定义
    char *get_sex(void)
    {
        return sex;
    } // 完成成员函数的定义
    int get_year(void)
    {
        return birthday.get_year();
    } // 完成成员函数的定义
    int get_month(void)
    {
        return birthday.get_month();
    }
    int get_day(void)
    {
        return birthday.get_day();
    } // 完成成员函数的定义
    void print(void);
};

person::person(void) // 无参构造函数
{
    strcpy(name, "无名氏");
    strcpy(sex, "男");
    birthday.set_date(1980, 1, 1);
}

void person::set_person(char *na, char *s, int y, int m, int d)
{
    strcpy(this->name, na);
    strcpy(this->sex, s);
    birthday.set_date(y, m, d);
} // 完成成员函数的定义

void person::print(void)
{
    cout << "姓名:" << name << endl;
    cout << "性别:" << sex << endl;
    cout << "出生日期:" << birthday.get_year() << "年";
    cout << birthday.get_month() << "月";
    cout << birthday.get_day() << "日" << endl;
}

#endif