//
// Created by liuhongwei on 19-5-5.
//

#ifndef STACK_ARR_STACK_A_H
#define STACK_ARR_STACK_A_H

#include <iostream>

class stack_a
{
public:
    int top();//数组长度
    stack_a(int w):n(w),_top(-1){}
    ~stack_a()
    {
        delete []p;
    }
    bool push(int e);
    int pop();
    bool empty();
    bool full();
    //bool creat(int m=50);
private:
    int n;//数组预留元素空间
    int *p=new int[n];
    int _top;//数组长度
};


#endif //STACK_ARR_STACK_A_H
