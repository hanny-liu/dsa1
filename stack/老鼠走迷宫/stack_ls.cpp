//
// Created by liuhongwei on 19-5-5.
//

#include "stack_ls.h"
using namespace std;
point stack_ls::top()
{
    if(empty())
    {
        cout<<"栈空，无返回值！"<<endl;
    } else
    {
        return point(_top->s_i,_top->s_j);
    }
}
int stack_ls::push(int i,int j)
{
    node *l=new node;
    if(len==0)
    {
        l->s_i=i;
        l->s_j=j;
        l->next= nullptr;
        p->next=l;
        _top=l;
    }
    else
    {
        l->s_i=i;
        l->s_j=j;
        l->next= _top;
        _top=l;
        p->next=l;
    }
    len++;
    return 1;
}
int stack_ls::size()
{
    return len;
}
int stack_ls::pop()
{
    if(empty())
    {
        cout<<"栈空，无法弹出元素！"<<endl;
        return -1;
    }
    else
    {
        p->next=_top->next;
        delete _top;
        _top=p->next;
        len--;
        return 1;
    }
}
bool stack_ls::empty()
{
    if(p->next== nullptr&&len==0)
        return true;
    else
        return false;
}