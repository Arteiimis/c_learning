
#include "../include/ObjectPool4.hpp"
#include <iostream>
#include<thread>

using namespace std;

class Int
{
private:
    int value;

public:
    explicit Int(int x)
            : value(x) { cout << "Create Int(int)" << endl; }
    Int(int x, int y)
            : value(x + y) { cout << "Create Int(int,int)" << endl; }
    Int(const Int &it)
            : value(it.value) { cout << "Copy Create Int" << endl; }

    Int &operator=(const Int &it)
    {
        if (this != &it)
        {
            value = it.value;
        }
        cout << "operator=()" << endl;
        return *this;
    }

    Int(Int &&it) noexcept
            : value(it.value)
    {
        it.value = 0;
        cout << "Move Create Int" << endl;
    }

    Int &operator=(Int &&it)
    {
        if (this != &it)
        {
            value = it.value;
            it.value = 0;
        }
        cout << "move operator=()" << endl;
        return *this;
    }

    ~Int() { cout << "Destroy Int " << endl; }
    void SetValue(int x) { value = x; }
    int GetValue() const { return value; }
    void Print() const { cout << "Value: " << value << endl; }
};

void fun(ObjectPool<Int> &myobj, int x)
{
    auto p = myobj.acquire(x);

    if (p)
    {
        p->SetValue(x);
        p->Print();
        p->SetValue(0);
    }
}

void funa(ObjectPool<Int> &myobj)
{
    auto pa = myobj.acquire(10);
    if (pa) pa->Print();
    auto pb = myobj.acquire(10);
    if (pb) pa->Print();
    auto pc = myobj.acquire(10);
    if (pc) pa->Print();
    auto pd = myobj.acquire(10);
    if (pd) pa->Print();
    auto pe = myobj.acquire(10);
    if (pe) pa->Print();
}

void funb(ObjectPool<Int>& myobj)
{
    auto pa = myobj.acquire(10);
    if (pa) pa->Print();
    auto pb = myobj.acquire(10);
    if (pb) pa->Print();
    auto pc = myobj.acquire(10);
    if (pc) pa->Print();
    auto pd = myobj.acquire(10);
    if (pd) pa->Print();
    auto pe = myobj.acquire(10);
    if (pe) pa->Print();
}

void func(ObjectPool<Int> &myobj)
{
    auto pc = myobj.acquire(30);
    if (pc) pc->Print();
}

void fund(ObjectPool<Int> &myobj)
{
    auto pd = myobj.acquire(40);
    if (pd) pd->Print();
}

void fune(ObjectPool<Int> &myobj)
{
    auto pe = myobj.acquire(50);
    if (pe) pe->Print();
}

int main()
{
    ObjectPool<Int> mypool(4, 2);
    const int n = 100;
    std::thread thar[n] = {};
    for (int i = 0; i < n; ++i)
    {
        thar[i] = std::thread(fun, std::ref(mypool), i);
    }
    for (int i = 0; i < n; ++i)
    {
        thar[i].join();
    }
    cout << "Total Obejct   : " << mypool.getTotalObjSize() << endl;
    cout << "Idle Object    : " << mypool.getIdleObjSize() << endl;
    cout << "Acivate Object : " << mypool.getActivateObjSize() << endl;
    return 0;

}
#if 0
int main()
{
    ObjectPool<Int> mypool(4, 2);
    std::thread tha(funa, std::ref(mypool));
    std::thread thb(funb, std::ref(mypool));
    std::thread thc(func, std::ref(mypool));
    std::thread thd(fund, std::ref(mypool));
    std::thread the(fune, std::ref(mypool));

    tha.join();
    thb.join();
    thc.join();
    thd.join();
    the.join();

    cout << "Total Obejct   : " << mypool.getTotalObjSize() << endl;
    cout << "Idle Object    : " << mypool.getIdleObjSize() << endl;
    cout << "Acivate Object : " << mypool.getActivateObjSize() << endl;
    return 0;

}

// 使用类模板设计对象池类型//std::list存储池对象 std::shared_ptr 管理对象生命周期
//提供acquire 接口获取池中对象， clear() 接口用于清空池中对象；
int main()
{
    ObjectPool<Int> mypool(4, 2);
    {
        auto pa = mypool.acquire(10);
        if (pa) pa->Print();

        auto pb = mypool.acquire(20);
        if (pb) pb->Print();

        auto pc = mypool.acquire(30);
        if (pc) pb->Print();

        auto pd = mypool.acquire(40);
        if (pd) pd->Print();

        auto pe = mypool.acquire(50);
        if (pe) pe->Print();
    }

    cout << "Total Obejct   : " << mypool.getTotalObjSize() << endl;
    cout << "Idle Object    : " << mypool.getIdleObjSize() << endl;
    cout << "Acivate Object : " << mypool.getActivateObjSize() << endl;
    return 0;
}

#endif