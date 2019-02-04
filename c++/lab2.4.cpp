#include<iostream>
using namespace std;
int max (int &a, int &b){
if (a > b){
a = 100;
}
else b =100;
}
int main(){
int x,y;
cout << "Enter the first temperature"<<endl;
cin>> x;
cout << "Enter the second temperature"<<endl;
cin >>y ;
max(x,y);
cout << "The numbers are"<<x <<"and"<<y<< endl;
return 0;
}
