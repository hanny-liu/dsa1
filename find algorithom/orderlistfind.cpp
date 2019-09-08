//
// Created by liuhongwei on 19-4-13.
//
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include<stdlib.h>
using namespace std;

void direct_insert_sort(vector<int> &R)
{
    int t=R[0];
    for(int i=1;i<=R.size();i++)
    {
        if(R[i]<R[i-1])
        {
            t=R[i];
            for(int j=i-1;t<R[j];j--)
            {
                R[j+1]=R[j];
                R[j]=t;
            }
        }
    }
}
void shell_insert_sort(vector<int> R,vector<int> d)
{
    for(int k=0;k<d.size()-1;k++)
    {
        int dk=d[k];
        for(int m=1;m<dk;m++)
        {
            for(int i=m+dk;i<R.size()-1;i+=dk)
            {
                if(R[i]<R[i+dk])
                {
                    R[0]=R[i];
                    for(int j=i-dk;j>=0&&R[0]<R[j];j-=dk)
                    {
                        R[j+dk]=R[j];
                        R[j]=R[0];
                    }
                }
            }

        }
    }
}

void bubble_sort(vector<int> &R)
{
    for(int i=1;i<R.size()-1;i++)
    {
        int swap=0;
        for(int j=1;j<R.size()-i;j++)
        {
            if(R[j]>R[j+1])
            {
                R[0]=R[j+1];
                R[j+1]=R[j];
                R[j]=R[0];
                swap=1;
            }
            if(swap==0)
                break;
        }
    }
}
void bubble_modified_sort(vector<int>& R)
{
    int i=R.size();
    while (i>1)
    {
        int lastexchangeindex=1;
        for(int j=1;j<i;j++)
        {
            if(R[j]>R[j+1])
            {
                R[0]=R[j+1];
                R[j+1]=R[j];
                R[j]=R[0];
                lastexchangeindex=j;
            }
        }
        i=lastexchangeindex;
    }
}

int binsearch(vector<int> R,int high,int low,int key)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(R[mid]==key)
            return  mid;
        else if(R[mid]>key)
            binsearch(R,low,mid-1,key);
        else if(R[mid]<key)
            binsearch(R,mid+1,high,key);
    } else
        return -1;
}
int partition(vector<int> R,int low,int high)
{
    int p=R[low];
    while(low<high)
    {
        while(low<high&&R[high]>=p)
        {
            --high;
        }
        R[low]=R[high];
        while (low<high&&R[low]<=p)
        {
            ++low;
        }
        R[high]=R[low];
    }
    R[low]=p;
    return low;
}
void quicksort(vector<int> R,int low,int high)
{
    if(low<high)
    {
        int p=partition(R,low,high);
        quicksort(R,low,p-1);
        quicksort(R,p+1,high);
    }
}

void merge(vector<int> &p,int begin,int middle,int end)
{
    vector<int> pl;
    for(int u=begin;u<=middle;u++)
    {
        pl.push_back(p[u]);

    }
    vector<int> pr;
    for(int u=middle+1;u<=end;u++)
    {
        pr.push_back(p[u]);
    }
    int i(0),j(0),k(begin);
    while(k<=end)
    {
        while(i<pl.size()&&j<pr.size())
        {
            if(pl[i]<=pr[j])
            {
                p[k]=pl[i];
                i++;
                k++;
            } else
            {
                p[k]=pr[j];
                j++;
                k++;
            }
        }
        while(j<pr.size())
        {
            p[k]=pr[j];
            j++;
            k++;
        }
        while(i<pl.size())
        {
            p[k]=pl[i];
            i++;
            k++;
        }
        //k++;
    }
}

void mergesort(vector<int> &p,int begin,int end)
{
    if (begin<end)
    {
        int middle = (begin + end) / 2;
        mergesort(p, begin, middle);
        mergesort(p, middle + 1, end);
        merge(p, begin, middle, end);
    }

}


