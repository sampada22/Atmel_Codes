#include <iostream>
using namespace std;
#define NUM 4
template<class T>
void sum(T *a)
{
    static T result;
    for (int i=0;i<=NUM;i++)
    {
        result+=a[i];
    }
        cout<<"the result is "<<result<<endl;
}
int main()
{
    int x[]={1,2,3,4,5};
    float y[]={2.2,2.3,2.4,2.5,2.7};
    sum(x);
    sum(y);
    return 0;
}
