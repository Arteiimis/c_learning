#ifndef _AVLTREE_
#define _AVLTREE_

#define ElementType int
#define HEIGHT(p) ((p == NULL) ? 0 : ((Node *)(p)->height)) //宏定义高度函数
#define MAX(a, b) ((a) > (b) ? (a) : (b))                   //宏定义最大值函数

typedef struct AVLNode
{
    ElementType key;       //节点值
    int height;            //该节点高度
    struct AVLNode *left;  //左节点
    struct AVLNode *right; //右节点
} Node, *AVLTree;

static Node *AVLTree_create_node(ElementType key, Node *left, Node *right); //创建AVL树
int AVL_Height(AVLTree tree);                                               //返回AVL树的高度
Node *Inter_Search(AVLTree x, ElementType key);                             //迭代查找值，返回值对应的节点
Node *AVL_minimum(AVLTree tree);                                            //返回最小直接点
Node *AVL_maximum(AVLTree tree);                                            //返回最大值节点
static Node *LL_Rotation(AVLTree k2);                                       //左单旋转
static Node *RR_Rotation(AVLTree k1);                                       //右单旋转
static Node *LR_Rotation(AVLTree k3);                                       //左双旋转
static Node *RL_Rotation(AVLTree k1);                                       //右双旋转
Node *AVL_Insert(AVLTree tree, ElementType key);                            //向AVL树中插入数据，并自动维护AVL树
static Node *Delete_Node(AVLTree tree, Node *z);                            //删除给定节点
Node *AVL_Delete_byval(AVLTree tree, ElementType key);                      //按值检索，删除对应节点
void print_AVLTree(AVLTree tree, ElementType key, int direction);           //打印AVL树
void Destory_AVLTree(AVLTree tree);                                         //销毁AVL树

#endif