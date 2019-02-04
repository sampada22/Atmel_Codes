#include<iostream>
using namespace std;
class test{
private:
int x;
public:
test(int a){
x = a;
}
friend bool  operator ==(test t1,test t2);
friend bool operator < (test t1,test t2);
friend bool operator > (test t1,test t2);
friend bool operator != (test t1,test t2);
friend bool operator >= (test t1,test t2);
friend bool operator <= (test t1,test t2);


};
 bool operator == ( test t1, test t2){
return ( t1.x ==  t2.x);
}
bool operator < (test t1,test t2){
return  t1.x <  t2.x;
}
bool operator > (test t1,test t2){
return  t1.x >  t2.x;
}
bool operator != (test t1,test t2){
return  t1.x !=  t2.x;
}
bool operator >=(test t1,test t2){
return t1.x >=  t2.x;
}
bool operator <= (test t1,test t2){
return  t1.x <=  t2.x;
}

int main (){
test t1(5);
test t2(6);
if (t1 == t2){
cout << "Equal"<<endl;

}

if (t1 >= t2){
cout << "Greater than or equal to"<<endl;

}
if (t1 <= t2){
cout << "Less than or equal to"<<endl;

}
if (t1 != t2){
cout << " Not equal"<<endl;

}
if (t1 > t2){
cout << "Gretaer"<<endl;

}if (t1 < t2){
cout << "lesser"<<endl;

}
}
