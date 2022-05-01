#include "Queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(0);
	Q->front->next=NULL;
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* 存储分配失败 */
		exit(0);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	Q->rear=s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* 将欲删除的队头结点暂存给p，见图中① */
	*e=p->data;				/* 将欲删除的队头结点的值赋值给e */
	Q->front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if(Q->rear==p)		/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
		Q->rear=Q->front;
	free(p);
	return OK;
}

Status DestroyQueue(LinkQueue *Q)   /* 销毁队列Q */
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q)  /* 若Q为空队列,则返回TRUE,否则返回FALSE */
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)    /* 求队列的长度 */
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		i++;
		p=p->next;
	}
	return i;
}