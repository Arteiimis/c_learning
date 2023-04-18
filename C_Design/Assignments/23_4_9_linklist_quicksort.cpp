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
    linkList() : head(nullptr), cursize(0) {}

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

    void quickSort(node *head, node *tail)
    {
        if (head == tail || head->next == tail)
            return;
        node *p = head, *q = head->next;
        while (q != tail)
        {
            if (q->data < head->data)
            {
                p = p->next;
                swap(p->data, q->data);
            }
            q = q->next;
        }
        swap(p->data, head->data);
        quickSort(head, p);
        quickSort(p->next, tail);
    }
};

int main()
{
    linkList list;
    for (int i = 0; i < 10; i++)
        list.insert(rand() % 100);
    list.print();
    list.quickSort();
    list.print();

    return 0;
}