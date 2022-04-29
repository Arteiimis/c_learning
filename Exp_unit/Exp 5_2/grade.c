//从键盘输入10个学生的某门课的成绩，计算平均成绩，并输出不及格的成绩和人数//
#include<stdio.h>

int main() {
    int grade[10], i, sum, count = 0;
    double average;

    for( int i = 1; i <= 10; i++ ) {
        scanf("%d", &grade[i]);
    }
    for( int j = 1; j <= 10; j++ ) {
        sum += grade[j];
        if ( grade[j] < 60 )
            count++;
    }
    average = sum / 10.0;

    printf("平均数：%lf\n", average);
    printf("不及格人数：%d\n", count);
}