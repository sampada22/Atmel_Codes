#include <iostream>
using namespace std;
class Date {
private:
int d,m,y,leap = 0;
int month_check[7] ={1,3,5,7,8,10,11};
public:
getdata(){
cout<<"Enter date "<<endl;
cin>>d;
cin>>m;
cin>>y;
}
void leapcheck(){
if (y%100 == 0){
if (y % 400 == 0){
leap ++;
}}
else if (y %4 == 0){
leap++;
}
}
showdata(){
cout<<"The next day is:"<<d<<"|"<<m<<"|"<<y<<endl;
}
operator ++ (int ){
if (d == 30)
for (int i = 0; i<7; i++){

}

}

