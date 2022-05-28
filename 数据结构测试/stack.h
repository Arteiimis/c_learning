#ifndef _STACK_H_
#define _STACK_H_   

#define EMPTY_STACK -1
#define MIN_STACK_SIZR 5
#define ElementType int

typedef struct stack_record
{
    ElementType stack_size;     //栈大小
    ElementType top;            //栈顶元素
    ElementType *array;         //栈指针
} STACK;

void makeEmpty(STACK *s);                   //创建空栈
int isEmpty(STACK *s);                      //判断栈是否为空
int isFull(STACK *s);                       //判断栈是否为满
STACK *create_stack(int maxElements);       //创建给定大小的栈
void dispoesStack(STACK *s);                //销毁给定的栈
void push(ElementType element, STACK *s);   //压栈
ElementType top(STACK *s);                  //获得栈顶元素
void deleteTop(STACK *s);                   //删除栈顶元素
ElementType pop(STACK *s);                  //出栈

#endif