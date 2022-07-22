//实现功能：开卡  查询内容 存钱 取钱 转账 修改密码服务
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct band
{
    char cardname[20];
    char name[20];
    char PWD[6];
    double money;
    struct band *next;
};
struct band *head, *tail, *temp;
void init()
{
    head = NULL;
    tail = NULL;
    temp = NULL;
}
//写入文件
void write()
{
    FILE *fp = fopen("2.txt", "w");
    temp = head;
    while (temp != NULL)
    {
        fprintf(fp, "%s %s %s %lf\n", temp->cardname, temp->name, temp->PWD, temp->money);
        temp = temp->next;
    }
    fclose(fp);
}
//读出文件
void read()
{
    int flag = 0;
    FILE *fp = fopen("2.txt", "r");
    init();
    while (1)
    {
        temp = (struct band *)malloc(sizeof(struct band));
        flag = fscanf(fp, "%s %s %s %lf", temp->cardname, temp->name, temp->PWD, &temp->money);
        if (flag == -1)
        {
            break;
        }
        else
        {
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }
    }
    fclose(fp);
    system("cls");
}
//提示信息
void printUsage()
{
    printf("\t+-----------+\n");
    printf("\t| 1.开户    |\n");
    printf("\t| 2.查询    |\n");
    printf("\t| 3.存款    |\n");
    printf("\t| 4.取款    |\n");
    printf("\t| 5.转账    |\n");
    printf("\t| 6.载入文件|\n");
    printf("\t| 7.密码修改|\n");
    printf("\t| 0.退出    |\n");
    printf("\t+-----------+\n");
    printf("请输入您的选择：");
}
//开卡
void createCard()
{
    //开始进行结点
    char a[20];
    printf("\n欢迎您使用开卡功能：");
    printf("\n请输入您的卡号：");
    scanf("%s", a);

    struct band *pd;
    pd = head;
    while (pd != NULL)
    {
        if (strcmp(a, pd->cardname) == 0)
        {
            printf("您输入的卡号已存在,请重新输入: ");
            scanf("%s", a);
            pd = head;
        }
        else
        {
            pd = pd->next;
        }
    }
    if (pd == NULL)
    {
        printf("可开卡！请再次输入：\n");
    }

    temp = (struct band *)malloc(sizeof(struct band));
    temp->next = NULL;
    scanf("%s", temp->cardname);
    printf("\n请输入您的姓名：");
    scanf("%s", temp->name);
    printf("\n请输入您的密码：");
    scanf("%s", temp->PWD);
    printf("\n请输入您的余额：");
    scanf("%lf", &temp->money);
    //节点已产生 ，加入到链表中
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    write();
    system("pause");
    system("cls");
}

