#include <iostream>
using namespace std;
class student
{
public:
    virtual void display()=0;
};
class engineering:public student
{
public:
    void display()
    {
        cout<<"this is the message from the engineering class"<<endl;
    }
};
class medicine:public student
{
public:
    void display()
    {
        cout<<"this is the message from the medicine class"<<endl;
    }
};
class science:public student
{
public:
    void display()
    {
        cout<<"this is the message from the science class"<<endl;
    }
};
int main()
{
    student *ptr;
    ptr=new engineering;
    ptr->display();
    ptr=new medicine;
    ptr->display();
    ptr=new science;
    ptr->display();
    delete ptr;
    return 0;
}
