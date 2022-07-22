#include <stdio.h>
#include <stdlib.h>

int main()
{
    double P, r;
    int n, m = 10000;
    int choice;

    printf("1：一次存五年。\n");
    printf("2：先存两年，到期后本息再存三年。\n");
    printf("3：先存三年，到期后本息再存两年。\n");
    printf("4：先存一年，到期后将本息再存一年，连续存五年。\n");
    printf("5：活期存款，活期利息每季度结算一次。\n");
    printf("请输入你的理财方案：\n");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        r = 0.03;
        n = 5;
        P = m * (1 + n * r);
        printf("本息和为：%.2f\n", P);
        break;
    case 2:
        r = 0.021;
        n = 2;
        P = m * (1 + n * r);
        r = 0.0275;
        n = 3;
        P = P * (1 + n * r);
        printf("本息和为：%.2f\n", P);
        break;
    case 3:
        r = 0.0275;
        n = 3;
        P = m * (1 + n * r);
        r = 0.021;
        n = 2;
        P = P * (1 + n * r);
        printf("本息和为：%.2f\n", P);
        break;
    case 4:
        for (int i = 0; i < 5; i++)
        {
            r = 0.015;
            n = 1;
            P = m * (1 + n * r);
            m = P;
        }
        printf("本息和为：%.2f\n", P);
        break;
    case 5:
        r = 0.035;
        n = 5;
        P = m * (1 + n * r);
        printf("本息和为：%.2f\n", P);
        break;
    default:
        printf("输入错误！\n");
            break;
    }

    return 0;
}