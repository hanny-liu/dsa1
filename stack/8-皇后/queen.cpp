//
// Created by liuhongwei on 19-5-8.
//
#pragma once

#include <iostream>
#include "stack.h"
#include <string>
#include <Eigen/Core>
#include <vector>
using namespace Eigen;
using namespace std;

int flag;

int hxcheck(int i,int j,Matrix<int,8,8> &M)
{
    int f=1;
    for(int n=0;n<8;n++)
    {
        if(M(i-1,n)==1&&n!=j)
        {
            f=0;
            break;
        }

    }
    return f;
}
int zxcheck(int i,int j,Matrix<int,8,8> &M)
{
    int f=1;
    for(int n=0;n<8;n++)
    {
        if(M(n,j)==1&&n!=i)
        {
            f=0;
            break;
        }

    }
    return f;
}
int leftcheck(int i,int j,Matrix<int,8,8> &M)
{
    int f=1;
    if((i-1)>=0&&(j-1)>=0)
    {
        for(int m=i-1,n=j-1;m>=0&&n>=0;m--,n--)
        {
            if(M(m,n)==1)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        {
            for(int m=i+1,n=j+1;m<=7&&n<=7;m++,n++)
            {
                if(M(m,n)==1)
                {
                    f=0;
                    break;
                }
            }
        }
    } else
    {
        for(int m=i+1,n=j+1;m<=7&&n<=7;m++,n++)
        {
            if(M(m,n)==1)
            {
                f=0;
                break;
            }
        }
    }

    return f;

}
int rightcheck(int i,int j,Matrix<int,8,8> &M)
{
    int f=1;
    if((i-1)>=0&&(j+1)<=7)
    {
        for(int m=i-1,n=j+1;m>=0&&n<=7;m--,n++)
        {
            if(M(m,n)==1)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        {
            for(int m=i+1,n=j-1;m<=7&&n>=0;m++,n--)
            {
                if(M(m,n)==1)
                {
                    f=0;
                    break;
                }
            }
        }
    } else
    {
        for(int m=i+1,n=j-1;m<=7&&n>=0;m++,n--)
        {
            if(M(m,n)==1)
            {
                f=0;
                break;
            }
        }
    }
    return f;
}
int check(int i,int j,Matrix<int,8,8> &M)
{
    int f;
    f=hxcheck(i,j,M);
    if(f==1)
    {
        f=zxcheck(i,j,M);
        if(f==1)
            f=leftcheck(i,j,M);
            if(f==1)
            {
                f=rightcheck(i,j,M);
                if(f==1)
                    return f;
            }
    } else
        f=0;
    return f;

}

int main()
{
    stack sz;
    Matrix<int,8,8> M=Matrix<int,8,8>::Zero();
    int i,j;
    i=rand()%8;
    j=rand()%8;
    sz.push(i,j);
    M(i,j)=1;
    //int ri(0),rj(0);
    while(1)
    {
        if(i-1>=0)
        {
            i=i-1;
        }
        else
            i++;
        flag=check(i,j,M);
        if(flag==1)
            sz.push(i,j);
        else
        {
            if((j-1)>=0)
                j--;
            flag=check(i,j,M);
            if(flag==1)
                sz.push(i,j);
            else
                continue;
        }
        if(sz.size()==8)
            break;
    }
    for(int i=0;i<=sz.size();i++)
        cout<<"("<<sz.top().i<<","<<sz.top().j<<")"<<ends;
    cout<<endl;
}