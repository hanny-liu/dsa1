//
// Created by liuhongwei on 19-5-16.
//

#ifndef QUEUE_Q_H
#define QUEUE_Q_H
#define Maxsize 10

#include <iostream>
using namespace std;
class q{
public:
    q(){}
    int queue[Maxsize];
    int front=-1;
    int rear=-1;
    void enqueue(int item);
    void dequeue(int & item);
    void front_value();
};


#endif //QUEUE_Q_H
