#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void make_empty(QUEUE *q)
{
    if(q != NULL)
    {
        q->front = 1;
        q->rear = 0;
        q->size = 0;
    }
}

int is_empty(QUEUE *q)
{
    return (q->size == 0);
}

int is_full(QUEUE *q)
{
    return (q->size == q->capacity);
}

QUEUE *create_queue(int maxElement)
{
    if(maxElement < MinQueueSize)
    {
        printf("队列长度过短！\n");
        return NULL;
    }
    else
    {
        QUEUE *q = (QUEUE *)malloc(sizeof(struct queueRecourd));
        q->array = (ElementType *)malloc(sizeof(ElementType) * maxElement);
        q->capacity = maxElement;
        make_empty(q);
        return q;
    }
}

static int succ(int value, QUEUE *q)
{
    if(++value == q->capacity)
        value = 0;
    return value;
}

void en_queue(ElementType element, QUEUE *q)
{
    if(!is_full(q))
    {
        q->size++;
        q->rear = succ(q->rear, q);
        q->array[q->rear] = element;
    }
    else
    {
        printf("列表已满！\n");
    }
}

ElementType front(QUEUE *q)
{
    if( !is_empty(q) )
    {
        return q->array[q->front];
    }
    else
    {
        printf("队列为空！\n");
    }
}

ElementType de_queue(QUEUE *q)
{
    if( !is_empty(q) )
    {
        int ret = q->array[q->front];
        q->size--;
        q->front = succ(q->front, q);
        return ret;
    }
    else
    {
        printf("队列为空！\n");
        return 0;
    }
}

void dispose_queue(QUEUE *q)
{
    if(q != NULL)
    {
        free(q->array);
        free(q);
    }
}