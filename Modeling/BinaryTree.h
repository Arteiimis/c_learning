#ifndef BinaryTree_h
#define BinaryTree_h
#define MAX_SIZE 100

#include "math.h"  
#include "time.h"
#include<stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType;  /* 树结点的数据类型，目前暂定为整型 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

typedef struct
{
	int level,order; /* 结点的层,本层序号(按满二叉树计算) */
}Position;

TElemType Nil=0; /*  设整型以0为空 */


typedef struct BinaryTreeNode {
    char data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BinaryTreeNode;

int addLeftChile(BinaryTreeNode* curNode, char leftData);
int addRightChild(BinaryTreeNode* curNode, char rightData);
void LevelOrderTraverse(SqBiTree T);

#endif