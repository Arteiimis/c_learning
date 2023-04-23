#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "date.h"

class student : public person
{
public:
    int id;
    char department[20];
    date enterdate;

public:
    student(void);
    void set_student(int n, char *s, int y, int m, int d);
    int get_id(void)
    {
        return id;
    } // 完成成员函数的定义
    char *get_department(void)
    {
        return department;
    } // 完成成员函数的定义
    int get_enteryear(void)
    {
        return enterdate.get_year();
    } // 完成成员函数的定义
    int get_entermonth(void)
    {
        return enterdate.get_month();
    } // 完成成员函数的定义
    int get_enterday(void)
    {
        return enterdate.get_day();
    } // 完成成员函数的定义
    void print(void);
    void print_base();
};

student::student(void)
{
    strcpy(name, "无名氏");
    strcpy(sex, "男");
    birthday.set_date(1980, 1, 1);
    id = 0;
    strcpy(department, "计算机");
    enterdate.set_date(2000, 9, 1);
}
void student::set_student(int n, char *s, int y, int m, int d)
// n、s、y、m、d分别为id、department、enterdate提供值
{
    id = n;
    strcpy(department, s);
    enterdate.set_date(y, m, d);
} // 完成成员函数的定义

void student::print(void)
{
    cout << "学号:" << id << endl;
    person::print();
    cout << "系(专业):" << department << endl;
    cout << "进校日期:" << enterdate.get_year() << "年";
    cout << enterdate.get_month() << "月";
    cout << enterdate.get_day() << "日" << endl;
}
void student::print_base()
{
    cout << setw(8) << get_id();
    cout << setw(12) << get_name();
    cout << setw(4) << get_sex();
    cout << setw(6) << get_year() << "-" << get_month() << "-" << get_day();
    cout << setw(20) << get_department();
    cout << setw(6) << get_enteryear() << "-" << get_entermonth();
    cout << "-" << get_enterday() << endl;
}

#endif