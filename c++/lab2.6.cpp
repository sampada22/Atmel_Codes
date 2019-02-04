#include <iostream>
using namespace std;
void salary(int c, int o, int s, int p){
cout <<"Salary of CEO :"<<c<<endl;
cout <<"Salary of officer :"<<o<<endl ;
cout <<"Salary of System Analyst :"<<s<<endl;
cout <<"Salary of Programmer :"<<p<<endl;
}
int main(){
int a1,a2,a3,a4;
a1 = 35000+0.09*35000;
a2 = 25000 + 0.1 *25000;
a3 = 24000 + 0.12*24000;
a4 = 18000 +0.12*18000;
salary(a1,a2,a3,a4);
}
