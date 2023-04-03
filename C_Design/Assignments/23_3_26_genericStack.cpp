#include <bits/stdc++.h>
using namespace std;

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define __OVERFLOW -2

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 1.5

typedef int status;

struct genericStack
{
    int capacity;
    int size;
    int elementSize;
    string type;
    void *base;
};

void initStack(genericStack *s, string type)
{
    s->capacity = STACK_INIT_SIZE;
    s->size = 0;
    if (type == "int")
    {
        s->elementSize = sizeof(int);
        s->base = new int[s->capacity];
        s->type = "int";
    }
    else if (type == "double")
    {
        s->elementSize = sizeof(double);
        s->base = new double[s->capacity];
        s->type = "double";
    }
    else if (type == "char")
    {
        s->elementSize = sizeof(char);
        s->base = new char[s->capacity];
        s->type = "char";
    }
    else
    {
        cout << "Invalid type" << endl;
    }
}

void deleteStack(genericStack *s)
{
    assert(s->base != NULL);
    free(s->base);
    s->base = NULL;
    s->size = 0;
    s->capacity = 0;
}

status stackGrow(genericStack *s)
{
    void *newBase = realloc(s->base, (s->capacity + STACKINCREMENT) * s->elementSize);
    if (newBase == nullptr)
        return __OVERFLOW;
    s->base = newBase;
    s->capacity += STACKINCREMENT;

    return OK;
}

void push(genericStack *s, void *val)
{
    assert(s->base != NULL);
    if (s->size == s->capacity)
        if (!stackGrow(s))
            return;
    char *target = (char *)s->base + s->size * s->elementSize;
    memcpy(target, val, s->elementSize);
    s->size++;
}

void *pop(genericStack *s)
{
    assert(s->base != NULL);
    char *target = (char *)s->base + s->size * s->elementSize;
    void *ans = nullptr;
    memcpy(ans, target, s->elementSize);

    return ans;
}

void print(genericStack *s)
{
    assert(s->base != NULL);
    for (int i = 0; i < s->size; i++)
    {
        char *target = (char *)s->base + i * s->elementSize;
        if (s->type == "int")
            printf("%d ", *(int *)target);
        else if (s->type == "double")
            printf("%lf ", *(double *)target);
        else if (s->type == "char")
            printf("%c ", *(char *)target);
    } 
    printf("\n");
}

int main()
{
    genericStack s_int;
    initStack(&s_int, "int");
    for (int i = 0; i < 20; i++)
        push(&s_int, &i);
    print(&s_int);

    genericStack s_double;
    initStack(&s_double, "double");
    // 插入20个随机浮点数
    for (int i = 0; i < 20; i++)
    {
        double x = (double)rand() / RAND_MAX;
        push(&s_double, &x);
    }
    print(&s_double);

    genericStack s_char;
    initStack(&s_char, "char");
    for (int i = 0; i < 20; i++)
    {
        char x = 'a' + rand() % 26;
        push(&s_char, &x);
    }
    print(&s_char);

    return 0;
}