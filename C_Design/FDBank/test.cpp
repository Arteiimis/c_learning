#include <iostream>
#include <string>
using namespace std;

// bool manbermark=0;//标记是否有注册成员
string loginmarknumber; //记录登录时还没有一个注册的，注册时的账号

class information
{
public:
    string num;        //账号
    string name;       //用户名
    string key;        //密码
    string ID;         //身份证号
    string tel;        //电话号码
    double money;      //余额
    information *next; //记录下一空间地址
};
int cheak_num(string str, information *head) //检查账号是否存在
{
    int t = 0; //记录该账号是否存在
    information *p = head;
    if (head == NULL)
        t = 0;
    else
    {
        while (p->next != NULL) //对已有账号进行遍历
        {
            if (p->num != str)
                p = p->next;
            else
            {
                t = 1;
                break;
            }
        }
        if (t == 0)
            if (p->num == str)
                t = 1;
    }
    return t; //若账号已经存在则返回1，否则返回0
}
information *get_information(information *head) //管理员录入信息
{
    information *s, *p;
    s = new information;
    cout << "请录入信息：" << endl;
    cout << "账号：";
    cin >> s->num;
    cout << "用户名：";
    cin >> s->name;
    cout << "密码：";
    cin >> s->key;
    cout << "身份证号：";
    cin >> s->ID;
    cout << "电话号码：";
    cin >> s->tel;
    cout << "余额：";
    cin >> s->money;
    cout << endl
         << "====================================信息录入成功===============================" << endl;
    while (1)
    {
        char ch;
        if (head == NULL)
        {
            head = s;
            // head->next=NULL;//头指针赋值
        }
        else
            p->next = s; //将新结点插入已有链表的最后
        cout << "是否继续录入信息   是（1），（2）否" << endl;
        cin >> ch;
        while (ch != '1' && ch != '2')
        {
            cout << "请重新输入是否继续录入 是（1）  否（2）";
            cin >> ch;
        }
        if (ch == '1')
        {
            //选择“是?
            p = s; // p指向链表中最后的结点
            p->next = NULL;
            s = new information;
            s->next = NULL;
            cout << "请输入注册信息:" << endl;
            cout << "账号：";
            string str111;
            cin >> str111;
            int t;
            t = cheak_num(str111, head);
            while (t == 1) //对已有账号进行判断 ，直到新注册账号不存在为止
            {
                cout << "账号已存在，请重新注册：";
                cin >> str111;
                t = cheak_num(str111, head);
            }
            s->num = str111;
            cout << "用户名：";
            cin >> s->name;
            cout << "密码：";
            cin >> s->key;
            cout << "身份证号:";
            cin >> s->ID;
            cout << "电话号码:";
            cin >> s->tel;
            cout << "余额:";
            cin >> s->money;
            cout << endl;
        }
        else //选择“否”
        {
            s->next = NULL;
            break;
        }
        cout << endl
             << "====================================信息录入成功===============================" << endl;
    }
    return head;
}
void output_information(information *head) //显示所有账号信息
{
    if (head == NULL)
    {
        cout << "暂无注册信息";
        return;
    }
    int i = 1;
    information *s;
    s = head;
    while (s->next != NULL)
    {
        cout << "用户注册编码：" << i << endl;
        cout << "账号：" << s->num << endl;
        cout << "用户名: " << s->name << endl;
        cout << "密码：" << s->key << endl;
        cout << "身份证号：" << s->ID << endl;
        cout << "电话：" << s->tel << endl;
        cout << "金额：" << s->money << endl
             << endl;
        s = s->next;
        i++;
    }
    cout << "用户注册编码：" << i << endl;
    cout << "账号：" << s->num << endl;
    cout << "用户名: " << s->name << endl;
    cout << "密码：" << s->key << endl;
    cout << "身份证号：" << s->ID << endl;
    cout << "电话：" << s->tel << endl;
    cout << "金额：" << s->money << endl;
}
int check_keys(string number, string keys, information *head) //检查账号是否存在且密码是否正确
{
    int t = 0;
    information *p = head;
    while (p->next != NULL)
    {
        if (p->num != number)
            p = p->next;
        else
        {
            if (p->key == keys)
            {
                t = 3; //账号存在且密码正确
                break;
            }
            else
            {
                t = 2; //账号存在但是密码不正确
                break;
            }
        }
    }
    if (t == 0)
        if (p->num == number)
            if (p->key == keys)
                t = 3; //账号存在且密码正确
            else
                t = 2; //账号存在但是密码不正确
    return t;
}
void take_money(information *p) //取钱函数
{
    double m;
    cout << "请输入提款金额：";
    cin >> m;
    if (m <= p->money) //判断是否超过账号余额
    {
        p->money = p->money - m;
        cout << "取款成功" << endl;
    }
    else
    {
        while (m > p->money) //若取钱金额超过账户余额
        {
            cout << "余额不足，请重新操作" << endl;
            cout << "请输入提款金额：";
            cin >> m;
        }
        p->money = p->money - m; //对取现后的余额进行修改
        cout << endl
             << "======================================取款成功==================================" << endl;
    }
}
void save_money(information *p) //存钱函数
{
    double m;
    cout << "请输入存款金额:";
    cin >> m;
    p->money = p->money + m; //对所存入的账户余额修改
    cout << endl
         << "======================================存款成功==================================" << endl;
}
information *cheak_number(string number, information *head) //在管理员模式下或者是客户在正确输入密码后查找客户信息
{
    int a = 0; //标记账户是否存在
    information *p = head;
    while (p->next != NULL)
    {
        if (p->num == number)
        {
            a = 1;
            break;
        }
        else
            p = p->next;
    }
    if (p->num == number)
        a = 1;
    if (a == 0)
        p = NULL;
    return p; //返回所查找的客户地址信息
}
void move_money(information *p, information *head) // 转账函数                  p是正在登陆的账号地址
{
    information *x; //记录所转账号地址
    x = NULL;
    double m;   //转账金额
    string str; //转账账号
    char ch;    //记录用户输入的是否继续转账决定
    cout << "请输入要转账的账号:";
    cin >> str;
    x = cheak_number(str, head); //记录下了所转账好的地址
    while (x == NULL)            //如果账户不存在
    {
        x = cheak_number(str, head); //记录下了所转账好的地址
        cout << "账号不存在，是否重新操作：(1)是  (2)否" << endl;
        cin >> ch;
        if (ch == '1')
        {
            cout << "请重新输入要转账的账户：";
            cin >> str;
            x = cheak_number(str, head); //记录下了所转账好的地址
        }
        else
            break;
    }
    if (x != NULL) //如果账户存在
    {
        cout << "请输入转账金额：";
        cin >> m;
        while (p->money < m)
        {
            cout << "余额不足，请重新输入转账金额：" << endl;
            cin >> m;
        }
        x->money = x->money + m;
        p->money = p->money - m;
        cout << endl
             << "=====================================转账成功================================" << endl;
    }
}
void revise_information(information *p) //"修改信息"
{
    string str, str1; //记录用户账号信息
    char ch;          //记录用户决定
    while (1)
    {
        cout << "请选择要修改的信息  (1)账号  (2)用户名  (3)密码  (4)身份证号  (5)电话 (6)退出修改当前账户信息   ";
        cin >> ch;
        while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6') //用户若输入业务已有误
        {
            cout << "请重新输入有效的业务：";
            cin >> ch;
        }
        if (ch == '1') //修改账号
        {
            cout << "请输入新账号：";
            cin >> str;
            p->num = str;
            cout << endl
                 << "====================================修改账号成功================================" << endl;
        }
        else if (ch == '2') //修改用户名
        {
            cout << "请输入新的用户名：";
            cin >> str;
            p->name = str;
            cout << endl
                 << "===================================修改用户名成功==============================" << endl;
        }
        else if (ch == '3') //修改密码
        {
            cout << "请输入原密码：";
            cin >> str;
            while (p->key != str)
            {
                cout << "与原密码不一致，请重新输入原密码：";
                cin >> str;
            }
            cout << "请输入新密码：";
            cin >> str;
            cout << "请确认密码：";
            cin >> str1;
            while (str != str1)
            {
                cout << "与第一次输入不同，请重新设定：";
                cout << "请输入新密码：";
                cin >> str;
                cout << "请确认密码：";
                cin >> str1;
            }
            cout << endl
                 << "===============================设定成功，请记好新密码==========================" << endl;
        }
        else if (ch == '4') //修改身份证号
        {
            cout << "请输入新身份证号：";
            cin >> str;
            p->ID = str;
            cout << endl
                 << "==================================修改身份证成功===============================" << endl;
        }
        else if (ch == '5') //修改电话号码
        {
            cout << "请输入新电话号码：";
            cin >> str;
            p->tel = str;
            cout << endl
                 << "==================================电话号码修改成功=============================" << endl;
        }
        else
            break; //退出修改账户信息
    }
}
void show_information(information *p) //显示当前账户信息
{
    cout << "账号：" << p->num << endl;
    cout << "用户名:" << p->name << endl;
    cout << "密码：" << p->key << endl;
    cout << "身份证号：" << p->ID << endl;
    cout << "电话：" << p->tel << endl;
    cout << "金额：" << p->money << endl;
}

