#include <bits/stdc++.h>

#define OK 0
#define ERROR -1

typedef int status;
typedef int ElemType;

typedef struct dlNode
{
    dlNode *prev;
    dlNode *next;
    ElemType data;

} dlNode, *PdlNode;

typedef struct dlList
{
    dlNode *head;
    int cursize;
} dlList;

// 开辟一个节点
dlNode *buyNode(ElemType data, dlNode *prev = nullptr, dlNode *next = nullptr)
{
    dlNode *newnode = (dlNode *)malloc(sizeof(dlNode));
    if (nullptr == newnode)
        exit(EXIT_FAILURE);
    newnode->prev = (prev == nullptr) ? newnode : prev;
    newnode->next = (next == nullptr) ? newnode : next;
    newnode->data = data;

    return newnode;
}

// 删除节点
status freeNode(dlNode *node)
{
    assert(node != nullptr);

    free(node);
    return OK;
}

// 初始化节点
void initList(dlList *list)
{
    list->cursize = 0;
    list->head = buyNode(0);
    list->head->next = list->head;
    list->head->prev = list->head;
}

// 在指定节点之前插入
void prevInsert(dlList *plist, dlNode *ptr, ElemType data)
{
    assert(plist != nullptr && ptr != nullptr);

    dlNode *node = buyNode(data, ptr->prev, ptr);
    ptr->prev->next = node;
    ptr->prev = node;
    plist->cursize++;
}

// 在指定节点之后插入
void nextInsert(dlList *plist, dlNode *ptr, ElemType data)
{
    assert(plist != nullptr && ptr != nullptr);

    dlNode *node = buyNode(data, ptr, ptr->next);
    ptr->next->prev = node;
    ptr->next = node;
    plist->cursize++;
}

// 头插
void headInsert(dlList *plist, ElemType data)
{
    assert(plist != nullptr);

    nextInsert(plist, plist->head, data);
}

// 尾插
void tailInsert(dlList *plist, ElemType data)
{
    assert(plist != nullptr);

    prevInsert(plist, plist->head, data);
}

void insertArr(dlList *plist, ElemType *first, ElemType *last)
{   
    assert(plist != nullptr && first != nullptr && last != nullptr);

    while (first != last)
    {
        tailInsert(plist, *first);
        first++;
    }
}

dlNode *findVal(dlList *plist, ElemType val)
{
    assert(plist != nullptr);

    dlNode *ptr = plist->head->next;
    while (ptr != plist->head)
    {
        if (ptr->data == val)
            return ptr;
        ptr = ptr->next;
    }

    return nullptr;
}

std::vector<dlNode*> findValAll(dlList *plist, ElemType val)
{
    assert(plist != nullptr);

    std::vector<dlNode*> vec;
    dlNode *ptr = plist->head->next;
    while (ptr != plist->head)
    {
        if (ptr->data == val)
            vec.push_back(ptr);
        ptr = ptr->next;
    }

    return vec;
}

// 删除当前节点
status erase(dlList *plist, dlNode *ptr)
{
    assert(plist != nullptr);
    if (nullptr == ptr)
        return ERROR;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    plist->cursize--;

    freeNode(ptr);
    return OK;
}

status eraseAll(dlList *plist, ElemType val)
{
    assert(plist != nullptr);

    dlNode *ptr = plist->head->next;
    while (ptr != plist->head)
    {
        if (ptr->data == val)
        {
            dlNode *temp = ptr->next;
            erase(plist, ptr);
            ptr = temp;
        }
        ptr = ptr->next;
    }

    return OK;
}

void clear(dlList *plist)
{
    assert(plist != nullptr);

    dlNode *ptr = plist->head->next;
    while (ptr != plist->head)
    {
        dlNode *temp = ptr->next;
        erase(plist, ptr);
        ptr = temp;
    }
}

void _push_back(dlList *plist, int val)
{
    assert(plist != nullptr);

    prevInsert(plist, plist->head, val);
}

dlNode *pop_front(dlList *plist)
{
    assert(plist != nullptr);
    dlNode *node = plist->head->next;
    erase(plist, plist->head->next);

    return node;
}

// 打印链表
void ptintList(dlList *plist)
{
    assert(plist != nullptr);

    dlNode *ptr = plist->head->next;
    if (ptr == plist->head)
    {
        printf("empty list");
        return;
    }
    while (ptr != plist->head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    dlList list;
    initList(&list);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    insertArr(&list, arr, arr + 10);
    ptintList(&list);
    eraseAll(&list, 5);
    ptintList(&list);
    clear(&list);
    ptintList(&list);
    // for (int i = 0; i < 10; i++)
    //     tailInsert(&list, i);

    // ptintList(&list);

    // for (int i = 0; i < 10; i++)
    //     headInsert(&list, i);

    // ptintList(&list);

    // erase(&list, list.head->next);

    // ptintList(&list);

    return 0;
}