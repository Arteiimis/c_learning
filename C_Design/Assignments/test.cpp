#include <iostream>
#include <concepts>
using namespace std;

class A
{
public:
    ~A() {cout << "A" << endl;};
};

class B : public A
{
public:
    ~B() {cout << "B" << endl;};
};

int main()
{
    A* a = new B();
    delete a;
    B* b = new B();
    delete b;
    
    return 0;
}
