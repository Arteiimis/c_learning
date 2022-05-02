#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 100

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_SIZE];

typedef struct{
    int level, order;
}Position;

TElemType Nil=0;
int TreeIndex = 1;

Status InitBiTree(SqBiTree T);
Status CreateBiTree(TElemType elem_num[], SqBiTree T);
void LevelOrderTraverse(SqBiTree T);
void Print(SqBiTree T);
TElemType Value(SqBiTree T,Position e);
int BiTreeDepth(SqBiTree T);

int main() {
    TElemType elem_num[MAX_SIZE] = {0};
    int tape, count;
    printf("请输入总药片数量：");
    scanf("%d", &tape);
    elem_num[TreeIndex] = tape;
    
    for(TreeIndex; elem_num[TreeIndex] > 2; TreeIndex += 1) {
        TreeIndex += 1;
        elem_num[TreeIndex] = elem_num[TreeIndex / 2] / 2;
        elem_num[TreeIndex + 1] = (elem_num[(TreeIndex + 1) / 2] / 2) + (elem_num[(TreeIndex + 1) / 2] % 2);
            tape = (tape - 1)/2 + 1;
    }
    for(int i = 1; elem_num[i] != 0; i++){
        if(elem_num[i] < 2)
            elem_num[i] = 0;
        if(elem_num[i] >= 2)
            count++;
    }
    elem_num[0] = count;

    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(elem_num, T);
    printf("-----------------------------------------------------\n");
    printf("按层输出的二叉树图：\n");
    Print(T);
    printf("-----------------------------------------------------\n");
    printf("层序遍历得到的二叉树表：\n");
    LevelOrderTraverse(T);
    printf("-----------------------------------------------------\n");
}

Status InitBiTree(SqBiTree T) {
    int i;
    for( i = 0; i < MAX_SIZE; i++)
        T[i] = Nil;
}

Status CreateBiTree(TElemType elem_num[], SqBiTree T) {
    int i;
    for(i = 0; i < elem_num[0]; i++) {
        if(elem_num[i + 1] == 0) {
            T[i] = Nil;
        } else {
            T[i] = elem_num[i + 1];
        }
    }
    while(i < MAX_SIZE) {
        T[i] = Nil;
        i++;
    }
}

void LevelOrderTraverse(SqBiTree T) {
    int i = MAX_SIZE-1, j;
    int sum = 0, temp = 0;
    while(T[i] == Nil)
        i--;
    for(j = 0; j <= i; j++){
        if(T[j] != Nil){
            printf("%d ", T[j]);
            if (T[j] > 4) {
                sum += T[j];
            } else if(T[j] <= 4) {
                temp = (T[j] + 1) * T[j] / 2;
                sum += temp;
            }
        }
    }
    printf("\n");
    printf("层序循环过后得到的最小污染数为：%d\n", sum);
}

void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("第%d层: ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%-3d ",k,e);
		}
		printf("\n");
	}
}

TElemType Value(SqBiTree T,Position e)
{ 
	return T[(int)powl(2,e.level-1)+e.order-2];
}

int BiTreeDepth(SqBiTree T)
{ 
    int i, j = -1;
    for(i = MAX_SIZE-1 ; i >= 0; i--)
        if(T[i] != Nil)
            break;
    i++; 
    do{
        j++;
    }while(i>=powl(2,j));
    return j;
}