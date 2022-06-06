#ifndef _PRIORI_QUEUE_
#define _PRIORI_QUEUE_

#define ElementType int
#define false 0
#define true 1
#define FAILURE 0
#define SUCCESS 1

typedef struct HeapStruct
{
    int capacity;
    int size;
    ElementType *eles;
} PrioriQueue;

PrioriQueue *init_PQ(int maxEleNum);               //初始化优先级队列
int is_full(PrioriQueue *pq);                      //判断队列是否为满
int is_empty(PrioriQueue *pq);                     //判断队列是否为空
int insert_pq(ElementType val, PrioriQueue *pq);   //插入元素，自动上浮或下沉到对应位置
int find_min(PrioriQueue *pq, ElementType *val);   //返回堆顶元素
int delete_min(PrioriQueue *pq, ElementType *min); //删除堆顶元素

#endif