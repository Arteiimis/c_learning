#ifndef SCORE_H
#define SCORE_H

#include "student.h"
const int M = 10;
class score : public student
{
private:
    float sc[M], aver;
    int m;

public:
    score(void);                      // 无参构造函数
    void set_score(float x[], int n); // 提供成绩
    float get_score(int i)            // 得到第i科成绩
    {
        return sc[i];
    }                    // 完成成员函数的定义
    float get_aver(void) // 得到平均成绩
    {
        return aver;
    } // 完成成员函数的定义
    void print(void);
    void print_score(void);
};

score::score(void) // 无参构造函数
{
    strcpy(name, "无名氏");
    strcpy(sex, "男");
    birthday.set_date(1980, 1, 1);
    id = 0;
    strcpy(department, "计算机");
    enterdate.set_date(2000, 9, 1);
    int i;
    m = M;
    for (i = 0; i < m; i++)
        sc[i] = 0;
    aver = 0;
}

void score::set_score(float x[], int n) // 提供成绩:完成成员函数的定义
{
    int i;
    float sum = 0;
    m = n;
    for (i = 0; i < m; i++)
    {
        sc[i] = x[i];
        sum += x[i];
    }
    aver = sum / m;
}

void score::print(void) // 重载输出print()
{
    student::print();
    int i;
    for (i = 0; i < m; i++)
        cout << "  " << sc[i];
    cout << "  " << aver << endl;
}

void score::print_score(void)
{
    int j;
    cout << setw(8) << get_id();
    cout << setw(12) << get_name();
    for (j = 0; j < m; j++)
        cout << setw(6) << get_score(j);
    cout << " " << setw(6) << get_aver() << endl;
}

#endif