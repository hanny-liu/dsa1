//
// Created by liuhongwei on 19-5-16.
//

#ifndef BTREEORDER_BTREE_H
#define BTREEORDER_BTREE_H

#include <iostream>
template <typename T>
class node
{
public:
    T data;//数据
    node * left=NULL;//左节点
    node * right=NULL;//右节点
};
template <typename T>
void addnode(node<T> * n,node<T> *l)
{
    if(n->data<l->data)
        l->left=n;
    else
        l->right=n;
}
template <typename T>
void inorder(node<T> * b)
{
    if(b!=NULL)
    {
        inorder(b->left);
        std::cout<<b->data<<std::endl;
        inorder(b->right);
    }
}
template <typename T>
void preorder(node<T> * b)
{
    if(b!=NULL)
    {
        std::cout<<b->data<<std::ends;
        preorder(b->left);
        preorder(b->right);
    }
}
template <typename T>
void postorder(node<T> * b)
{
    if(b!=NULL)
    {
        postorder(b->left);
        postorder(b->right);
        std::cout<<b->data<<std::ends;
    }
}
template <typename T>
node<T> * search(node<T> * ptr,int val)
{
    //node *ini=new node;
    //ini=ptr;
    while(1)
    {
        if(ptr==NULL)
        {
            return ptr;
        }
        if(val<ptr->data)
        {
            ptr=ptr->left;
        }
        else if(val>ptr->data)
        {
            ptr=ptr->right;
        }
        else
            return ptr;
    }
}
template <typename T>
node<T> * create_btree(node<T> * ptr,int val)
{
    node<T> *p=new node<int>;
    p->data=val;
    node<T> *back,*current;
    current=ptr;
    if(ptr==NULL)
    {
        ptr=p;
        return ptr;
    } else
    {
        while(current!=NULL)
        {
            back=current;
            if(val>current->data)
                current=current->right;
            else
                current=current->left;
        }
        if(val>back->data)
            back->right=p;
        else
            back->left=p;
        return p;
    }
}
template <typename T>
void delete_btree(node<T> * ptr,int val)
{
    node<T> *current,*back,*l;
    current=ptr;

    if(current==NULL)
    {
        std::cout<<"无此节点，已退出！"<<std::endl;
        return;
    } else
    {
        current=ptr;
        l=ptr;
        while(current->data!=val)
        {
            l=current;
            if(val>current->data)
                current=current->right;
            else
                current=current->left;
        }
        if(current->left==NULL)
        {
            if(l->left==current)
            {
                l->left=current->left;
                delete current;
            } else
            {
                l->right=current->left;
                delete current;
            }
        }else if(current->right==NULL)
        {
            if(l->left==current)
            {
                l->left=current->right;
                delete current;
            } else
            {
                l->right=current->right;
                delete current;
            }
        } else
        {
            back=current->left;
            if(l->left==current)
            {
                while(back->right!=NULL)
                {
                    back=back->right;
                }
                l->left=back;
                delete current;
            } else
                {
                    while(back->right!=NULL)
                    {
                        back=back->right;
                    }
                    l->right=back;
                    delete current;
                }
        }

           std::cout<<"节点已删除！"<<std::endl;
        }

    }

#endif //BTREEORDER_BTREE_H
