//
// Created by liuhongwei on 19-5-5.
//

#include "stack_a.h"
bool stack_a::push(int e)
{
    if(full())
    {
        std::cerr<<"stack已满，无存储空间"<<std::endl;
        return 0;
    }
    p[++_top]=e;
    return 1;
}
bool stack_a::full()
{
    if(_top==n)
        return true;
    else
        return false;
}
int stack_a::pop()
{
    if(empty())
    {
        std::cout<<"栈已空！"<<std::endl;
        return -1;
    } else
    {
        return p[_top--];
    }
}
bool stack_a::empty()
{
    if(_top==-1)
    {
        return true;
    }
    else
        return false;
}
int stack_a::top()
{
    if(empty())
    {
       std:: cout<<"栈已空，无返回值！"<<std::endl;
        return -1;
    }
    else
        return p[_top];
}