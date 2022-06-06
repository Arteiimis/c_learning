#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void makeEmpty(STACK *s)
{
    if (s != NULL)
    {
        s->top = EMPTY_STACK;
    }
}

int isEmpty(STACK *s)
{
    return (s->top == EMPTY_STACK);
}

int isFull(STACK *s)
{
    return (s->top == s->stack_size - 1);
}

STACK *create_stack(int maxElements)
{
    STACK *s;
    if (maxElements < MIN_STACK_SIZR)
    {
        printf("栈容量过小！\n");
        return NULL;
    }
    s = (STACK *)malloc(sizeof(struct stack_record));
    s->array = (ElementType *)malloc(sizeof(ElementType) * maxElements);
    s->stack_size = maxElements;
    makeEmpty(s);

    return s;
}

void dispoesStack(STACK *s)
{
    if (s != NULL)
    {
        free(s->array);
        free(s);
    }
}

void push(ElementType element, STACK *s)
{
    if (!isFull(s))
    {
        s->top++;
        s->array[s->top] = element;
    }
    else
    {
        printf("栈已满！");
    }
}

ElementType top(STACK *s)
{
    if (!isEmpty(s))
    {
        return s->array[s->top];
    }
    else
    {
        printf("空栈，无元素可输出！\n");
        return 0;
    }
}

void deleteTop(STACK *s)
{
    if (!isEmpty(s))
    {
        s->top--;
    }
    else
    {
        printf("空栈，无可删除元素！\n");
    }
}

ElementType pop(STACK *s)
{
    if (!isEmpty(s))
    {
        return s->array[s->top--];
    }
    else
    {
        printf("空栈，无元素可输出！\n");
        return 0;
    }
}