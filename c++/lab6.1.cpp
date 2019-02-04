#include <iostream>

using namespace std;

class Dist
{
public:
    Dist (const float & m)
    {
        meter=m;
        centi= (m-meter)*100;
    }
    Dist(const int & m, const float & c):
    meter(m), centi(c) {}
    void display()
    {
        cout<<"Meters: "<<meter<<" Centimeters: "<<centi<<endl;
    }
    operator float()
    {
        float temp;
        temp = meter + centi/100;
        return temp;
    }

private:
    int meter;
    float centi;
};

int main()
{
    Dist d1(15, 15);
    float f = 6.78;
    cout<<"Distance: "<<endl;
    d1.display();
    cout<<"In meters: "<<endl;
    cout<<float(d1)<<" meters"<<endl;
    cout<<endl;
    cout<<"6.78 meters to Dist object: "<<endl;
    Dist(f).display();
    return 0;
}
