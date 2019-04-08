//
// Created by liuhongwei on 19-3-18.
//
#include <iostream>
#include "seek.h"

using namespace std;

int main()
{
    cout<<"请输入括号运算符：\n输入#退出程序"<<endl;
    char n;
    orderstack *l,L;
    l=&L;
    stack_init(l);
    while(n!='#')
    {
        cin>>n;
        if(n=='('||n=='{'||n=='[')
            stack_push(l,n);
        else
        {
            char elem;
            //elem=&e;
            stack_top(l,elem);
            //cout<<e<<endl;
            if(elem=='(')
                if(n==')')
                {
                    stack_pop(l,elem);
                }
                else
                {
                    stack_clear(l);
                    stack_destroy(l);
                    cout<<"匹配失败！"<<endl;
                    break;
                }
            else if(elem=='[')
                if(n==']')
                    stack_pop(l,elem);
                else
                {
                    stack_clear(l);
                    stack_destroy(l);
                    cout<<"匹配失败！"<<endl;
                    break;
                }
            else if(elem=='{')
                if(n=='}')
                    stack_pop(l,elem);
                else
                {
                    stack_clear(l);
                    stack_destroy(l);
                    cout<<"匹配失败！"<<endl;
                    break;
                }
        }

    }


}