void query_money(information *p) //显示当前账户余额
{
    cout << "您的余额为：";
    cout << p->money << endl;
}
information *logon(information *head) //用户注册账号
{
    information *s;
    string str; //记录账号信息
    cout << "请输入注册账号：";
    cin >> str;
    int t;
    if (head == NULL) //如果链表不存在信息，默认为新注册的账号不存在
        t = 0;
    else
        t = cheak_num(str, head); //判断账号是否已经存在
    while (t == 1)                //账号已经存在 重新输入
    {
        cout << "账号已存在，请重新注册：";
        cin >> str;
        t = cheak_num(str, head);
    }
    s = new information; //为链表开辟新空间
    s->num = str;
    if (head == NULL)
        loginmarknumber = str;
    cout << "用户名：";
    cin >> s->name;
    cout << "密码：";
    cin >> s->key;
    cout << "身份证号：";
    cin >> s->ID;
    cout << "电话号码：";
    cin >> s->tel;
    cout << "余额：";
    cin >> s->money;
    if (head == NULL) //如果当前链表没有任何信息
    {
        head = s;
        head->next = NULL;
    }
    else //将新注册的插入当前链表
    {
        s->next = head->next;
        head->next = s;
    }
    cout << endl
         << "=====================================注册成功===================================" << endl;
    return head;
}

