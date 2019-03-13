//
// Created by liuhongwei on 19-3-9.
//

#include <iostream>
#include "list.h"

using namespace std;

int main() {

    list L, *l = &L;
    cout << "请输入需要的操作：\n1 创建线性表\n2 插入数据\n3 查找数据\n4 删除数据\n5 清空线性表\n6 退出" << endl;
    while (1) {
        int n;
        cin >> n;
        int pos;
        int n1;
        status s;
        switch (n) {
            case 1:
                s = list_init(l);
                if (s == success)
                    cout << "创建成功！" << endl;
                else
                    cout << "创建失败！" << endl;
                break;
            case 2:
            {
                cout << "请输入插入的元素值：" << endl;
                //int pos, elem;
                cin >> pos;
                node *elem=new (node);
                elem->data=pos;
                s = list_insert(l, elem);
                if (s == success)
                    cout << "插入成功,目前有" << list_size(l) << "个元素" << endl;
                else if (s == fatal)
                    cout << "线性表空间已满！" << endl;
                else
                    cout << "超出范围！" << endl;
                break;
            }
            case 3:
            {
                cout << "按值查找请按：1,按位置查找请按：2" << endl;
                    //int n1;
                cin >> n1;
                if (n1 == 1)
                {
                    cout << "输入需要查找的数值：" << endl;
                    cin >> pos;
                    s = list_locate(l, pos, n1);
                    if (s == success)
                        cout << pos << "在线性表第" << n1 << "个位置处" << endl;
                    else if(s==fatal)
                        cout << "线性表为空！" << endl;
                    else if(s==fail)
                        cout<<"查无此值！"<<endl;
                }
                else
                {
                    cout << "输入需要查找的位置：" << endl;
                    cin >> pos;
                    int e;
                    s = list_retrival(l, pos, e);
                    if (s == success)
                        cout << "查找成功，位置" << pos<< "的元素为" << e << endl;
                    else if (s == fatal)
                        cout << "查找失败" << endl;
                    else
                        cout << "超出边界" << endl;
                }
                break;
            }
            case 4:
            {
                cout << "输入需要删除的位置：" << endl;
                cin >> pos;
                s = list_delete(l, pos);
            if (s == success)
                cout << "删除成功,还剩" << list_size(l) << "个元素" << endl;
            else if (s == fail)
                cout << "删除失败,线性表为空!" << endl;
            else
                cout << "超出线性表范围！" << endl;
            break;
            }
            case 5:
            {
                s=list_clear(l);
                if (s == success)
                    cout << "已清空线性表" << endl;
                else
                    cout << "清空失败" << endl;
                break;
            }
                default:
                    break;
            }
                if (n == 6)
                    break;
        }
        //orderlist_clear(l);
        list_destroy(l);
        return 0;
    }
