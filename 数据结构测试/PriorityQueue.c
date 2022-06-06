#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

PrioriQueue *init_PQ(int maxEleNum)
{
    PrioriQueue *pq = NULL;
    if (maxEleNum <= 0)
        return NULL; //检查输入大小的合法性
    pq = malloc(sizeof(PrioriQueue));
    if (pq == NULL)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    //下标为零的节点作为哨兵，不储存数据
    pq->eles = malloc((maxEleNum + 1) * sizeof(ElementType));
    if (pq->eles == NULL)
    {
        printf("malloc failed\n");
        free(pq);
        return NULL;
    }
    //初始化成员
    memset(pq->eles, 0, (maxEleNum + 1) * sizeof(ElementType));
    pq->capacity = maxEleNum;
    pq->size = 0;

    return pq;
}

//判满函数
int is_full(PrioriQueue *pq)
{
    if (pq == NULL)
        return false;
    if (pq->capacity == pq->size)
        return true;
    else
        return false;
}

//判空函数
int is_empty(PrioriQueue *pq)
{
    if (pq == NULL)
        return false;
    if (pq->size == 0)
        return true;
    else
        return false;
}

int insert_pq(ElementType val, PrioriQueue *pq)
{
    int i = 0;
    //确保优先级队列非满
    if (is_full(pq))
    {
        printf("PrioriQueue is full!\n");
        return FAILURE;
    }
    printf("inserting %d\n", val);
    //不断上浮元素，直到队列满足优先级队列要素
    for (i = pq->size + 1; pq->eles[i / 2] > val && i > 1; i /= 2)
    {
        pq->eles[i] = pq->eles[i / 2];
    }
    pq->eles[i] = val;
    pq->size++;

    return SUCCESS;
}

int find_min(PrioriQueue *pq, ElementType *val)
{
    if (is_empty(pq))
    {
        printf("PriorityQueue is empty!\n");
        return FAILURE;
    }
    // 0处的元素作为哨兵使用。
    *val = pq->eles[1];

    return SUCCESS;
}

int delete_min(PrioriQueue *pq, ElementType *min)
{
    int i = 1;
    int minchild = 0;
    if (is_empty(pq))
    {
        printf("PriorityQueue is empty!\n");
        return FAILURE;
    }
    //取得队首最小值
    *min = pq->eles[1];
    //暂时取出队尾元素
    ElementType last = pq->eles[pq->size];
    pq->size--;
    if (pq->size == 0)
    {
        pq->eles[i] == 0;
        return SUCCESS;
    }
    //不断下沉空节点
    for (i = 1; i * 2 <= pq->size; i = minchild)
    {
        minchild = i * 2;
        //找到当前节点左右孩子中的最小节点
        if (minchild != pq->size && pq->eles[minchild + 1] < pq->eles[minchild])
            minchild++;
        //如果最后一个元素比空节点处的子节点打，则继续下沉空节点，将该子节点上浮
        if (last > pq->eles[minchild])
            pq->eles[i] = pq->eles[minchild];
        //否则说明last存放位置不会破坏队列性质，直接退出循环
        else
            break;
    }
    pq->eles[i] = last; //将之前保存的队尾节点存放在空节点位置
    return SUCCESS;
}