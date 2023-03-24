#include <bits/stdc++.h>
using namespace std;

template <typename T>
class linkList
{
private:
    struct node
    {
        T data;
        node *next;
        node(T data, node *next = nullptr) : data(data), next(next) {}
    };
    int size;
    node *head;

public:
    linkList() : size(0)
    {
        this->head = new node(T(), nullptr);
    }

    ~linkList()
    {
        node *dummy = this->head;
        while (dummy != nullptr)
        {
            node *temp = dummy;
            dummy = dummy->next;
            delete temp;
        }
    }

    void nextInsert(node *ptr, T data)
    {
        assert(ptr != nullptr);

        node *newnode = new node(data, ptr->next);
        ptr->next = newnode;
        this->size++;
    }

    void headInsert(T data)
    {
        node *newnode = new node(data, this->head->next);
        head->next = newnode;
        this->size++;
    }

    void tailInsert(T data)
    {
        node *dummy = this->head;
        node *newnode = new node(data);
        while (dummy->next != nullptr)
            dummy = dummy->next;
        if (dummy == this->head)
        { // 如果插入的是第一个节点
            this->head->next = newnode;
        }
        else
        {
            dummy->next = newnode;
        }
        newnode->next = nullptr;
        this->size++;
    }

    void sort()
    {
        _sort(this->head->next, nullptr);
    }

    node *_sort(node *head, node *tail)
    {
        if (head == tail) return head;
        node *slow = head, *fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        node *mid = slow;

        return merge(_sort(head, mid), _sort(mid, tail));
    }

    node *merge(node *head, node *tail)
    {
        node *dummy = new node(0);
        node *temp = dummy, *left = head, *right = tail;

        while (left && right)
        {
            if (left->data <= right->data)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left)
            temp->next = left;
        else if (right)
            temp->next = right;

        return dummy->next;
    }

    void print()
    {
        node *dummy = this->head;
        while (dummy->next != nullptr)
        {
            dummy = dummy->next;
            cout << dummy->data << " ";
        }
        cout << endl;
    }
};

int main()
{
    //test sort

    linkList<int> list;
    // 随即插入十个数字到链表中
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        list.tailInsert(rand() % 100);
    list.print();
    list.sort();
    list.print();



}