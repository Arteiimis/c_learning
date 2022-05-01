#include"BinaryTree.h"
#include <assert.h>
#include <stdio.h>

Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}

/* 构造空二叉树T。因为T是固定数组，不会改变，故不需要& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* 初值为空 */
	return OK;
}

Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* 此结点(不空)无双亲且不是根 */
		{
			printf("出现无双亲的非根结点%d\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* 将空赋值给T的后面的结点 */
		i++;
	}

	return OK;
}

/* 层序遍历二叉树 */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* 找到最后一个非空结点的序号 */
	for(j=0;j<=i;j++)  /* 从根结点起,按层序遍历二叉树 */
		if(T[j]!=Nil)
			visit(T[j]); /* 只遍历非空的结点 */
	printf("\n");
}

