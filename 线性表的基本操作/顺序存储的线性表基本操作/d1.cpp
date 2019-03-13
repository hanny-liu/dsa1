//
// Created by liuhongwei on 19-3-7.
//
#include "d1.h"

//初始化顺序线性表
status orderlist_init(orderlist  *L)
{
    status s=success;
    L->list_size=maxsize;
    L->p=(int *)malloc(sizeof(int)*L->list_size);
    L->length=0;
    if(L->p==NULL)
        s=fail;
    return s;
}

//销毁线性表
void orderlist_destroy(orderlist *L)
{
    free(L->p);
}
//清空线性表的元素
status orderlist_clear(orderlist *L)
{
    status s=fail;
    for(int i=0;i<L->length;)
        orderlist_delete(L,i);
    if(L->length==0)
        s=success;
    return s;
}
//线性表是否为空
status  orderlist_empty(orderlist  *L)
{
    status s=fail;
    if(L->length!=0)
        s=success;
    return s;
}
//线性表的元素个数
int orderlist_size(orderlist *L)
{
    return L->length;
}
//按位置查找线性表中的值
status orderlist_retrival(orderlist *L,int pos,int *elem)//elem需要指向对象的指针，所以可以先赋值给p,即L->p
{
    status s = range_error;
    if (orderlist_empty(L)==success)//必须确定线性表是否为空
    {
        if (pos >= 0 && pos <L->length)
        {
            *elem =L->p[pos];
            s = success;
        }
    }
    else
        s=fatal;
    return s;
}
//按值查找线性表中的值
status orderlist_locate(orderlist *L,int elem,int & pos)
{
    status s=fail;
    if(L)
    {
        for(int i=0;i<=L->length;i++)
        {
            if(L->p[i]==elem)
            {
                pos=i;
                s=success;
            }
        }
    }
    return s;
}
//插入元素,需要检查事先分配的空间是否装满元素
status orderlist_insert(orderlist *L,int pos,int elem)
{
    status s=range_error;
    if(pos>=0&&pos<=L->length)
    {
        if(L->length<L->list_size)
        {
            for(int i=L->length+1;i>pos;i--)
            {
                L->p[i]=L->p[i-1];
            }
            L->length++;
            L->p[pos]=elem;
            s=success;
        }
        else
            s=fatal;
    }
    return s;
}
//删除某个位置上的元素值
status orderlist_delete(orderlist *L,int pos)
{
    status s=fail;
    if(L)
    {
        if(pos>=0&&pos<L->length)
        {
            for(int i=pos;i<=L->length;i++)
            {
                L->p[i]=L->p[i+1];
                s=success;
            }
            L->length--;
        }
        else
            s=range_error;
    }
    return s;
}
//求线性表的前驱指针
status orderlist_prior(orderlist *L,int pos,int *elem)
{
    status s=range_error;
    if(L)
    {
        if(pos>0&&pos<=L->length)
        {
            *elem=L->p[pos-1];
            s=success;
        }
    } else
        s=fatal;

    return s;
}

//求线性表的后继指针
status orderlist_next(orderlist *L,int pos, int *elem)
    {
        status s=range_error;
        if(L)
        {
            if(pos>=0&&pos<L->length)
            {
                *elem=L->p[pos+1];
                s=success;
            }
        } else
            s=fatal;
        return s;
    }