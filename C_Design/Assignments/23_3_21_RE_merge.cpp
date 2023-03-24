#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

template <typename T>
class dlList
{
private:
    struct dlNode
    {
        T data;
        dlNode *prev;
        dlNode *next;
        dlNode(T _data) : data(_data), prev(nullptr), next(nullptr) {}
        dlNode(T _data, dlNode *_prev, dlNode *_next) : data(_data), prev(_prev), next(_next) {}
    };

    dlNode *head;
    dlNode *tail;
    int size;

public:
    dlList() :  size(0) 
    {
        head = new dlNode(0);
        tail = new dlNode(0);
        head->next = tail;
        tail->prev = head;
    }

    void nextInsert(dlNode *node, T data)
    {
        assert(node != nullptr);

        dlNode *newnode = new dlNode(data, node, node->next);
        node->next->prev = newnode;
        node->next = newnode;
        size++;
    }

    void headInsert(T data)
    {
        nextInsert(head, data);
    }

    void tailInsert(T data)
    {
        nextInsert(tail->prev, data);
    }

    void sort()
    {
        head = _sort(head);
    }

    dlNode *_sort(dlNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        dlNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        dlNode *mid = slow->next;
        slow->next = nullptr;

        dlNode *left = _sort(head);
        dlNode *right = _sort(mid);
        return merge(left, right);
    }

    dlNode *merge(dlNode *list1, dlNode *list2)
    {
        dlNode *dummy = new dlNode(0);
        dlNode *temp = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data <= list2->data)
            {
                temp->next = list1;
                list1->prev = temp;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2->prev = temp;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1)
        {
            temp->next = list1;
            list1->prev = temp;
        }
        else if (list2)
        {
            temp->next = list2;
            list2->prev = temp;
        }

        return dummy->next;
    }

    void print()
    {
        dlNode *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    dlList<int> dlList;
    srand(time(0));
    for (int i = 0; i < 10000; i++)
        dlList.tailInsert(rand() % 10);

    //dlList.print();
    auto start = high_resolution_clock::now();
    dlList.sort();
    auto stop = high_resolution_clock::now();
    //dlList.print();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}