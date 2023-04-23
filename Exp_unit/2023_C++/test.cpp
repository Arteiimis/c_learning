#include <iostream>
using namespace std;
class Base
{
private:
    float x, y;

public:
    Base(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    }
    void print(void)
    {
        cout << " x=" << x << "  y=" << y;
    }
};
class Derived : public Base
{
private:
    float z;

public:
    Derived(float a = 0, float b = 0, float c = 0) : Base(a, b)
    {
        z = c;
    }
    void print(void)
    {
        Base::print();
        cout << "  z=" << z;
    }
};
void fun1(Base ob) // 普通函数
{
    ob.print();
    cout << endl;
}
void fun2(Base &ob) // 普通函数
{
    ob.print();
    cout << endl;
}
void fun3(Base *ob) // 普通函数
{
    ob->print();
    cout << endl;
}

int main(void)
{
    Derived ob(15.0, 25.0, 35.0);
    fun1(ob);
    fun2(ob);
    fun3(&ob);

    return 0;
}
