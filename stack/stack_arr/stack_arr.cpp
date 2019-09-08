//
// Created by liuhongwei on 19-5-5.
//

#pragma once

#include <iostream>
using namespace std;

#include "stack_a.h"

int main()
{
    cout<<"请输入栈存放元素数量："<<ends;
    int n;
    cin>>n;
    stack_a st(n);

    cout<<"请输入操作数字：/n1.入栈;/n2.出栈/n3.返回栈顶元素/n4.清空栈;"<<endl;
    int i;
    while(cin>>i)
    {
        int elem;
        switch (i)
        {
            case 1:
            {
                cout<<"请输入需要压入的元素："<<endl;
                cin>>elem;
                st.push(elem);
                break;

            }
            case 2:
            {
                cout<<st.pop()<<endl;
                break;
            }
            case 3:
            {
                cout<<st.top()<<endl;
                break;
            }
            case 4:
            {
                while(!st.empty())
                {
                    st.pop();
                }
                cout<<"栈已清空！"<<endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;

}
