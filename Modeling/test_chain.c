#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef int ElementType;
ElementType Nil;
typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *lchild,*rchild;
}BiTreeNode,*BiTree;

int TreeIndex = 0;
ElementType elem_num[MAX_SIZE] = {20, 10, 5, 3, 2, 5, 10, 0, 0};//此处输入等待转换为二叉树的数组

void CreateBiTree(ElementType elem_num[], BiTree *T);
int InitBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);

int main() {
    BiTree T;
    InitBiTree(&T);
    CreateBiTree(elem_num, &T);
    PreOrderTraverse(T);
}

void CreateBiTree(ElementType elem_num[], BiTree *T) {
    ElementType ch;
    ch = elem_num[TreeIndex++];

    if(ch == 0)
        *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data = ch;
        CreateBiTree(elem_num, &((*T)->lchild));
        CreateBiTree(elem_num, &((*T)->rchild));
    }
}

int InitBiTree(BiTree *T) {
    *T = NULL;
}

void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%d ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
