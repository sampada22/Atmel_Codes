#include <iostream>
using namespace std;

class Complex
{
 public:
  int real, img;
  void getdata()
  {
    cout << "Enter real part: ";
    cin >> real;
    cout << "Enter imaginary part: ";
    cin >> img;
  }
  void displayp ()
  {
    cout << real << "+" << img << "i ";
  }
  void displaym ()
  {
    cout << real << "+" << img << "i ";
  }
};

class ComplexMath:public Complex
{
 private:
 public:
  ComplexMath(){
  }

  ComplexMath& operator+(const Complex a)
  {
    real += a.real;
    img += a.img;
    return *this;
  }
   ComplexMath& operator-(const Complex a)
  {
    real -= a.real;
    img -= a.img;
    return *this;
  }
};

int main()
{
  Complex a;
  Complex b;
  ComplexMath c;
  Complex d;
  a.getdata();
  c.getdata();
  a.displayp();
  b=c+a;
  std::cout << " + ";
  c.displayp();
  cout << "=";

  b.displayp();

  cout<<endl;
  d=c-a;
  c.displaym();
  std::cout << " - ";
  a.displaym();
  cout << "=";
  d.displaym();
  return 0;
}
