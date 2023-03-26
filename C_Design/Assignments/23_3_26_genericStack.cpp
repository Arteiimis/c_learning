#include <bits/stdc++.h>
using namespace std;

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define __OVERFLOW -2

typedef int status;

struct genericNode
{
    void *data;
    genericNode *next;
};

struct genericStack
{
    genericNode *top;
    int cursize;
};

genericNode *buyNode(void *val, genericNode *narg = nullptr)
{
    genericNode *p = (genericNode *)malloc(sizeof(genericNode));
    if (p == nullptr)
        exit(__OVERFLOW);
    p->data = val;
    p->next = narg;

    return p;
}

void freeNode(genericNode *p)
{
    assert(p != nullptr);

    free(p);
}

status initStack(genericStack *ps)
{
    ps->top = nullptr;
    ps->cursize = 0;

    return OK;
}

void clearStack(genericStack *ps)
{
    assert(ps != nullptr);
    while (ps->top != nullptr)
    {
        genericNode *p = ps->top;
        ps->top = ps->top->next;
        freeNode(p);
    }
    ps->cursize = 0;
}

int stackLength(const genericStack *ps)
{
    assert(ps != nullptr);
    return ps->cursize;
}

status push(genericStack *ps, string type, void *val)
{
    assert(ps != nullptr);
}