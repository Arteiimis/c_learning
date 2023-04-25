#include <iostream>
using namespace std;
class base1
{
public:
    virtual void fun()
    {
        cout << "----base1----" << endl;
    }
};
class base2
{
public:
    virtual void fun()
    {
        cout << "----base2----" << endl;
    }
};
class derived : public base1, public base2
{
public:
    void fun()
    {
        cout << "----derived----" << endl;
    }
};
int main()
{
    base1 ob1, *p1;
    base2 ob2, *p2;
    derived ob3;
    p1 = &ob1;
    p1->fun();
    p2 = &ob2;
    p2->fun();
    p1 = &ob3;
    p1->fun();
    p2 = &ob3;
    p2->fun();
}
