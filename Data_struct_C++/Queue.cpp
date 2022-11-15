#include <iostream>

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T _data, Node *_next = NULL)
        {
            data = _data;
            next = _next;
        }
    };
    Node *head = new Node(0);
    Node *tail = new Node(0);
    int size = 2;

public:
    LinkedList()
    {
        head->next = tail;
        tail->next = head;
    }
    bool head_insert(T data);
    bool tail_insert(T data);

    bool prev_insert(int index, T data)
    {
        if (index < 0 || index > size)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        Node *new_node = new Node(data, p->next);
        p->next = new_node;
        size++;
        return true;
    }
    bool next_insert(int index, T data)
    {
        if (index < 0 || index > size)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        Node *new_node = new Node(data, p->next);
        p->next = new_node;
        size++;
        return true;
    }

    bool prev_Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        size--;
        return true;
    }
    bool next_Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
        size--;

        return true;
    }
    bool Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        size--;

        return true;
    }
    bool front_Delete(int index)
    {
        if (index < 0 || index >= size || size <= 2)
        {
            return false;
        }
        Node *p = head;
        p->next = p->next->next;
        size--;

        return true;
    }
    bool rear_Delete()
    {
        if (size <= 2)
        {
            return false;
        }
        Node *p = head;
        for (int i = 0; i < size - 2; i++)
        {
            p = p->next;
        }
        p->next = tail;
        size--;

        return true;
    }

    bool isfull()
    {
        return size == 0;
    };
    bool isempty()
    {
        return size == 0;
    };

    void print();
};