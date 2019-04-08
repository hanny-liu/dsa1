//
// Created by liuhongwei on 19-3-18.
//
#include <iostream>
#include "orderstack.h"

using namespace std;

int main()
{
    cout<<"请输入操作所对应的数字：\n1 创建栈；\n2 入栈；\n3 出栈；\n4查看栈顶元素；\n5 清空栈\n6 退出"<<endl;
    int n;
    orderstack *l;
    orderstack L;
    l=&L;
    status s;
    while(n!=6)
    {
        cin>>n;
        switch (n)
        {
            case 1:
            {
                s=stack_init(l);
                if(s==success)
                    cout<<"创建成功！"<<endl;
                else
                    cout<<"创建失败！"<<endl;
                break;
            }
            case 2:
            {
                cout<<"请输入需要入栈的元素；"<<endl;
                int elem;
                cin>>elem;
                s=stack_push(l,elem);
                if(s==success)
                    cout<<"入栈成功！"<<endl;
                else
                    cout<<"满溢，入栈失败"<<endl;
                break;
            }
            case 3:
            {
                int *elem,i;
                elem=&i;
                s=stack_pop(l,elem);
                if(s==success)
                    cout<<"出栈成功，栈顶元素为"<<*elem<<endl;
                else
                    cout<<"出栈失败"<<endl;
                break;
            }
            case 4:
            {
                int *elem,i;
                elem=&i;
                s=stack_pop(l,elem);
                if(s==success)
                    cout<<"栈顶元素为"<<*elem<<endl;
                else
                    cout<<"无栈顶元素"<<endl;
                break;
            }
            case 5:
            {
                s=stack_clear(l);
                if(s==success)
                    cout<<"已清空栈！"<<endl;
                else
                    cout<<"清空失败！"<<endl;
            }
            default:
                break;
        }
    }
    stack_destroy(l);
    cout<<"已退出程序！"<<endl;
    return 0;
}
