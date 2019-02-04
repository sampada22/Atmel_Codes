#include<iostream>
using namespace std;
class shape{
public:
    virtual void show(){
    cout<<"Function from the base class has been called."<<endl;
    }
    virtual void area(){
    cout<<"The base class has no data to display area."<<endl;
    }
    virtual ~shape(){
    cout<<"Destructor from the base class. "<<endl;
    }
};
class circle:public shape{
private:
    float r;
public:
    circle():r(0){}
    circle(float rad):r(rad){}

    void show()
    {
        cout<<"The radius of the circle is:"<<r<<endl;
    }
    void area(){
    cout<<"The area of circle is: "<<3.14*r*r<<endl;
    }
    ~circle(){
    cout<<"Destructor from circle. "<<endl;
    }
};
class rect: public shape{
private:
    float a,b;
public:
    rect():a(0),b(0){}
    rect(float l, float br):a(l),b(br){}
    void show(){
    cout<<"The length and breadth of the rectangle is: "<<a<<", "<<b<<endl;
    }
    void area(){
    cout<<"The area of the rectangle is: "<<a*b<<endl;
    }
    ~rect(){
    cout<<"Destructor from rectangle. "<<endl;
    }
};
class trap: public shape{
private:
    float a,b,h;
public:
    trap():a(0),b(0),h(0){}
    trap(float base1, float base2, float height):a(base1),b(base2),h(height){}
    void show(){
    cout<<"The two bases and the height of the trapezoid are: "<<a<<", "<<b<<", "<<h<<endl;
    }
    void area(){
    cout<<"The area of the trapezoid is: "<< (a+b)/2*h<<endl;
    }
    ~trap(){
    cout<<"Destructor from trapezoid."<<endl;
    }
};
int main(){
rect r(5.5,3);
circle c(2.5);
trap t(1.5,2.5,4);
shape s,*sptr[]={&s,&c,&r,&t};

for(int i=0;i<4;i++){
    sptr[i]->show();
    sptr[i]->area();
    cout<<endl;
}

return 0;
}
