#pragma once
#include <iostream>
#include <vector>
#include "btree.h"
using namespace std;

int main()
{
    vector<int> vi{7,4,1,5,16,8,11,12,15,9,2};
    node<int> * bt=new node<int>;
    bt->data=7;
    node<int> * current=bt;
    for(int i=1;i<vi.size();i++)
    {
        while(current!=NULL)
        {
            if(vi[i]<current->data)
            {
                if(current->left==NULL)
                {
                    node<int> * pi=new node<int>;
                    pi->data=vi[i];
                    current->left=pi;
                    break;
                } else
                    current=current->left;
            }
            else
            {
                if(current->right==NULL)
                {
                    node<int> * pi=new node<int>;
                    pi->data=vi[i];
                    current->right=pi;
                    break;
                } else
                    current=current->right;
            }

        }
        current=bt;
    }
    preorder(bt);
    cout<<endl;
    inorder(bt);
    postorder(bt);
    cout<<endl;
    node<int> *l=search(bt,13);
    if(l==NULL)
    {
        l=create_btree(bt,13);
        cout<<"已将"<<l->data<<"加入二叉树中！"<<endl;
        inorder(bt);
    }
    else
        cout<<"二叉树中存在："<<l->data<<endl;
    delete_btree(bt,13);
    inorder(bt);
}
