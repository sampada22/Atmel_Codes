#include <iostream>
using namespace std ;
inline float net(float sal){
cout <<endl<< "You have to pay Rs."<<sal * 0.1;
}
int main(){
int salary;
cout << "Enter the salary"<<endl;
cin >>salary;
net(salary);
return 0;

}
