#include <iostream>
using namespace std;
void test(int n)
{
    try{
    if (n==1) throw n;
     if (n==0) throw 'n';
     if (n==-1) throw (1.20000);
     cout<<"end of try block"<<endl;

    }
    catch(char c)
    {
        cout<<"character"<<endl;
    }
    catch( int x)
    {
        cout<<"integer"<<endl;
    }
    catch(double  z)
    {
        cout<<"float"<<endl;
    }
}
void test1(int n)
{
     try{
    if (n==1) throw n;
     if (n==0) throw 'n';
     if (n==-1) throw 1.0;
     }
     catch(...)
     {
         cout<<"master exception:all types caught"<<endl;
     }
}
void divide(double x,double y)
{
    try{
    if (y==0.0)
        throw y;
    else
        cout<<"result is "<<x/y<<endl;

    }
    catch(double)
    {
        cout<<"caught zero error inside the divide function"<<endl;
        throw;
    }

}
int main()
{
    cout<<"test of multiple catch "<<endl;
    test(1);
    test(0);
    test(-1);
    cout<<"test of catching all exceptions by function test1()"<<endl;
    test1(1);
    test1(0);
    test1(-1);
    cout<<"testing rethrowing a exception"<<endl;
    try{
    divide(2.0,1.0);
    divide(2.0,0.0);
    }
    catch(double)
    {
        cout<<"again caught the zero error from the main function"<<endl;
    }
    return 0;
}
