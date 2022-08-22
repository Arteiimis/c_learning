#include <iostream>
using namespace std;

template <class eletype>
class PriorityQueue
{
private:
    eletype *elems;
    int size;
    int capacity;
    PriorityQueue(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        elems = new eletype[capacity];
    }

public:
    bool push(eletype val);
    eletype pop();
    bool DeleteEle(int index);
    int Delete ();
    bool isfull()
    {
        return size == capacity;
    };
    bool isempty()
    {
        return size == 0;
    };
};

template <class eletype>
bool PriorityQueue<eletype>::push(eletype val)
{
    int i = 0;
    if (isfull())
    {
        cout << "Queue is full" << endl;
        return false;
    }
    cout << "InQueue" << endl;
    for (i = this->size - 1; this->arr[i / 2] > val && i > 1; i /= 2)
    {
        this->elems[i] = this->elems[i / 2];
    }
    this->elems[i] = val;
    this->size++;

    return true;
}

template <class eletype>
eletype PriorityQueue<eletype>::pop()
{
    eletype ret = this->elems[1];
    eletype x = elems[--size];
    
}