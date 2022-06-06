#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"

static Node *AVLTree_create_node(ElementType key, Node *left, Node *right)
{
    Node *p;
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;

    p->key = key;
    p->height = 0;
    p->left = left;
    p->right = right;

    return p;
}

int AVL_Height(AVLTree tree)
{
    return HEIGHT(tree);
}

Node *Inter_Search(AVLTree x, ElementType key)
{
    while ((x != NULL) && (x->key != key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

Node *AVL_minimum(AVLTree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->left != NULL)
        tree = tree->left;

    return tree;
}

Node *AVL_maximum(AVLTree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->right != NULL)
        tree = tree->right;

    return tree;
}

static Node *LL_Rotation(AVLTree k2)
{
    AVLTree k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = MAX(HEIGHT(k2->left), HEIGHT(k2->right) + 1);
    k1->height = MAX(HEIGHT(k1->left), k2->height) + 1;

    return k1;
}

static Node *RR_Rotation(AVLTree k1)
{
    AVLTree k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = MAX(HEIGHT(k1->left), HEIGHT(k1->right) + 1);
    k2->height = MAX(HEIGHT(k2->right), k1->height) + 1;

    return k2;
}

static Node *LR_Rotation(AVLTree k3)
{
    k3->left = RR_Rotation(k3->left);

    return LL_Rotation(k3);
}

static Node *RL_Rotation(AVLTree k1)
{
    k1->right = LL_Rotation(k1->right);

    return RR_Rotation(k1);
}

Node *AVL_Insert(AVLTree tree, ElementType key)
{
    if (tree = NULL)
    {
        //新建节点
        tree = AVLTree_create_node(key, NULL, NULL);
        if (tree == NULL)
        {
            printf("ERROR: create node failed!\n");
            return NULL;
        }
    }
    else if (key < tree->key) //应该将key插入到tree左子树的情况
    {
        tree->left = AVL_Insert(tree->left, key);
        if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = LL_Rotation(tree);
            else
                tree = LR_Rotation(tree);
        }
    }
    else if (key > tree->key) //应该将key插入到tree右子树的情况
    {
        tree->right = AVL_Insert(tree->right, key);
        if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = RR_Rotation(tree);
            else
                tree = RL_Rotation(tree);
        }
    }
    else
    {
        printf("禁止添加相同节点！\n");
    }
    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return tree;
}

static Node *Delete_Node(AVLTree tree, Node *z)
{
    if (tree == NULL || z == NULL)
        return NULL;

    if (z->key < tree->key) //待删除节点在左子树中
    {
        tree->left == Delete_Node(tree->left, z);
        if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
        {
            Node *r = tree->right;
            if (HEIGHT(r->left) > HEIGHT(r->right))
                tree = RL_Rotation(tree);
            else
                tree = RR_Rotation(tree);
        }
    }
    else if (z->key > tree->key) //待删除节点在右子树中
    {
        tree->right = Delete_Node(tree->right, z);
        if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
        {
            Node *l = tree->left;
            if (HEIGHT(l->right) > HEIGHT(l->left))
                tree = LR_Rotation(tree);
            else
                tree = LL_Rotation(tree);
        }
    }
    else // tree为对应要删除的节点
    {
        //左右节点都要非空
        if ((tree->left) && (tree->right))
        {
            if (HEIGHT(tree->left) > HEIGHT(tree->right))
            {
                /*  如果tree左子树比右子树高，则：
                 *      (01)找出tree左子树中的最大值；
                 *      (02)将该节点赋值给tree；
                 *      (03)删除该最大节点
                 *  类似于用tree的左子树中的最大节点，作为tree的替身
                 *  此时删除左子树中的最大节点，不会破坏AVL树的平衡
                 */
                Node *max = AVL_maximum(tree->left);
                tree->key = max->key;
                tree->left = Delete_Node(tree->left, max);
            }
            else
            {
                /*  如果tree左子树不必右子树高，则：
                 *      (01)找出tree右子树中的最小值；
                 *      (02)将该节点赋值给tree；
                 *      (03)删除该最小节点
                 *  类似于用tree的右子树中的最小节点，作为tree的替身
                 *  此时删除右子树的最小节点，不会破坏AVL树的平衡
                 */
                Node *min = AVL_minimum(tree->right);
                tree->key = min->key;
                tree->right = Delete_Node(tree->right, min);
            }
        }
        else
        {
            Node *tmp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(tmp);
        }
    }
    return tree;
}

Node *AVL_Delete_byval(AVLTree tree, ElementType key)
{
    Node *z;
    if ((z = Inter_Search(tree, key)) != NULL)
    {
        tree = Delete_Node(tree, z);
    }

    return tree;
}

void print_AVLTree(AVLTree tree, ElementType key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)
            printf("%2d is root\n", tree->key);
        else
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

        print_AVLTree(tree->left, tree->key, -1);
        print_AVLTree(tree->right, tree->key, 1);
    }
}

void Destory_AVLTree(AVLTree tree)
{
    if (tree = NULL)
        return;

    if (tree->left != NULL)
        Destory_AVLTree(tree->left);
    if (tree->right != NULL)
        Destory_AVLTree(tree->right);

    free(tree);
}