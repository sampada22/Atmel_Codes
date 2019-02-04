#include<iostream>
using namespace std;
class com
{
private:
    float re;
    float im;
public:
    com()
    {
        re=0;
        im=0;
    }
    friend istream& operator>>(istream &is, com &c);
    friend ostream& operator<<(ostream &os,com &c);
};
istream& operator>>(istream &is ,com &c)
{
    is>>c.re>>c.im;
    return is;
}
ostream& operator<<(ostream &os,com &c)
{
    os<<c.re<<"+i"<<c.im<<flush;
    return os;
}
int main()
{
    com c1;
    cout<<"enter the complex no "<<endl;
    cin>>c1;
    cout<<"the entered complex no. is"<<endl<<c1;
    return 0;
}
