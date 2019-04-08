//
// Created by liuhongwei on 19-3-14.
//

#include "orderstack.h"
#include <iostream>

//顺序栈初始化
status stack_init(orderstack *l)
{
    status s=success;
    l->size=100;
    l->p=(int*)malloc(l->size* sizeof(int));
    l->top=-1;
    if(l->p==nullptr)
        s=fail;
    return s;
}

//销毁栈
void stack_destroy(orderstack *l)
{
    free(l->p);
}

//栈的长度
int length_stack(orderstack *l)
{
    return l->top;
}

//栈是否为空
bool stack_empty(orderstack *l)
{
    if(l->top==-1)
        return false;
    else
        return true;
}

//清空栈
status stack_clear(orderstack *l)
{
    status s=fail;
    int *elem;
    for(int i=0;i<l->top;)
        stack_pop(l,elem);
    if(l->top==-1)
        s=success;
    return s;
}

//查看栈顶元素
status stack_top(orderstack *l,  int * elem)
{
    status s=fail;
    if(l)
    {
        elem=l->p+l->top;
        s=success;
    }
    return s;
}

//入栈
status stack_push(orderstack *l, int & elem)
{
    status s=range_error;
    if(l->top<l->size)
    {
        l->top++;
        l->p[l->top]=elem;
        s=success;
    }
    return s;
}

//出栈
status stack_pop(orderstack *l,int *elem)
{
    status s=fail;
    if(l->top!=-1)
    {
        *elem=l->p[l->top];
        l->top--;
        s=success;
    }
    return s;
}

