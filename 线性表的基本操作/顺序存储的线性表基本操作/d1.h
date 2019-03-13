//
// Created by liuhongwei on 19-3-7.
//

#ifndef D_D1_H
#define D_D1_H
#define maxsize 100

#include <malloc.h>

class orderlist{
public:
    //orderlist():list_size(maxsize),p((int *)malloc(sizeof(int)*list_size)),length(0){}
    int list_size;//顺序线性表的内存大小
    int *p;//定义指向顺序线性表首地址的指针
    int length;//顺序线性表的元素个数

};

enum status{
    success,fail,fatal,range_error
};

status orderlist_init(orderlist  *L);//初始化顺序线性表

void orderlist_destroy(orderlist *L);//销毁线性表

status orderlist_clear(orderlist *L);//清空线性表的元素

status orderlist_empty(orderlist   *L);//线性表中元素个数

int orderlist_size(orderlist  *L);//线性表的大小

status orderlist_retrival(orderlist  *L,int pos,int *elem);//查找线性表中的元素位置和元素

status orderlist_locate(orderlist *L,int elem,int &pos);//输出元素位置

status orderlist_insert(orderlist *L,int pos,int elem);//插入元素

status orderlist_delete(orderlist *L,int pos);//删除某个位置上的元素值

status orderlist_prior(orderlist*L,int pos,int *elem);//求线性表的前驱指针

status orderlist_next(orderlist *L,int pos,int *elem);//求线性表的后继指针
#endif //D_D1_H
