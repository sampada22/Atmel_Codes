#include<iostream>
using namespace std;
class vehicle{
private:
int num;
float rate,hour;
public:
vehicle(){}
vehicle (int n, float r, float h){
num = n, rate = r, hour = h;
}
void charge (){
float c;
if (num>=10){
c = (rate*hour*num)- (0.1*rate*hour*num);
}
else {
c = rate*hour*num;

}
cout <<"The charge for"<<num<<"vehicles parked for"<<hour<<"hour is: Rs"<<c<<endl;

}
void cpy(vehicle v){
num = v.num;
rate = v.rate;
hour = v.hour;

}
};
int main(){
vehicle v1(12,100,2),v2;
v2.cpy(v1);
v1.charge();
v2.charge();
return 0;
}
