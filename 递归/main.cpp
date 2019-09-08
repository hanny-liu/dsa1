#include <iostream>
using namespace std;
void dif1(int y);
void dif2(int x)
{
    if(x) dif1(x);
}
void dif1(int y)
{
    if(y>0)
        dif2(y-3);
    cout<<y<<ends;
}
int main() {
    dif1(21);
    cout<<endl;
    //system("pause");
    return 0;

}