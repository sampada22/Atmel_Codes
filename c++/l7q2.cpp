#include<iostream>
#include<string.h>
using namespace std;
class person {
protected:
    char *name;
public:
    person(){}
    person(char *s){
    name=s;
    }
};
class  employee: public person   {
protected:
    char *office;
public:
    employee(){}
    employee(char *o):office(o){}
    void show(){
    cout<<name<<" "<<office<<endl;
    }
};
int main{
person e("ram");
e.show();
return 0;
}
