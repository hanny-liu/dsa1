//
// Created by liuhongwei on 19-5-5.
//

#ifndef STACK_ARR_STACK_LS_H
#define STACK_ARR_STACK_LS_H

#include<iostream>

//首先定义节点
class node
{
public:
    node *next;
    int s_i;//矩阵行索引
    int s_j;//矩阵列索引
};

class point
{
public:
    point(int m=0,int n=0):i(m),j(n){}
    int i;
    int j;
};

class stack_ls
{
public:

    node *_top;//指向栈顶的节点；
    stack_ls():len(0)
    {
        p->next= nullptr;
        p->s_j=1;
        p->s_i=1;
        _top=p;
    }
    ~stack_ls(){delete p;}
    int push(int i,int j);
    int pop();
    bool empty();
    point top();
    int size();
private:
    node *p=new node;//链栈头节点
    int len;
};


#endif //STACK_ARR_STACK_LS_H
