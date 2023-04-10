#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d) : data(d), next(nullptr) {}
};

class linkList
{
private:
    node *head;
    int cursize;

public:
    linkList():head(nullptr),cursize(0){}

    void insert(int d)
    {
        node *p = new node(d);
        p->next = head;
        head = p;
        cursize++;
    }

    void print()
    {
        node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void quickSort()
    {
        quickSort(head, nullptr);
    }

    void quickSort(node *start, node *end)
    {
        if (start == end)
            return;
        node *p = partition(start, end);
        quickSort(start, p);
        quickSort(p->next, end);
    }

    node *partition(node *start, node *end)
    {
        int pivot = start->data;
        node *p = start, *q = start->next;
        while (q != end)
        {
            if (q->data < pivot)
            {
                p = p->next;
                swap(p->data, q->data);
            }
            q = q->next;
        }
        swap(p->data, start->data);
        return p;
    }
    
    node 
};