//
// Created by liuhongwei on 19-3-9.
//

#ifndef LIST_H
#define LIST_H

class node{
public:
    int data;//节点结构存储的数据
    node *next;//节点结构指向下一个数据元素的后继指针
};
class list {
public:
    node *p;//链表中指向节点结构的指针，需要动态分配内存
    int length;//list中的元素个数
    node *pr;
};

enum status{
    success,fail,fatal,range_error
};

status list_init(list  *L);//初始化顺序线性表

void list_destroy(list *L);//销毁线性表

status list_clear(list *L);//清空线性表的元素

status list_empty(list   *L);//线性表中元素个数

int list_size(list  *L);//线性表的大小

status list_retrival(list  *L,int &pos,int &e);//查找线性表中的元素位置和元素

status list_locate(list *L,int &elem,int &pos);//输出元素位置

status list_insert(list *L,node *elem);//插入元素

status list_delete(list *L,int & pos);//删除某个位置上的元素值

status list_next(list *L,int pos,int *elem);//求线性表的后继指针

#endif //单链表的基本操作_LIST_H
