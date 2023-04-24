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
    void setBase(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    }
    void print(void)
    {
        cout << "  x=" << x << "  y=" << y;
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
    void setDerived(float a = 0, float b = 0, float c = 0)
    {
        Base::setBase(a, b);
        z = c;
    }
    void print(void)
    {
        Base::print();
        cout << "  z=" << z;
    }
};
int main(void)
{
    Base ob1;
    Derived ob2;
    ob2.setDerived(25.5, 35.5, 50.5);
    ob1 = ob2;
    ob1.print();
    cout << endl;
    ob2.print();
    cout << endl;
    Base *pb = &ob1;
    pb->print();
    cout << endl;
    Derived *pd = &ob2;
    pd->print();
    cout << endl;
    Base &cb = ob2;
    cb.print();
    cout << endl;
}
