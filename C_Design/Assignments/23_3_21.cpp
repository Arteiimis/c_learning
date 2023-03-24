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

// 删除当前节点
status erase(dlList *plist, dlNode *ptr)
{
    assert(plist != nullptr);
    if (nullptr == ptr)
        return ERROR;
    dlNode *temp = ptr;
    temp->prev->next = temp->next;
    temp->next = temp->prev;

    freeNode(temp);
    return OK;
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
    for (int i = 0; i < 10; i++)
        tailInsert(&list, i);

    ptintList(&list);

    for (int i = 0; i < 10; i++)
        headInsert(&list, i);

    ptintList(&list);

    erase(&list, list.head->next);

    ptintList(&list);

    return 0;
}