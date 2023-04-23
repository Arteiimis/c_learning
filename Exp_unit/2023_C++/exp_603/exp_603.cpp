#include <bits/stdc++.h>
#include "score.h"
using namespace std;

void input_base(score *p, int n);         // 学生基本数据输入
void input_score(score *p, int n, int m); // 学生成绩输入
void print_base(score *p, int n);         // 学生基本数据输出
void print_score(score *p, int n, int m); // 学生成绩输出
score &average(score *p, int n, int m);   // 普通函数：平均成绩计算
void sort(score *p, int n, int m);        // 普通函数：按平均成绩排序

int main()
{
    int n, m;
    cout << "学生人数：";
    cin >> n;
    cout << "考试科数：";
    cin >> m;
    score *p, aver;
    p = new score[n]; // 动态分配内存单元——动态数组
    if (p == NULL)
    {
        cout << "内存分配失败" << endl;
        return 0;
    }
    int ch;
    do
    {
        cout << "\n\n     请选择:\n";
        cout << "  1. 输入学生基本数据\n";
        cout << "  2. 输入学生成绩\n";
        cout << "  3. 计算课程平均成绩\n";
        cout << "  4. 输出学生基本数据\n";
        cout << "  5. 输出学生成绩\n";
        cout << "  6. 按平均成绩排序\n";
        cout << "  0. 退出\n";
        cout << "\n    输入你的选择:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            input_base(p, n);
            break;
        case 2:
            input_score(p, n, m);
            break;
        case 3:
            aver = average(p, n, m);
            break;
        case 4:
            print_base(p, n);
            break;
        case 5:
            print_score(p, n, m);
            aver.print_score();
            break;
        case 6:
            sort(p, n, m);
            break;
        case 0:
            break;
        }
    } while (ch);
    delete[] p; // 释放内存
}
void input_base(score *p, int n) // 学生基本数据输入
{
    int i, id, y1, m1, d1, y2, m2, d2;
    char name[11], sex[3], dpt[20];
    cout << "\n  请输入学生基本数据:";
    for (i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "个学生:\n";
        cout << "学号:";
        cin >> id;
        cout << "姓名:";
        cin >> name;
        cout << "性别:";
        cin >> sex;
        cout << "出生年:";
        cin >> y1;
        cout << "出生月:";
        cin >> m1;
        cout << "出生日:";
        cin >> d1;
        cout << "所在系:";
        cin >> dpt;
        cout << "入学年:";
        cin >> y2;
        cout << "入学月:";
        cin >> m2;
        cout << "入学日:";
        cin >> d2;
        p[i].set_person(name, sex, y1, m1, d1);  // 完成函数的调用
        p[i].set_student(id, sex, y2, m2, d2); // 完成函数的调用
    }
}
void input_score(score *p, int n, int m)
{
    int i, j;
    float x[M];
    for (i = 0; i < n; i++)
    {
        cout << p[i].get_id() << p[i].get_name() << "的成绩：" << endl;
        for (j = 0; j < m; j++)
        {
            cout << "第" << j + 1 << "科成绩：";
            cin >> x[j];
        }
        p[i].set_score(); // 完成函数的调用
    }
}
void print_base(score *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
        p[i].print_base();
    cout << endl;
}
void print_score(score *p, int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
        p[i].print_score();
}
score &average(score *p, int n, int m) // 用返回引用的方法
{
    int i, j;
    float s[M] = {0};
    static score aver; // 返回的对象必须是静态的
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
            s[j] = s[j] + p[i].get_score(j);
        s[j] = s[j] / n;
    }
    aver.set_person("平均成绩", " ", 0, 0, 0);
    aver.set_score(); // 完成函数的调用
    return aver;
}
void sort(score *p, int n, int m) // 选择法排序：完成空白处的内容
{
    score t;
    float a;
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        a = p[i].get_aver();
        k = i;
        for (j = i + 1; j < n; j++)
            if ()
            {
                a = p[j].get_aver();
                k = j;
            }
        if ()
        {
            t = p[i];
            p[i] = p[k];
            p[k] = t;
        }
    }
}
