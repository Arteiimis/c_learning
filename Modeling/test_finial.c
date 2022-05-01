#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

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
TElemType elem_num[MAX_SIZE] = {9, 20, 10, 10, 5, 5, 0, 0, 3, 2};
int elem_num_index = 1;

Status InitBiTree(SqBiTree T);
Status CreateBiTree(TElemType elem_num[], SqBiTree T);
void LevelOrderTraverse(SqBiTree T);

int main() {
    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(elem_num, T);
    LevelOrderTraverse(T);
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
    while(T[i] == Nil)
        i--;
    for(j = 0; j <= i; j++)
        if(T[j] != Nil)
            printf("%d ", T[j]);
    printf("\n");
}