information *choose(information *head) //普通用户登陆账号以及选择需要的业务
{
    int t, loginmark = 0;
    if (head == NULL)
    { //还没有注册账号
        cout << endl
             << "未有账户注册，无法完成登陆功能，请先注册账户信息" << endl
             << "是否现在注册：（1）是，（2）稍后注册" << endl;
        int x;
        cin >> x;
        while (x != 1 && x != 2)
        {
            cout << "请重新选择：";
            cin >> x;
        }
        if (x == 1)
        {
            head = logon(head);
            loginmark = 1;
        }
        else
            return head;
    }

    information *p;      // p是用来记录所查找到的账号的地址的
    string number, keys; // number 记录登陆账号 keys记录账密码
    if (loginmark == 0)
    {
        cout << "请输入账号：";
        cin >> number;
        cout << "请输入账号密码:";
        cin >> keys;
        t = check_keys(number, keys, head); // t是用来记录是否存在账号以及密码是否正确的，若账号不存在则返回0，若账号密码错误返回2，账号存在且密码正确时返回3
        while (t == 0 || t == 2)            //如果账号不存在或者是密码输入错误
        {
            if (t == 2) //用户输入密码有误
            {
                cout << "密码输入错误，请重新输入账号及密码";
                cout << "账号:";
            }
            else //账号不存在
                cout << "账号不存在，请重新输入账号及密码,账号:";
            cin >> number;
            cout << "密码:";
            cin >> keys;
            t = check_keys(number, keys, head); //调用判断密码 账号是否正确
        }
    }
    else
        number = loginmarknumber;

    cout << endl
         << "==================================普通用户登陆成功==============================" << endl
         << endl;
    cout << "请选择业务：(1)取钱 (2)存钱  (3)转账  (4)修改信息  (5)余额查询 (6)显示账号信息  (7)退出账号" << endl;
    p = cheak_number(number, head); //记录所登陆的账号地址
    char ch;                        //记录用户所做的选择
    cin >> ch;
    while (1)
    {
        while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7') //用户若出入业务有误
        {
            cout << "请重新输入所需业务：(1)取钱 (2)存钱  (3)转账  (4)修改信息  (5)余额查询 (6)显示账号信息  (7)退出账号" << endl;
            cin >> ch; //重新输入业务
        }
        if (ch == '7') //退出当前账户
            break;
        else
        {
            switch (ch)
            {
            case '1':
                take_money(p);
                break; //取钱
            case '2':
                save_money(p);
                break; //存钱
            case '3':
                move_money(p, head);
                break; //转账
            case '4':
                revise_information(p);
                break; //修改信息
            case '5':
                query_money(p);
                break; //查询余额
            case '6':
                show_information(p);
                break; //查看信息
            }
            cout << "请选择业务：(1)取钱 (2)存钱  (3)转账  (4)修改信息  (5)余额查询 (6)显示账号信息  (7)退出账号" << endl;
            cin >> ch;
        }
    }
    return head;
}

