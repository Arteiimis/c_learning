#include <bits/stdc++.h>

#define OK 0
#define ERROR -1

typedef int status;
typedef int ElemType;
typedef struct listNode
{
    ElemType data;
    listNode *next;
} listNode, *PlistNode;

typedef struct
{
    listNode *head;
    int cursize;
} linkList;

// 初始化一个节点
listNode *buyNode(ElemType data, listNode *next)
{
    listNode *s = (listNode *)malloc(sizeof(listNode));
    if (nullptr == s)
        exit(EXIT_FAILURE);

    s->data = data;
    s->next = next;

    return s;
}

// 删除节点
void freeNode(listNode *p)
{
    assert(p != nullptr);

    free(p);
}

// 初始化链表
void initList(linkList *list)
{
    assert(list != nullptr);

    list->cursize = 0;
    list->head = buyNode(0, nullptr);
}

int listSize(linkList *plist)
{
    assert(plist != nullptr);

    return plist->cursize;
}

// 任意位置后端插入
void nextInsert(linkList *plist, listNode *node, ElemType data)
{
    assert(plist != nullptr && node != nullptr);

    listNode *s = buyNode(data, node->next);
    node->next = s;
    plist->cursize++;
}

// 头插
void headInsert(linkList *plist, ElemType data)
{
    assert(plist != nullptr);

    listNode *s = buyNode(data, plist->head->next);
    plist->head->next = s;
    plist->cursize++;
}

// 尾插
void tailInsert(linkList *plist, ElemType data)
{
    assert(plist != nullptr);

    listNode *p = plist->head;
    while (p->next != nullptr)
        p = p->next;

    listNode *s = buyNode(data, nullptr);
    p->next = s;
    plist->cursize++;
}

// 任意位置后端删除
status nextErase(linkList *plist, listNode *node)
{
    assert(plist != nullptr && node != nullptr);
    if (node->next == nullptr)
        return ERROR;

    listNode *p = node->next;
    node->next = p->next;
    freeNode(p);
    plist->cursize--;

    return OK;
}

// 头删
status headErase(linkList *plist)
{
    assert(plist != nullptr);
    if (plist->head->next == nullptr)
        return ERROR;

    listNode *p = plist->head->next;
    plist->head->next = p->next;
    freeNode(p);
    plist->cursize--;

    return OK;
}

// 头删代码复用版
void headEraseRE(linkList *plist)
{
    assert(plist != nullptr);
    nextErase(plist, plist->head);
}

// 尾删
status tailErase(linkList *plist)
{
    assert(plist != nullptr);
    if (plist->head->next == nullptr)
        return ERROR;

    listNode *p = plist->head;
    while (p->next != nullptr && p->next->next != nullptr)
        p = p->next;

    freeNode(p->next);
    p->next = nullptr;
    plist->cursize--;

    return OK;
}

// 尾删代码复用版
void tailEraseRE(linkList *plist)
{
    assert(plist != nullptr);
    listNode *p = plist->head;

    while (p->next != nullptr && p->next->next != nullptr)
        p = p->next;

    nextErase(plist, p);
}

// 按值删除节点
status removeVal(linkList *plist, ElemType data)
{
    assert(plist != nullptr);
    listNode *p = plist->head;

    while (p->next != nullptr && p->next->data != data)
        p = p->next;

    if (p->next == nullptr)
        return ERROR;

    nextErase(plist, p);

    return OK;
}

// 删除所有值为data的节点
status removeAllVal(linkList *plist, ElemType data)
{
    assert(plist != nullptr);
    listNode *prev = plist->head;
    listNode *p = prev->next;
    while (p != nullptr)
    {
        if (p->data == data)
        {
            prev->next = p->next;
            freeNode(p);
            plist->cursize--;
            p = prev->next;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    return OK;
}

// 按值查找节点
listNode *findVal(linkList *plist, ElemType data)
{
    assert(plist != nullptr);
    int sign = 0;
    if (plist->head->next == nullptr)
        return nullptr;

    listNode *p = plist->head->next;
    for (; p != nullptr && p->data != data; p = p->next)
        sign++;

    return sign == plist->cursize ? nullptr : p;
}

// 按值查找节点的前驱
listNode *findValPrev(linkList *plist, ElemType data)
{
    assert(plist != nullptr);
    int sign = 0;
    if (plist->head->next == nullptr)
        return nullptr;

    listNode *p = plist->head;
    for (; p->next != nullptr && p->next->data != data; p = p->next)
        sign++;

    return sign == plist->cursize ? nullptr : p;
}

// 删除链表
void destoryList(linkList *plist)
{
    assert(plist != nullptr);

    free(plist);
}

// 清空链表（保留头节点）
status clearList(linkList *plist)
{
    assert(plist != nullptr);

    while (plist->head->next != nullptr)
        headErase(plist);

    return OK;
}

// 打印链表
void printList(linkList *plist)
{
    assert(plist != nullptr);
    listNode *p = plist->head->next;
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    linkList list;
    initList(&list);

    for (int i = 0; i <= 10; i++)
        tailInsert(&list, i);
    for (int j = 0; j <= 10; j++)
        headInsert(&list, j);

    printList(&list);
    // findValPrev(&list, 11) == nullptr ? printf("not found") : printf("found");
    removeAllVal(&list, 5);

    printList(&list);

    destoryList(&list);

    return 0;
}