//查询功能
void query()
{
    printf("欢迎您使用查询功能：\n");
    char a[20];
    char b[20];
    char c[6];
    int i;
    temp = head; // temp从头开始
    printf("请输入您的卡号：\n");
    scanf("%s", a);
    while (1)
    {

        if (strcmp(a, temp->cardname) == 0)
        {
            printf("您输入的卡号正确，请输入您的姓名: \n");
            scanf("%s", b);
            if (strcmp(b, temp->name) == 0)
            {
                printf("您输入的姓名正确，请输入您的密码(您有三次机会)！\n"); //密码三次机会验证
                for (i = 1; i <= 3; i++)
                {
                    scanf("%s", c);
                    if (strcmp(c, temp->PWD) == 0)
                    {
                        printf("您输入的密码正确！\n");
                        printf("\n您的余额是%lf\n\n", temp->money);
                        break;
                    }
                    else
                    {
                        printf("您输入的密码不正确！\n");
                    }
                }
                if (i > 3)
                {
                    printf("您的密码错误！\n");
                    break;
                }
            }
            else
            {
                printf("您输入的姓名不正确！\n");
                break;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("您输入的卡号不正确！\n");
            break;
        }
    }
    system("pause");
    system("cls");
}
//存钱
void save()
{
    printf("欢迎您使用存钱功能：\n");
    char a[20];
    char b[20];
    char c[6];
    double d;
    int i;
    temp = head;
    printf("请输入您的卡号：\n");
    scanf("%s", a);
    while (1)
    {
        if (strcmp(a, temp->cardname) == 0)
        {
            printf("您输入的卡号正确，请输入您的姓名！\n");
            scanf("%s", b);
            if (strcmp(b, temp->name) == 0)
            {
                printf("您输入的姓名正确，请输入您的密码(您有三次机会)！\n"); //三次机会
                for (i = 1; i <= 3; i++)
                {
                    scanf("%s", c);
                    if (strcmp(c, temp->PWD) == 0)
                    {
                        printf("您输入的密码正确！\n");
                        printf("您的余额是%lf\n", temp->money);
                        printf("您要存的钱数为:");
                        scanf("%lf", &d);
                        while (d <= 0)
                        {
                            printf("您的输入有误！请重新输入。");
                            scanf("%lf", &d);
                        }
                        temp->money = temp->money + d;
                        printf("您此时的余额为：%lf\n", temp->money);
                        write();
                        break;
                    }
                    else
                    {
                        printf("您的密码错误，请重新输入。您还有%d次机会。\n", 3 - i);
                    }
                }
                if (i > 3)
                {
                    printf("您输入的密码不正确！\n");
                    break;
                }
            }
            else
            {
                printf("您输入的姓名不正确！\n");
                break;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("您输入的卡号不正确！\n");
            break;
        }
    }
    system("pause");
    system("cls");
}
//取钱
void withdraw()
{
    printf("欢迎您使用取钱功能：\n");
    char a[20];
    char b[20];
    char c[6];
    double d;
    int i;
    temp = head;
    printf("请输入您的卡号：\n");
    scanf("%s", a);
    while (1)
    {
        if (strcmp(a, temp->cardname) == 0)
        {
            printf("您输入的卡号正确，请输入您的姓名！\n");
            scanf("%s", b);
            if (strcmp(b, temp->name) == 0)
            {
                printf("您输入的姓名正确，请输入您的密码(您有三次机会)！\n");
                for (i = 1; i <= 3; i++)
                {
                    scanf("%s", c);
                    if (strcmp(c, temp->PWD) == 0)
                    {
                        printf("您输入的密码正确！\n");
                        printf("您的余额是%lf\n", temp->money);
                        printf("您要取的钱数为:");
                        scanf("%lf", &d);
                        if (d > temp->money)
                        {
                            printf("您的余额不足！请重新输入：");
                            scanf("%lf", &d);
                        }
                        temp->money = temp->money - d;
                        printf("您此时的余额为：%lf\n", temp->money);
                        write();
                        break;
                    }
                    else
                    {
                        printf("您输入的密码错误！您还有%d次机会。\n", 3 - i);
                    }
                }
                if (i > 3)
                {
                    printf("您输入的密码不正确！\n");
                    break;
                }
            }
            else
            {
                printf("您输入的姓名不正确！\n");
                break;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("您输入的卡号不正确！\n");
            break;
        }
    }
    system("pause");
    system("cls");
}
//转账
void transfer()
{
    read();
    printf("欢迎您使用转账功能：\n");
    char a[20];
    char b[20];
    char c[6];
    char e[20];
    double d;
    int i;
    temp = head;
    struct band *pd;
    printf("欢迎使用转账服务！\n");
    printf("请输入您的卡号：");
    scanf("%s", a);
    while (1)
    {
        if (strcmp(a, temp->cardname) == 0)
        {
            printf("您输入的卡号正确，请输入您的姓名!\n");
            scanf("%s", b);
            if (strcmp(b, temp->name) == 0)
            {
                printf("您输入的姓名正确，请输入密码(您有三次机会)!\n");
                for (i = 1; i <= 3; i++)
                {
                    scanf("%s", c);
                    if (strcmp(c, temp->PWD) == 0)
                    {
                        printf("您输入的密码正确，请输入要转账人的账号!\n");
                        scanf("%s", e);
                        pd = head;
                        while (1)
                        {
                            if (strcmp(e, pd->cardname) == 0)
                            {
                                printf("您转账人的卡号在开卡当中！\n");
                                printf("请输入您要转入的钱数(退出请按-1)！\n");
                                scanf("%lf", &d);
                                if (d > temp->money)
                                {
                                    printf("您的余额不足，请重新输入。");
                                }
                                else
                                {
                                    temp->money = temp->money - d;
                                    pd->money = pd->money + d;
                                    printf("您此时的余额为:%lf元\n", temp->money);
                                    break;
                                }
                                if (d == -1)
                                {
                                    break;
                                }
                            }
                            else
                            {
                                pd = pd->next;
                            }
                            if (pd == NULL)
                            {
                                printf("您输入的转账人的卡号不在我们开的卡当中！\n");
                                break;
                            }
                        }
                        break;
                    }
                    else
                    {
                        printf("您的密码不正确！您还有%d次机会。", 3 - i);
                    }
                }
                if (i > 3)
                {
                    printf("您输入的密码不正确！\n");
                    break;
                }
            }
            else
            {
                printf("您的姓名错误！");
                break;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("您的卡号不存在！\n");
            break;
        }
    }
    write();
    system("pause");
    system("cls");
}
//修改密码
void changePWD()
{
    printf("\n欢迎您使用修改密码功能：");
    char a[20];
    char b[20];
    char c[6];
    int i;
    temp = head;
    printf("\n请输入您的卡号：");
    scanf("%s", a);
    while (1)
    {
        if (strcmp(a, temp->cardname) == 0)
        {
            printf("您输入的卡号正确，请输入您的姓名！\n");
            scanf("%s", b);
            if (strcmp(b, temp->name) == 0)
            {
                printf("您输入的姓名正确，请输入您的密码！(您有三次机会)\n");
                for (i = 1; i <= 3; i++)
                {
                    scanf("%s", c);
                    if (strcmp(c, temp->PWD) == 0)
                    {
                        printf("您输入的密码正确！\n");
                        printf("请输入新的密码：");
                        scanf("%s", temp->PWD);
                        printf("\n您的新密码为：%s", temp->PWD);
                        break;
                    }
                    else
                    {
                        printf("您输入的密码不正确！您还有%d次机会\n", 3 - i);
                    }
                }
                if (i > 3)
                {
                    printf("您输入的密码不正确！\n");
                    break;
                }
            }
            else
            {
                printf("您输入的姓名不正确！\n");
                break;
            }
            break;
        }
        else
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("您输入的卡号不正确！\n");
            break;
        }
    }
    write();
    system("pause");
    system("cls");
}
void main()
{
    int op;
    while (1)
    {
        read();
        printUsage();
        scanf("%d", &op);
        if (op == 0)
        {
            printf("\n感谢您的使用，欢迎下次光临！");
            break;
        }
        switch (op)
        {
        case 1:
            createCard();
            break;
        case 2:
            query();
            break;
        case 3:
            save();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            read();
            printf("文件读取成功！\n");
            break;
        case 7:
            changePWD();
            break;
        default:
            printf("您的输入有误！\n");
        }
    }
}