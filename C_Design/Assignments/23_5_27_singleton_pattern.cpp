#include <bits/stdc++.h>
using namespace std;

class object
{
private:
    int value;
    static object* pobj;

private:
    object(int x = 0) :value(x) { cout << "Create Objobjectect" << this << endl; }
    object(const object&) = delete;
    object& operator=(const object&) = delete; // C++ 11;

public:
    ~object() { cout << "Destroy Object" << this << endl; }
    int& Value() { return value; }
    const int& Value()const { return value; }
    void show() const { cout << "value: " << value << endl; }
    static object* GetObject(int x)
    {
        if (nullptr == pobj)
        {
            pobj = new object(x);  // .heap
        }
        return pobj;
    }
};