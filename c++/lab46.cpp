#include<iostream>
using namespace std;
class counter
{
private:
static int count;
int num;

public:
counter()
       {
              static int count=0;
              count++;
              num=count;
       }
void showdata()
       {
              cout<<"The Serial number of this object is: "<<num<<endl;

       }
       ~counter(){
       cout<<"out of dcopr";
       }
};

int main()
       { counter c[3];
              for(int i=0;i<3;i++)
              {
                     c[i].showdata();
              }
       }