//二叉树建立，遍历
/*struct bitNode
{
    char data;
    bitNode *lchild, *rchild;
} ;
void createBiTree ( bitNode  *&T )
{
    char ch;
    cin >> ch;
    if ( ch == '#' )
        T = nullptr;
    else
    {
        T = new bitNode;
        T->data = ch;
        createBiTree(T->lchild);
        createBiTree(T->rchild);

    }
}

void operation1(char ch)
{
    cout<<ch<<" ";
}

void preOrder(bitNode *T)
{
    if(T==nullptr)
        return;
    operation1(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void inOrder(bitNode *T)
{
    if(T==nullptr)
        return;

    inOrder(T->lchild);
    operation1(T->data);
    inOrder(T->rchild);
}

void postOrder(bitNode *T)
{
    if(T==nullptr)
        return;

    postOrder(T->lchild);
    postOrder(T->rchild);
    operation1(T->data);
}

/*int main()
{
    bitNode *T=nullptr;
    createBiTree(T);
    cout<<"前序 "<<endl;
    preOrder(T);
    cout<<endl;
    cout<<"中序 "<<endl;
    inOrder(T);
    cout<<endl;
    cout<<"后序 "<<endl;
    postOrder(T);
    return 0;
}*/

 #include <iomanip>//这个头文件是声明一些 “流操作符”的
 //比较常用的有:setw(int);//设置显示宽度，left//right//设置左右对齐。 setprecision(int);//设置浮点数的精确度。
 // 哈夫曼树的结点结构
 struct element
 {
     int weight;        // 权值域
     int lchild, rchild, parent;  // 该结点的左、右、双亲结点在数组中的下标
 };
 // 选取权值最小的两个结点
 void selectMin(element a[],int n, int &s1, int &s2)
 {
     for (int i = 0; i < n; i++)
     {
         if (a[i].parent == -1)// 初始化s1,s1的双亲为-1
         {
             s1 = i;
             break;
         }
     }
     for (int i = 0; i < n; i++)// s1为权值最小的下标
     {
         if (a[i].parent == -1 && a[s1].weight > a[i].weight)
             s1 = i;
     }
     for (int j = 0; j < n; j++)
     {
         if (a[j].parent == -1&&j!=s1)// 初始化s2,s2的双亲为-1
         {
             s2 = j;
             break;
         }
     }
     for (int j = 0; j < n; j++)// s2为另一个权值最小的结点
     {
         if (a[j].parent == -1 && a[s2].weight > a[j].weight&&j != s1)
             s2 = j;
     }
 }
 // 哈夫曼算法
 // n个叶子结点的权值保存在数组w中
 void HuffmanTree(element huftree[], int w[], int n)
 {
    for (int i = 0; i < 2*n-1; i++)    // 初始化，所有结点均没有双亲和孩子
     {
         huftree[i].parent = -1;
         huftree[i].lchild = -1;
         huftree[i].rchild = -1;
     }
     for (int i = 0; i < n; i++)    // 构造只有根节点的n棵二叉树
     {
         huftree[i].weight = w[i];
     }
     for (int k = n; k < 2 * n - 1; k++) // n-1次合并
     {
         int i1, i2;
         selectMin(huftree, k, i1, i2); // 查找权值最小的俩个根节点，下标为i1,i2
         // 将i1，i2合并，且i1和i2的双亲为k
         huftree[i1].parent = k;
         huftree[i2].parent = k;
         huftree[k].lchild = i1;
         huftree[k].rchild = i2;
         huftree[k].weight = huftree[i1].weight + huftree[i2].weight;
     }

 }

 void b_sort(vector<int> &s)
 {
     for(int i=s.size()-1;i>0;i--)
     {
         for(int j=1;j<=i;j++)
         {
             int temp=s[j];
             if(s[j]<s[j-1])
             {
                 s[j]=s[j-1];
                 s[j-1]=temp;
             }
         }
     }
 }

int main()
{
   vector<int> s;
   int j;
   for(int i=0;i<11;i++)
   {
       j=1+rand()%9;
       s.push_back(j);
   }
   for(int i=0;i<s.size()-1;i++)
   {
       cout<<s[i]<<" ";
   }
   cout<<endl;
   b_sort(s);
    for(int i=0;i<s.size()-1;i++)
    {
        cout<<s[i]<<" ";
    }
}
