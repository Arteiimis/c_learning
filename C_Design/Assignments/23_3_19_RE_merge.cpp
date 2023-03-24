#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct listNode
{
    int data;
    listNode *next;
    listNode(int _data) : data(_data), next(nullptr) {}
    listNode(int _data, listNode *_next) : data(_data), next(_next) {}
};

template <typename T>
class linkList
{
private:
    listNode *head;
    int size;

public:
    linkList()
    {
        head = new listNode(0);
        size = 0;
    }
    ~linkList()
    {
        listNode *p = head;
        while (p != nullptr)
        {
            listNode *q = p->next;
            delete p;
            p = q;
        }
    }

    void nextInsert(listNode *node, T data)
    {
        assert(node != nullptr);
        listNode *newnode = new listNode(data, node->next);
        node->next = newnode;
        size++;
    }

    void headInsert(T data)
    {
        listNode *newnode = new listNode(data, head->next);
        head->next = newnode;
        size++;
    }

    void tailInsert(T data)
    {
        listNode *newnode = new listNode(data, nullptr);
        listNode *temp = this->head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
        size++;
    }

    void sort()
    {
        this->head = _sort(this->head);
    }

    listNode *_sort(listNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        listNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        listNode *mid = slow->next;
        slow->next = nullptr;

        listNode *left = _sort(head);
        listNode *right = _sort(mid);

        return merge(left, right);
    }

    listNode *merge(listNode *head, listNode *tail)
    {
        listNode *dummy = new listNode(0);
        listNode *temp = dummy;
        while (head != nullptr && tail != nullptr)
        {
            if (head->data < tail->data)
            {
                temp->next = head;
                head = head->next;
            }
            else
            {
                temp->next = tail;
                tail = tail->next;
            }
            temp = temp->next;
        }
        if (head != nullptr)
            temp->next = head;
        if (tail != nullptr)
            temp->next = tail;

        return dummy->next;
    }

    void print()
    {
        listNode *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    linkList<int> list;
    // 随机插入十个数字
    srand(time(0));
    for (int i = 0; i < 10000; i++)
        list.tailInsert(rand() % 100);
    // list.print();

    auto start = high_resolution_clock::now();
    list.sort();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    // list.print();

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}