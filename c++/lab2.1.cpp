#include <iostream>
using namespace std;
struct date
{
int day, month, year;
};
void date_display( date c)
{cout << endl << c.day << "/" << c.month << "/" <<c.year << endl;}

int main(){
date d;
cout << "Enter day, month and year " << endl;
cin >> d.day>> d.month>> d.year;
date_display(d);
return 0;
}
