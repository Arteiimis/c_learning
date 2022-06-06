#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} List_single;

int main()
{
}

//创建链表
List_single *createListNode(int data)
{
    List_single *node = NULL;
    node = (List_single *)malloc(sizeof(List_single));
    if (node == NULL)
    {
        printf("malloc failled!\n");
        return NULL;
    }
    memset(node, 0, sizeof(List_single));
    node->data = data;
    node->next = NULL;
    return node;
}

//对链表进行尾插
void tail_insert(List_single *pH, List_single *new)
{
    List_single *node = pH;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = new;
}

//对链表进行头插
void top_inserd(List_single *pH, List_single *new)
{
    List_single *node = pH;
    new->next = node->next;
    node->next = new;
}

//删除链表中的某个节点
int delete_node(List_single *pH, int data)
{
    List_single *node = pH;
    List_single *prev = NULL;
    while (node->next != NULL)
    {
        prev = node;
        node = node->next;
        if (node->data == data)
        {
            if (node->next != NULL)
            {
                prev->next = node->next;
                free(node);
            }
            else
            {
                prev->next = NULL;
                free(node);
            }
            return 0;
        }
    }
    printf("没有需要删除的节点！\n");
    return -1;
}

void Print_node(List_single *pH)
{
    List_single *node = pH;
    node = node->next;
    while (node->next != NULL)
    {
        printf("data: %d\n", node->data);
        node = node->next;
    }
    printf("data: %d\n", node->data);
}