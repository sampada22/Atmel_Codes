#include <iostream>
using namespace std ;
namespace square{
int num;
int fun (int data){
return data * data;
}
}namespace cube {
int num;
int fun (int data){
return data * data* data;
}
}
int main(){
cout << "Enter two numbers whose square and cube is to be found" << endl;
cin >> square ::num >> cube :: num;
cout << "The sqaure of "<<square::num << " is"<< square :: fun(square:: num)<<endl;
cout <<"The cube of "<< cube::num << "is"<<cube ::fun(cube::num)<<endl;
}
