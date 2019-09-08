//
// Created by liuhongwei on 19-5-16.
//

#include "q.h"
void q::enqueue(int item)//入队
{
    rear=(rear+1)%10;
    if(rear==front)
        cout<<"队列已满！"<<endl;
    else
        queue[rear]=item;
}
void q::dequeue(int & item)//出队
{
    if(front==rear)
        cout<<"队列已空！";
    else
    {
        front=(front+1)%10;
        item=queue[front];
    }
}
void q::front_value()
{
    if(front==rear)
        cout<<"空队列！"<<endl;
    else
        cout<<queue[front]<<endl;
}