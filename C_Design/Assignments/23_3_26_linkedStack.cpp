#include <bits/stdc++.h>
using namespace std;

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define _OVERFLOW -2

typedef int Status;
typedef int SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *PStackNode;

typedef struct LinkStack
{
    PStackNode top; // 栈顶指针
    int cursize;    // 数据元素个数
} LinkStack;

StackNode *Buynode(SElemType val, StackNode *narg = nullptr)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    if (p == nullptr)
        exit(_OVERFLOW);
    p->data = val;
    p->next = narg;

    return p;
}

void Freenode(StackNode *p)
{
    assert(p != nullptr);
    free(p);
}
// 构造一个空栈
Status InitStack(LinkStack *ps)
{
    ps->top = nullptr;
    ps->cursize = 0;

    return OK;
}

// 销毁栈
void DestroyStack(LinkStack *ps)
{
    assert(ps != nullptr);
    while (ps->top != nullptr)
    {
        StackNode *p = ps->top;
        ps->top = ps->top->next;
        Freenode(p);
    }
    ps->cursize = 0;
}

// 置为空栈
void ClearStack(LinkStack *ps)
{
    assert(ps != nullptr);
    while (ps->top != nullptr)
    {
        StackNode *p = ps->top;
        ps->top = ps->top->next;
        Freenode(p);
    }
    ps->cursize = 0;
}

// 返回栈的元素个数，即栈的长度
int StackLength(const LinkStack *ps)
{
    assert(ps != nullptr);

    return ps->cursize;
}

// 若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const LinkStack *ps)
{
    assert(ps != nullptr);

    return ps->cursize == 0;
}

// 入栈val , val为栈顶数据元素
Status Push(LinkStack *ps, SElemType val)
{
    assert(ps != nullptr);
    StackNode *p = Buynode(val, ps->top);
    ps->top = p;
    ps->cursize++;

    return OK;
}

// 若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const LinkStack *ps, SElemType *pval)
{
    assert(ps != nullptr);
    if (ps->top == nullptr)
        return ERROR;
    *pval = ps->top->data;

    return OK;
}

// 若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR
Status Pop(LinkStack *ps, SElemType *pval)
{
    assert(ps != nullptr);
    if (ps->top == nullptr)
        return ERROR;
    *pval = ps->top->data;
    StackNode *p = ps->top;
    ps->top = ps->top->next;
    Freenode(p);
    ps->cursize--;

    return OK;
}

void print(LinkStack *ps)
{
    assert(ps != nullptr);
    StackNode *p = ps->top;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkStack myps;
    InitStack(&myps);
    for (int i = 0; i < 10; i++)
        Push(&myps, i);
    print(&myps);
    SElemType val;
    Pop(&myps, &val);
    cout << val << endl;
    print(&myps);

    return 0;
}