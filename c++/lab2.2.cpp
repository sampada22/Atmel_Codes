#include <iostream>
using namespace std ;
int convert()
{
int a;
cout << "Enter feet." <<endl;
cin >> a;
return a;
}
void convert(int *a, int *b){
*a = (12 * *b);


}
void convert(int inch){
cout << "The data in inches is :"<< inch<< endl;

}
int main(){
int data;
int x = convert();
convert(&data,&x);
convert(data);
}
