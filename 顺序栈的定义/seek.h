//
// Created by liuhongwei on 19-3-18.
//

#ifndef SEEK_SEEK_H
#define SEEK_SEEK_H


class orderstack {
public:
    int top;//顺序栈内的元素个数
    int size;//空间大小
    char *p;//动态分配固定空间

};

enum status{
    success,fail,fatal,range_error
};
//顺序栈初始化
status stack_init(orderstack *l);

//销毁栈
void stack_destroy(orderstack *l);

//栈的长度
int length_stack(orderstack *l);

//栈是否为空
bool stack_empty(orderstack *l);

//清空栈
status stack_clear(orderstack *l);

//查看栈顶元素
status stack_top(orderstack *l,  char & elem);

//入栈
status stack_push(orderstack *l, char & elem);

//出栈
status stack_pop(orderstack *l,char & elem);


#endif //SEEK_SEEK_H
