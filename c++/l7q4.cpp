#include<iostream>
#include<typeinfo>
using namespace std;
class Vehicle
{
public:
    Vehicle(){};
};

class Car: public Vehicle
{

};
 class Bus: public Vehicle
 {

 };

 int main(){
 Vehicle *v,*u;
 Car ford,*f;
 Bus nissan,*n;
 f=&ford;
 n=&nissan;
 v= dynamic_cast< Vehicle *>(f);
 u= dynamic_cast< Vehicle *>(n);
 cout<<"The type of v is: "<< typeid(v).name()<<endl;
 cout<<"The type of u is: "<< typeid(u).name()<<endl;
 }
