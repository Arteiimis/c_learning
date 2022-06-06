#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define ElementType int

typedef struct TreeNode
{
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void createTree(Node **T)
{
    ElementType data;
    scanf("%d", &data);
    if (data == -1)
    {
        *T = NULL;
    }
    else
    {
        *T = (Node *)malloc(sizeof(struct TreeNode));
        (*T)->data = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*T)->left));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*T)->right));
    }
}

void pre_order(Node *T)
{
    if (T != NULL)
    {
        printf("%d ", T->data);
        pre_order(T->left);
        pre_order(T->right);
    }
}

void in_order(Node *T)
{
    if (T != NULL)
    {
        in_order(T->left);
        printf("%d ", T->data);
        in_order(T->right);
    }
}

void post_order(Node *T)
{
    if (T != NULL)
    {
        post_order(T->left);
        post_order(T->right);
        printf("%d ", T->data);
    }
}

void level_order(Node *T)
{
    QUEUE *q = create_queue(100);

    while (T != NULL)
    {
        printf("%d", T->data);
        if (T->left != NULL)
        {
            en_queue(T->left, q);
        }
        if (T->right != NULL)
        {
            en_queue(T->right, q);
        }
        if (!is_empty(q))
        {
            T = de_queue(q);
        }
        else
        {
            T = NULL;
        }
    }
    dispose_queue(q);
}

int tree_deep(Node *T)
{
    int deep = 0;
    if (T)
    {
        int leftdeep = tree_deep(T->left);
        int rightdeep = tree_deep(T->right);
        deep = leftdeep > rightdeep ? leftdeep + 1 : rightdeep + 1;
    }
    return deep;
}
