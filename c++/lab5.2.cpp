#include<iostream>
using namespace std;
class coord {
private:
int x,y,z;
public:

void getdata(){
cout <<"Enter numbers"<<endl;
cin>>x;
cin>>y;
cin>>z;

}
void showdata1(){
cout<<"Sum:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}
void showdata2(){
cout<<"Difference:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}
friend coord  operator + (coord c1, coord c2);
friend  coord operator - (coord c1, coord c2);
};
 coord operator + (coord c1,coord c2){
coord a;
a.x = c1.x + c2.x;
a.y = c1.y +c2.y;
a.z = c1.z +c2.z;
return a;
}
 coord operator - (coord c1, coord c2){
coord a;
a.x = c2.x - c1.x;
a.y = c2.y -c1.y;
a.z = c2.z -c1.z;
return a;
}
int main(){
coord c1;
coord c2;
c1.getdata();
c2.getdata();
coord c3,c4;
 c3 = c1+c2;
 c4 = c2-c1;
 c3.showdata1();
 c4.showdata2();


}
