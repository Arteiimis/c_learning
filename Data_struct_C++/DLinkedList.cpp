#include <iostream>
using namespace std;

template <class T>
class DLinkedList;

template <class T>
class Node
{
private:
    Node<T> *prev;
    Node<T> *next;
    T data;
    friend class DLinkedList<T>;

public:
    /**
     * @brief 无参数构造节点.
     */
    Node()
    {
        prev = NULL;
        next = NULL;
    }
    /**
     * @brief 有参数构造节点.
     * @param _data 待传入数据域的数据.
     * @param _prev 该节点前驱指针, 初始化为NULL.
     * @param _next 该节点后继指针, 初始化为NULL.
     */
    Node(T _data, Node<T> *_prev = NULL, Node<T> *_next = NULL)
    {
        prev = _prev;
        next = _next;
        data = _data;
    }
    ~Node()
    {
        prev = NULL;
        next = NULL;
    }
};

template <class T>
class DLinkedList
{
private:
    Node<T> *head = new Node<T>();
    Node<T> *tail = new Node<T>();

public:
    DLinkedList()
    {
        head->next = tail;
        head->prev = tail;
        tail->prev = head;
        tail->next = head;
    }
    bool head_insert(T data);
    bool tail_insert(T data);
    bool insert(T data, int index);
    auto find_node(T data);
    bool delete_node(int index);
    int length();
    void print();
};

template <class T>
bool DLinkedList<T>::head_insert(T data)
{
    Node<T> *new_node = new Node<T>(data);
    if (new_node == NULL)
    {
        std::cout << "new node failed" << std::endl;
        return false;
    }
    else
    {
        new_node->prev = head;
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;

        return true;
    }
}

template <class T>
bool DLinkedList<T>::tail_insert(T data)
{
    Node<T> *new_node = new Node<T>(data);
    if (new_node == NULL)
    {
        std::cout << "new node failed" << std::endl;
        return false;
    }
    else
    {
        new_node->prev = tail->prev;
        new_node->next = tail;
        tail->prev->next = new_node;
        tail->prev = new_node;

        return true;
    }

    return true;
}

template <class T>
bool DLinkedList<T>::insert(T data, int index)
{
    if (index < 1)
    {
        std::cout << "输入位置非法." << std::endl;
        return false;
    }
    Node<T> *ptr = head;
    for (int i = i; i < index; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL && i <= index)
        {
            std::cout << "插入位置无效." << std::endl;
            return false;
        }
    }
    Node<T> *new_node = new Node<T>(data);
    if (new_node == NULL)
    {
        std::cout << "内存分配失败" << std::endl;
        return false;
    }
    new_node->next = ptr->next;
    if (ptr->next != head)
    {
        ptr->next->prev = new_node;
    }
    new_node->prev = ptr;
    ptr->next = new_node;

    return true;
}

template <class T>
auto DLinkedList<T>::find_node(T data)
{
    Node<T> *ptr = head->next;
    int index = 0;
    auto sign = index;

    while (ptr != tail)
    {
        if (ptr->data == data)
        {
            sign = index;
            break;
        }
        ptr = ptr->next;
        index++;
    }
    if (index == 0)
    {
        sign = false;
    }

    return sign;
}

template <class T>
bool DLinkedList<T>::delete_node(int index)
{
    if (index < 0 || index > length())
    {
        std::cout << "删除位置无效." << std::endl;
        return false;
    }
    Node<T> *ptr = head;
    for (int i = 0; i <= index; i++)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;

    return true;
}

template <class T>
int DLinkedList<T>::length()
{
    int length = 0;
    Node<T> *ptr = head->next;
    while (ptr != tail)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}

template <class T>
void DLinkedList<T>::print()
{
    Node<T> *ptr = head->next;
    while (ptr != tail)
    {
        cout << ptr->data << ((ptr->next == tail) ? "\n" : " - ");
        ptr = ptr->next;
    }
}

int main()
{
    DLinkedList<int> dll;
    for (int i = 0; i < 10; i++)
    {
        dll.tail_insert(i);
    }
    dll.print();

    int index;
    int result;
    cout << "type in which index you want to find: ";
    cin >> index;
    result = dll.find_node(index);

    if (result == false)
        cout << "not found" << endl;
    else
        cout << "found in index: " << result << endl;

    cout << "type in which index you want to delete: ";
    cin >> index;
    dll.delete_node(index);

    dll.print();

    return 0;
}