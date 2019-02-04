#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    void set_details()
    {
        cout<<"Enter name:  ";
        cin>>name;
        cout<<"Enter age:  ";
        cin>>age;
    }
    void address()
    {
        cout<<"The address of this object is "<<this<<endl;
    }
protected:
    string name;
    int age;
};

class Student:public Person
{
public:
    void set_marks()
    {
        cout<<"Enter marks of student: ";
        cin>>marks;
    }
    void reset_marks()
    {
        marks = 0;
    }
private:
    int marks;
};

class Employee:public Person
{
public:
    void set_salary()
    {
        cout<<"Enter salary of employee: ";
        cin>>salary;
    }
    void reset_salary()
    {
        salary = 0;
    }
private:
    int salary;
};

int main()
{
    Person p1, p2;
    Student s1, s2;
    Employee e1, e2;
    cout<<"Enter name and age for 2 people: "<<endl;
    p1.set_details();
    p2.set_details();
    cout<<"The addresses of these objects are: "<<endl;
    p1.address();
    p2.address();
    cout<<"Enter name, age and marks for 2 students: "<<endl;
    s1.set_details();
    s1.set_marks();
    s2.set_details();
    s2.set_marks();
    cout<<"The addresses of these objects are: "<<endl;
    s1.address();
    s2.address();
    cout<<"Enter name, age and salary for 2 employees: "<<endl;
    e1.set_details();
    e1.set_salary();
    e2.set_details();
    e2.set_salary();
    cout<<"The addresses of these objects are: "<<endl;
    e1.address();
    e2.address();
    return 0;
}
