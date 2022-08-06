#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Account
{
public:
    string cardname;
    string cardnumber;
    string PWD;
    int state;
    double balance;
    Account *next;
};

Account *head, *tail, *temp;

void init()
{
    head = NULL;
    temp = NULL;
    tail = NULL;
}

void write()
{
    ofstream fout;
    fout.open("Account.txt", ios::out);
    temp = head;
    while (temp != NULL)
    {
        fout << temp->cardname << " "
            << temp->cardnumber << " "
            << temp->PWD << " "
            << temp->state << " "
            << temp->balance << endl;
        temp = temp->next;
    }
    fout.close();
}

void read()
{
    ifstream fin;
    fin.open("Account.txt", ios::in);
    init();
    while(1)
    {
        temp = new Account;
        fin >> temp->cardname
            >> temp->cardnumber
            >> temp->PWD
            >> temp->state
            >> temp->balance;
        temp->next = NULL;
        if(head == NULL)
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
    fin.close();
    system("cls");
}

void mainmenu()
{
    cout << "\t+-----------+" << endl;
    cout << "\t| 1.开户    |" << endl;
    cout << "\t| 2.查询    |" << endl;
    cout << "\t| 3.存款    |" << endl;
    cout << "\t| 4.取款    |" << endl;
    cout << "\t| 5.转账    |" << endl;
    cout << "\t| 6.改密    |" << endl;
    cout << "\t| 7.销户    |" << endl;
    cout << "\t| 0.退出    |" << endl;
    cout << "\t+-----------+" << endl;
    cout << "请输入选择：";
}




int getAccNumber()
{
    ifstream fin;
    int n = 0;
    char line[512];
    fin.open("Account.txt", ios::in);
    if(fin.fail())
    {
        cout << "文件打开失败" << endl;
        return 0;
    }
    else
    {
        while(!fin.eof())
        {
            fin.getline(line, 512, '\n');
            n++;
        }
        fin.close();
        return n + 6220000;
    }
    fin.close();
}

void creadCard()
{
    system("cls");
    string name, number, pwd;
    number = to_string(getAccNumber());
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;
    temp = new Account;
    temp->cardname = name;
    temp->cardnumber = number;
    temp->PWD = pwd;
    temp->state = 1;
    temp->balance = 0;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    write();
    cout << "开户成功！" << endl;
    system("pause");
    system("cls");
}

void query()
{
    read();
    system("cls");
    temp = head;
    string number;
    string pwd;
    cout << "请输入卡号：";
    cin >> number;
    while (temp != NULL)
    {
        if (temp->cardnumber == number)
        {
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if (temp->PWD == pwd)
            {
                cout << "查询成功！" << endl;
                cout << "姓名：" << temp->cardname << endl;
                cout << "卡号：" << temp->cardnumber << endl;
                cout << "余额：" << temp->balance << endl;
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
        temp = temp->next;
    }
}

void save()
{
    read();
    system("cls");
    temp = head;
    string number;
    string pwd;
    double money;
    cout << "请输入卡号：";
    cin >> number;
    while (temp != NULL)
    {
        if(temp->state == 0)
        {
            cout << "该账户已注销！" << endl;
            system("pause");
            system("cls");
            return;
        }
        if (temp->cardnumber == number)
        {
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if (temp->PWD == pwd)
            {
                cout << "请输入存款金额：";
                cin >> money;
                temp->balance += money;
                cout << "存款成功！" << endl;
                write();
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
        temp = temp->next;
    }
}

void withdraw()
{
    read();
    system("cls");
    temp = head;
    string number;
    string pwd;
    double money;
    cout << "请输入卡号：";
    cin >> number;
    while (temp != NULL)
    {
        if(temp->state == 0)
        {
            cout << "该账户已注销！" << endl;
            system("pause");
            system("cls");
            return;
        }
        if (temp->cardnumber == number)
        {
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if (temp->PWD == pwd)
            {
                cout << "请输入取款金额：";
                cin >> money;
                if (temp->balance >= money)
                {
                    temp->balance -= money;
                    cout << "取款成功！" << endl;
                    write();
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << "余额不足！" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
        temp = temp->next;
    }
}

void transfer()
{
    read();
    system("cls");
    temp = head;
    string out_number;
    string in_number;
    string pwd;
    Account *out_temp;
    Account *in_temp;
    double money;
    cout << "请输入转出卡号：";
    cin >> out_number;
    while (temp != NULL)
    {
        if(temp->state == 0)
        {
            cout << "该账户已注销！" << endl;
            system("pause");
            system("cls");
            return;
        }
        if (out_number == temp->cardnumber)
        {
            out_temp = temp;
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if(pwd == out_temp->PWD)
            {
                cout << "请输入转入卡号：";
                cin >> in_number;
                temp = head;
                while (temp != NULL)
                {
                    if (in_number == temp->cardnumber)
                    {
                        in_temp = temp;
                        cout << "请输入转入金额：";
                        cin >> money;
                        if (out_temp->balance >= money)
                        {
                            out_temp->balance -= money;
                            in_temp->balance += money;
                            cout << "转账成功！" << endl;
                            write();
                            system("pause");
                            system("cls");
                            return;
                        }
                        else
                        {
                            cout << "余额不足！" << endl;
                            system("pause");
                            system("cls");
                            return;
                        }
                    }
                    temp = temp->next;
                }
                cout << "卡号不存在！" << endl;
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }
}

void changePWD()
{
    read();
    system("cls");
    temp = head;
    string number;
    string pwd;
    string new_pwd;
    cout << "请输入卡号：";
    cin >> number;
    while (temp != NULL)
    {
        if(temp->state == 0)
        {
            cout << "该账户已注销！" << endl;
            system("pause");
            system("cls");
            return;
        }
        if (temp->cardnumber == number)
        {
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if (temp->PWD == pwd)
            {
                cout << "请输入新密码：";
                cin >> new_pwd;
                temp->PWD = new_pwd;
                cout << "修改成功！" << endl;
                write();
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
        temp = temp->next;
    }
}

void cancelAccount()
{
    read();
    system("cls");
    temp = head;
    string number;
    string pwd;
    cout << "请输入卡号：";
    cin >> number;
    while (temp != NULL)
    {
        if (temp->cardnumber == number)
        {
            cout << "姓名输入正确，请输入密码：";
            cin >> pwd;
            if (temp->PWD == pwd)
            {
                cout << "确定要注销账户吗？（y/n）";
                char c;
                cin >> c;
                if (c == 'y')
                {
                    temp->state = 0;
                    cout << "注销成功！" << endl;
                    write();
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << "取消成功！" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
            }
            else
            {
                cout << "密码错误！" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
        temp = temp->next;
    }
}

int main()
{
    while(1)
    {
        int choice = 0;
        mainmenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            creadCard();
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
            changePWD();
            break;
        case 7:
            cancelAccount();
            break;
        case 0:
            cout << "退出程序！" << endl;
            system("pause");
            system("cls");
            return 0;
        default:
            cout << "输入错误！" << endl;
            system("pause");
            system("cls");
            return 0;
        }
    }
    return 0;
}