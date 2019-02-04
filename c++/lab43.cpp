#include<iostream>
#include<string.h>
using namespace std;
class dep{
private:
char name[3];
int id;
public:
dep(){}
dep(char n[3],int i){
strcpy (name,n);
id = i;
}
void showdata(){
cout <<"Name:"<<name<<endl;
cout<<"Id:"<<id<<endl;
}
~dep(){
cout<<"Object goes out of scope"<<endl;


}
};
int main(){
dep d1("BEX",04);
d1.showdata();
return 0;
}
