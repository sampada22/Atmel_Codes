#include <iostream>
using namespace std;

class FPS;

class SI
{
public:
    SI(const int & m, const float & c):
    meter(m), centi(c) {}
    operator FPS();
    void display()
    {
        cout<<"Meters: "<<meter<<" Centimeters: "<<centi<<endl;
    }
private:
    int meter;
    float centi;
};

class FPS
{
public:
    FPS(const int & f, const float & i):
    foot(f), inch(i) {}
    operator SI();
    void display()
    {
        cout<<"Feet: "<<foot<<" Inches: "<<inch<<endl;
    }
private:
    int foot;
    float inch;
};

FPS::operator SI()
{
    int meters;
    float centimeters;
    centimeters = (foot*12+inch)/0.393701;
    meters = centimeters / 100;
    centimeters = centimeters - meters*100;
    return SI(meters, centimeters);
}

SI::operator FPS()
{
    int foots;
    float inches;
    inches = 0.393701*(meter*100+centi);
    foots = inches / 12;
    inches = inches - foots*12;
    return FPS(foots, inches);
}

int main()
{
    SI s1(4, 60.4);
    FPS f1(10, 30.7);
    //cout<<"Initial values: "<<endl;
    s1.display();
    f1.display();
    //cout<<"Converted values: "<<endl;
    cout << endl;
    FPS(s1).display();
    SI(f1).display();
    return 0;
}