string change_monitor_keys(string monitor)
{
    string string1, string2; //记录用户两次输入密码
    cout << "请输入原密码：";
    cin >> string1;
    while (string1 != monitor) //如果管理员密码输入不正确
    {
        cout << "与原密码不符，是否重新输入  (1)是   (2) 否  " << endl;
        char chra;
        cin >> chra;                       //记录用户是否继续登陆
        while (chra != '1' && chra != '2') //判断用户是否存在误操作
        {
            cout << "选择有误，请重新选择：(1)是   (2) 否 " << endl;
            cin >> chra;
        }
        if (chra == '1') //继续登陆输入账号
        {
            cout << "请再次输入原密码：";
            cin >> string1;
        }
        else
        { //停止登陆
            cout << endl
                 << "==================================密码未修改====================================" << endl;
            break;
        }
    }
    if (string1 != monitor) //退出修改管理员密码
        return monitor;
    cout << "请输入新密码：";
    cin >> string1;
    cout << "请再次输入确认修改密码：";
    cin >> string2;
    while (string1 != string2) //判断两次输入的新密码是否一致
    {
        cout << "两次输入密码不相同，请选择是否继续修改：(1)是 (2)否" << endl;
        char jilu; //记录用户选择是否继续修改
        cin >> jilu;
        while (jilu != '1' && jilu != '2') //判断用户是否存在误操作，是则提示
        {
            cout << "请重修选择是否修改：(1)是 (2)否" << endl;
            cin >> jilu;
        }
        if (jilu == '1') //继续修改密码
        {
            cout << "请输入新密码：";
            cin >> string1;
            cout << "请再次输入确认修改密码：";
            cin >> string2;
        }
        else
        { //退出修改密码
            break;
        }
    }
    if (string2 == string1) //如果在两次输入修改密码一致，成功修改
    {
        monitor = string1;
        cout << endl
             << "====================================密码修改成功===============================" << endl;
    }
    else
        cout << endl
             << "==================================密码未修改==============================" << endl;
    return monitor;
}
void choose_model(information *head, string monitor) //选择开始界面业务
{
    information *p;
    char ch, mon_cho; //记录用户选择
    string str;       //后面用到的是管理员密码  客户账号
    cout << "==============================欢迎进入银行管理系统==============================" << endl;
    while (1)
    {
        cout << "请选择进入模式：" << endl;
        cout << "(1)管理员模式  (2)普通用户模式 (3)退出系统 " << endl;
        cin >> ch;
        while (ch != '1' && ch != '2' && ch != '3') //如果用户输入有误，提示
        {
            cout << "请选择进入模式：" << endl;
            cout << "(1)管理员模式  (2)普通用户模式 (3)退出系统 " << endl;
            cin >> ch;
        }
        if (ch == '1') //管理员模式
        {
            cout << "您已进入管理员模式" << endl
                 << "请输入管理员密码：";
            cin >> str;
            if (monitor != str)
            {
                char judge;            //用来记录选择
                while (monitor != str) //判断管理员密码是否正确
                {
                    cout << "管理员密码输入错误，是否重新输入   (1)是   (2)否" << endl; //此处考虑到可能是客户不小心进入可以选择退出管理员模式
                    cin >> judge;
                    while (judge != '1' && judge != '2') //如果用户输入有误,提示
                    {
                        cout << "请重新选择是否重新输入密码  (1)是   (2)否" << endl;
                    }
                    if (judge == '1') //继续输入密码
                    {
                        cout << "请重新输入管理员密码:";
                        cin >> str; //重新输入管理员密码
                    }
                    else
                    {
                        break; //结束本输入密码循环
                    }
                }
            }
            if (monitor == str) //成功登陆管理员
            {
                cout << endl
                     << "==================================管理员登陆成功===============================" << endl;
                while (1)
                {

                    cout << endl
                         << endl
                         << "请输入要执行的操作" << endl;
                    cout << "(1)客户信息录入  (2)管理客户信息  (3)修改管理员密码 (4)显示所有账户信息  (5)退出管理员模式" << endl;

                    cin >> mon_cho;                                                                                //记录用户选择
                    while (mon_cho != '1' && mon_cho != '2' && mon_cho != '3' && mon_cho != '4' && mon_cho != '5') //如果用户输入有误，提示
                    {
                        cout << endl
                             << endl
                             << "请重新选择模式" << endl;
                        cout << "(1)客户信息录入  (2)管理客户信息  (3)修改管理员密码  (4)显示所有账户信息  (5)退出管理员模式" << endl;
                        cin >> mon_cho;
                    }
                    if (mon_cho == '1') //客户信息录入
                        head = get_information(head);
                    else if (mon_cho == '2') //管理账户信息
                    {
                        if (head == NULL)
                        {
                            cout << "对不起，由于暂无账户注册信息，该操作无法执行" << endl;
                            continue;
                        }
                        cout << "请输入要修改的客户账号：";
                        cin >> str;
                        p = cheak_number(str, head); //判断账户是否存在
                        while (p == NULL)            //账户不存在，提示重新输入
                        {
                            cout << "该账号不存在，请重新输入：";
                            cin >> str;
                            p = cheak_number(str, head);
                        }
                        revise_information(p); //修改已存在的账户信息
                    }
                    else if (mon_cho == '5') //结束管理员模式
                        break;
                    else

                        if (mon_cho == '4') //输出所有账户信息
                        output_information(head);
                    else //修改管理员密码
                        monitor = change_monitor_keys(monitor);
                }
            }
        }
        else if (ch == '2') //选择普通客户模式
        {
            char jilu; //记录用户所选业务
            cout << "==============================欢迎进入银行管理系统==============================" << endl;
            while (1)
            {
                cout << "请选择需要业务：(1) 注册  (2) 登录 (3)退出普通用户模式 " << endl;
                cin >> jilu;
                while (jilu != '1' && jilu != '2' && jilu != '3') //判断用户误操作,提示
                {
                    cout << "输入错误，请重新选择业务：：(1) 注册  (2) 登录 (3)退出普通用户模式 " << endl;
                    cin >> jilu;
                }
                if (jilu == '1') //注册
                    head = logon(head);
                else if (jilu == '2') //登陆
                    head = choose(head);
                else
                    break; //退出普通用户模式
            }
        }
        else //退出该系统
            break;
    }
}
int main()
{
    information *head = NULL;
    string monitor = "123"; // monitor为管理员初始密码
    choose_model(head, monitor);
    return 0;
}
