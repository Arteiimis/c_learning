#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MinQueueSize 5
#define ElementType int

typedef struct queueRecourd
{
    int capacity;       //队列的最大容量
    int front;          //队首元素下标
    int rear;           //队尾元素下标
    int size;           //队列元素个数
    ElementType *array; //指向动态分配的内存
}QUEUE;

void make_empty(QUEUE *q);                      //创建空队列
int is_empty(QUEUE *q);                         //判断队列是否为空
int is_full(QUEUE *q);                          //判断队列是否为满
QUEUE *create_queue(int maxElement);            //创造一个给定长度的队列
void en_queue(ElementType element, QUEUE *q);   //对应元素入队
ElementType front(QUEUE *q);                    //返回队首元素值，但不删除
ElementType de_queue(QUEUE *q);                 //出队（返回队首元素，并且删除）
void dispose_queue(QUEUE *q);                   //销毁队列

#endif