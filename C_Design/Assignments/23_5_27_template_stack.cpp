#include <bits/stdc++.h>
using namespace std;

template <class _T>
class myStack
{
private:
    _T* _data;
    int _top;
    size_t _size;
    size_t _capacity;

public:
    ~myStack() { delete[] _data; }
    size_t getSize() const { return _size; }
    size_t getCapacity() const { return _capacity; }
    bool empty() const { return _size == 0; }
    bool full() const { return _size == _capacity; }

    myStack(int _sz = 10) : _data(nullptr), _top(0), _size(0), _capacity(_sz)
    {
        _data = (_T*) malloc(_capacity * sizeof(_T));
        _top = _data;
    }

    myStack& operator=(const myStack& other) = default;

    void push(const _T& val)
    {
        if (full()) { throw overflow_error("Stack is full"); }
        new(&_data[++_top]) _T(val);
    }

    _T pop()
    {
        if (empty()) { throw underflow_error("Stack is empty"); }
        _T val = move(_data[_top--]);
        _data[_top].~_T();
        return val;
    }

    void clear()
    {
        while (!empty()) { pop(); }
    }
};