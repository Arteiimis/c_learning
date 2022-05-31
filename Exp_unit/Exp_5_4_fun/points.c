//从键盘输入10个学生的某门课的成绩，调用函数1求平均成绩，再调用函数2输出不及格的成绩和人数。

#include <stdio.h>
int aver(int *point);
int unpass(int *point);

void main() 
{
    int point[10];
    for(int i = 0; i <= 10; i++)
        scanf("%d", &point[i]);
    int sum = aver(point);
    int un_pass = unpass(point);

    printf("十人平均成绩为：%d\n", sum);
    printf("不及格人数为：%d\n", un_pass);

    return;
}

int aver(int *point)
{
    int i, sum = 0;
    for (i = 0; i < 10; i++)
        sum += point[i];
    
    return sum / 10;
}

int unpass(int *point)
{
    int i, sum = 0;
    for (i = 0; i < 10; i++)
        if (point[i] < 60)
            sum++;
    
    return sum;
}