#pragma once
#include <iostream>
#include "q.h"
using namespace std;

int main() {
    q que;
    for(int i=0;i<8;i++)
    {
        que.enqueue(i);
    }
    int elem;
    que.dequeue(elem);
    cout<<elem<<endl;
    que.dequeue(elem);
    cout<<elem<<endl;
    que.dequeue(elem);
    cout<<elem<<endl;
    que.front_value();

}