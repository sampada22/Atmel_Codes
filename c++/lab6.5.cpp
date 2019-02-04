#include <iostream>
using namespace std;

class Complex
{
 public:
  int real, img;
  Complex()
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
    cout << real << "-" << img << "i ";
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
  ComplexMath c;
  a.displayp();
  std::cout << " + ";
  c.displayp();
  cout << "=";
  (c+a).displayp();
  cout<<endl;
  a.displaym();
  std::cout << " - ";
  c.displaym();
  cout << "=";
  (c-a).displaym
  ();
  return 0;
}
