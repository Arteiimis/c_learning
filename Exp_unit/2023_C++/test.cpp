#include <iostream>
#include <string>
using namespace std;
class person
{
private:
    char *name;

public:
    person(char *pn);         // 构造函数声明
    ~person(void);            // 析构函数声明
    person(const person &ob); // 拷贝构造函数声明
    char *get_name(void)
    {
        return name;
    }
    void print_name(void);
};

person::person(char *pn) // 定义构造函数，为name提供值
{
    name =   ② ;
    if (name != NULL)
        ③ ;
}

person::~person(void) // 显示定义析构函数
{
    delete[] name;
}

person::person(const person &ob) // 定义拷贝构造函数
{
    name =  ④ ;
    if (name != NULL)
        ⑤ ;
}

void person::print_name(void)
{
    cout << name << endl;
}

int main(void)
{
    person p1("张三");
    person p2 = p1;
    cout << "姓名:";
    p1.print_name();
    cout << "姓名:";
    p2.print_name();

    return 0;
}
