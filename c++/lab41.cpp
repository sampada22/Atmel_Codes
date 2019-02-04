#include<iostream>
using namespace std;
class time {
int hour, minute,sec;
public:
time(){}
time (int h, int m, int s){
hour = h,minute =m, sec =s;
}
time add_time(time t1,time t2){
time a;
sec = t1.sec + t2.sec;
minute = sec/60;
sec = sec%60;
minute = minute +t1.minute+t2.minute;
hour = minute/60;
minute = minute%60;
hour = hour +t1.hour +t2.hour;
return a;
}
void getdata(){
cout<<"Enter hour"<<endl;
cin>>hour;
cout<<"Enter minute"<<endl;
cin>>minute;
cout<<"Enter seconds"<<endl;
cin>>sec;
}
void display(){
cout<<"The added time is:"<<endl;
cout<<hour<<":"<<minute<<":"<<sec;
}
};
int main(){
time t1(0,0,0),t2(0,0,0),t3(0,0,0);
t1.getdata();
t2.getdata();
t3.add_time(t1,t2);
t3.display();
}
