//
// Created by liuhongwei on 19-3-9.
//

#include "list.h"
#include <stdlib.h>

//初始化顺序线性表
status list_init(list  *L)//初始化顺序线性表
{
    status s=success;
    node *e=new (node);
    L->pr=e;
    L->p=L->pr;
    L->length=0;
    return s;
}
//销毁线性表
void list_destroy(list *L)
{
    delete L->pr;
}

//清空线性表的元素
status list_clear(list *L)
{
    status s=fail;
    int j=1;
    while (L->length>0)
    {
        list_delete(L,j);
    }
    if(L->p->next->next==NULL&&L->pr->next->next==NULL)
        s=success;
    return s;
}

//线性表中元素个数
status list_empty(list   *L)//线性表中元素个数
{
    status s=fail;
    if(L->length==0)
        s=success;
    return s;
}

//线性表的大小
int list_size(list  *L)//线性表的大小
{
    return L->length;
}

//按位置查找
status list_retrival(list  *L,int &pos,int &e)
{
    status s=fail;
    if(L)
    {
        L->p=L->pr;
        if(pos>=0&&pos<=L->length)
        {
            for(int i=0;i<pos;i++)
            {
                L->p=L->p->next;
            }
            e=L->p->data;
            s=success;
        }
        else
            s=range_error;
    }
    return s;
}

//按值查找
status list_locate(list *L,int &elem,int &pos)
{
    status s=fatal;
    if(L)
    {
        L->p=L->pr;
        for(int i=0;i<=L->length;i++)
        {
            if(L->p->data!=elem)
            {
                L->p=L->p->next;
                if(i==L->length)
                {
                    s=fail;
                    break;
                }
            }
            else
            {
                pos=i;
                s=success;
                break;
            }
        }

    }
    return s;
}

//插入元素
status list_insert(list *L,node * elem)//插入元素//动态分配空间！！！！！
{
    status s=fail;
    if(L->length!=0)
    {
        node * tmp=L->pr->next;
        L->p= elem;
        L->pr->next= L->p;
        elem->next=tmp;
        L->length++;
        s=success;
    }
    else
    {
        L->pr->next= elem;
        L->p=elem;
        L->length++;
        s=success;
    } /*else if(L->length==1)
    {
        L->p=elem;
        L->pr->next=elem;
        L->length++;
        s=success;
    }*/

    return  s;
}

//删除某个位置上的元素值
status list_delete(list *L,int &pos)//删除某个位置上的元素值
{
    status s=fail;
    if(L)
    {
        L->p=L->pr;
        if(pos>0&&pos<L->length)
        {

            for(int i=0;i<pos-1;i++)
            {
                L->p=L->p->next;
            }
            node * tmp=L->p->next->next;
            delete L->p->next;
            L->p->next=tmp;
            L->length--;
            s=success;
        }
        else if(pos==L->length)
        {
            for(int i=0;i<pos-1;i++)
            {
                L->p=L->p->next;
            }
            delete L->p->next->next;
            delete L->p->next;
            L->length--;
            s=success;
        } else
            s=range_error;
    }
    return  s;
}

//求线性表的后继指针
status list_next(list *L,int &pos,node *elem)
{
    status s=fail;
    if(L)
    {
        L->p = L->pr;
        if (pos >= 0 && pos < L->length )
        {
            for (int i = 0; i < pos; i++)
            {
                L->p = L->p->next;
            }
            elem = L->p->next;
            s = success;
        } else
            s=range_error;
    }
    return s;
}