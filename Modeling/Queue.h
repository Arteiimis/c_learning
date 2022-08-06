#ifndef Queue_h
#define Queue_h
#include <stdio.h>
#define MAX_SIZE 100

typedef char Status;
typedef int QElemType; //队列的结点

typedef struct QNode    //结点结构
{
	QElemType data; //数据域
    struct QNode *next; //指针域
}QNode,*QueuePtr;

typedef struct	    //队列的链表结构
{
   QueuePtr front,rear; //队头、队尾指针
}LinkQueue;

Status InitQueue(LinkQueue *Q);//初始化队列
Status EnQueue(LinkQueue *Q,QElemType e);//入队
Status DeQueue(LinkQueue *Q,QElemType *e);//出队
Status DestroyQueue(LinkQueue *Q);//销毁队列
Status QueueEmpty(LinkQueue Q);//判断队列是否为空
int QueueLength(LinkQueue Q);//返回队列长度


#endif