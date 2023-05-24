#include <iostream>
#include <cstdlib> // #include<stdlib.h>
using namespace std;

class MyStack
{
private:
    enum
    {
        STACK_INIT_SIZE = 10,
        STACK_INC_SIEZ = 2
    };
    int *_data;
    int _size; // 容量
    int _top;  // 栈顶指针
public:
    MyStack() : _data(nullptr), _size(STACK_INIT_SIZE), _top(-1) //
    {
        _data = new (nothrow) int[_size]; // C++   throw std::bad_alloc
        if (nullptr == _data)
        {
            exit(EXIT_FAILURE);
        }
    }

    MyStack(int sz)
        : _data(nullptr),
          _size(sz > STACK_INIT_SIZE ? sz : STACK_INIT_SIZE),
          _top(-1) //
    {
        _data = new (nothrow) int[_size]; // C++   throw std::bad_alloc
        if (nullptr == _data)
        {
            exit(EXIT_FAILURE);
        }
    }

    ~MyStack()
    {
        if (nullptr != _data)
        {
            delete[] _data;
        }
        _data = nullptr;
        _size = 0;
        _top = -1;
    }

    // int Size(const MyStack * const this)
    int Size() const { return _top + 1; }
    bool Empty() const { return Size() == 0; }
    int Capt() const { return _size; }
    bool Full() const { return Capt() == Size(); }

    bool Push(int val)
    {
        if (Full())
        {
            return false;
        }
        _data[++_top] = val;
        return true;
    }
    bool Top(int &val) const // 取栈顶元素，元素不出栈
    {
        if (Empty())
            return false;
        val = _data[_top];
        return true;
    }
    bool Pop() // 只是出栈
    {
        if (Empty())
            return false;
        _top -= 1;
        return true;
    }
    bool GetPop(int &a) // 取栈顶元素和出栈
    {
        if (Empty())
            return false;
        a = _data[_top--];
        return true;
    }
};