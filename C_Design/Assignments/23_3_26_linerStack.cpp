#include <bits/stdc++.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 1.5
typedef int SElemType;

typedef struct
{
    SElemType *base; // 栈底指针
    int top;         // 栈顶指针
    int stacksize;   // 栈的当前最大容量
} SeqStack;

// 构造一个空栈
Status InitStack(SeqStack *ps)
{
    ps->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!ps->base)
        exit(_OVERFLOW);
    ps->top = 0;
    ps->stacksize = STACK_INIT_SIZE;
    return OK;
}
// 销毁栈
void DestroyStack(SeqStack *ps)
{
    assert(ps != nullptr);
    free(ps->base);
    ps->base = nullptr;
    ps->top = 0;
    ps->stacksize = 0;
    delete ps;
}
// 置为空栈
void ClearStack(SeqStack *ps)
{
    assert(ps != nullptr);
    ps->top = 0;
}
// 返回栈的元素个数，即栈的长度
int StackLength(const SeqStack *ps)
{
    assert(ps != nullptr);
    return ps->top;
}
// 若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const SeqStack *ps)
{
    assert(ps != nullptr);
    return ps->top == 0;
}
// 若栈为满栈，则返回TRUE,否则返回FALSE
bool StackFull(const SeqStack *ps)
{
    assert(ps != nullptr);
    return ps->top == ps->stacksize;
}
// 入栈val , val为栈顶数据元素
Status Push(SeqStack *ps, SElemType val)
{
    assert(ps != nullptr);
    if (StackFull(ps))
    {
        ps->base = (SElemType *)realloc(ps->base, (ps->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!ps->base)
            exit(_OVERFLOW);
        ps->stacksize += STACKINCREMENT;
    }
    ps->base[ps->top++] = val;
    return OK;
}
// 若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const SeqStack *ps, SElemType *pval)
{
    assert(ps != nullptr);
    if (StackEmpty(ps))
        return ERROR;
    *pval = ps->base[ps->top - 1];
    return OK;
}
// Status GetTop(const SeqStack *ps,ElemType &val);
// 若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR
Status Pop(SeqStack *ps, SElemType *pval)
{
    assert(ps != nullptr);
    if (StackEmpty(ps))
        return ERROR;
    *pval = ps->base[--ps->top];
    return OK;
}

void print(SeqStack *ps)
{
    assert(ps != nullptr);
    for (int i = 0; i < ps->top; i++)
        cout << ps->base[i] << " ";
    cout << endl;
}

int main()
{
    SeqStack ps;
    InitStack(&ps);

    for (int i = 0; i < 100; i++)
        Push(&ps, i);

    print(&ps);

    return 0;
}