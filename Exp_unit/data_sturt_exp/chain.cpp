#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct pnode
{
    float coef;
    int exp;
    struct pnode *prev;
    struct pnode *next;
} node;

//初始化链表头节点
node *init()
{
    node *head = (node *)malloc(sizeof(node));
    head->coef = 0;
    head->exp = 0;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

//头插法
void head_insert(node *head, float coef, int exp)
{
    node *p = init();
    p->coef = coef;
    p->exp = exp;
    p->next = head->next;
    p->prev = head;
    head->next = p;
    if (p->next != NULL)
    {
        p->next->prev = p;
    }
}

//尾插法
void tail_insert(node *head, float coef, int exp)
{
    for (; head->next != NULL; head = head->next)
        ;
    node *p = init();
    p->coef = coef;
    p->exp = exp;
    head->next = p;
    p->prev = head;
    p->next = NULL;
}

//打印链表
void printer(node *head)
{
    for (; head->next != NULL; head = head->next)
    {
        printf("%.2f*x^%d", head->next->coef, head->next->exp);
        if (head->next->next != NULL)
            printf(" + ");
    }
    printf("\n");
}

//链表归并排序主体
node *merge(node *left, node *right)
{
    node *head = init();
    node *temp = head;
    while (left != NULL && right != NULL)
    {
        if (left->exp < right->exp)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left != NULL)
        temp->next = left;
    else if(right != NULL)
        temp->next = right;

    return head->next;
}

//链表归并排序递归部分
node *Listsort(node *head)
{
    if (head->next == NULL || head->next->next == NULL)
        return head;
    node *fast = head->next;
    node *slow = head->next;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *mid = slow->next;
    slow->next = NULL;
    node *left = Listsort(head);
    node *right = Listsort(mid);

    return merge(left, right);
}

//多项式合并同类项
node *Node_merge(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->exp == temp->next->exp)
        {
            temp->coef += temp->next->coef;
            node *p = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL)
                temp->next->prev = temp;
            free(p);
        }
        else
            temp = temp->next;
    }

    return head;
}

//多项式相加
node *add(node *head1, node *head2)
{
    node *final_head = init();
    node *temp = final_head;
    while (head1->next != NULL)
    {
        temp->next = head1->next;
        head1 = head1->next;
        temp = temp->next;
    }
    while (head2->next != NULL)
    {
        temp->next = head2->next;
        head2 = head2->next;
        temp = temp->next;
    }
    final_head = Listsort(final_head);

    return Node_merge(final_head);
}

//头删法
void head_delete(node *head)
{
    node *p = head->next;
    head->next = p->next;
    if (p->next != NULL)
        p->next->prev = head;
    free(p);
}

//尾删法
void tail_delete(node *head)
{
    for (; head->next->next != NULL; head = head->next);
    node *p = head->next;
    head->next = NULL;
    free(p);
}

bool is_empty(node *head)
{
    if (head->next == NULL)
        return true;
    else
        return false;
}

int main()
{
    node *list1 = init();
    node *list2 = init();

    head_insert(list1, 1, 2);
    head_insert(list1, 2, 1);
    head_insert(list1, 3, 5);
    printf("list1: ");
    printer(list1);
    printf("after sort: ");
    list1 = Listsort(list1);
    printer(list1);

    tail_insert(list2, 1, 2);
    tail_insert(list2, 7, 3);
    tail_insert(list2, 4, 4);
    printf("list2: ");
    printer(list2);
    printf("after sort: ");
    list2= Listsort(list2);
    printer(list2);

    node *final_list = add(list1, list2);
    printf("list1 + list2: ");
    printer(final_list);

    return 0;
}