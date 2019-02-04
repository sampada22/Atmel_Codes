
#include <iostream>
#include <cstring>

class Musicians
{
 protected:
  std::string str[5];
  std::string wnd[5];
  std::string per[5];
 public:
  void string()
  {
    str[0] ="Veena";
    str[1]=" Guitar";
    str[2]="Sitar";
    str[3]="Sarod";
    str[4]="Mandolin";

  }
  void wind(){

    wnd[0]="Flute";
    wnd[1]="Clarinet";
    wnd[2]="Saxophone";
    wnd[3]="Nadhaswaram";
    wnd[4]="Piccolo";

  }
  void perc()
  {
    per[0]="Tabla";
    per[1]="Mridangam";
    per[2]="Bangos";
    per[3]="Drums";
    per[4]="Tambour";

  }
};
class TypeIns:public Musicians
{
 public:
  std::string* get()
  {
    std::cout<<"Type of instruments to be displayed: " << std::endl;
    std::cout << "a. String instruments" << std::endl;
    std::cout << "b. Wind instruments" << std::endl;
    std::cout << "c. Percussion instruments" << std::endl;
    char choice;
    std::cin >> choice;
    show(choice);
  }
  void show(char choice)
  {
    if(choice == 'a')
    {
      for(int i = 0 ; i < 5; i++)
      {
        std::cout << str[i] << std::endl;
      }
    }
    else if(choice == 'b')
    {
      for(int i = 0 ; i < 5; i++)
      {
        std::cout << wnd[i] << std::endl;
      }
    }
    else
    {
      for(int i = 0 ; i < 5; i++)
      {
        std::cout << per[i] << std::endl;
      }
    }
  }
};
int main()
{
  TypeIns t;
  t.string();
  t.perc();
  t.wind();
  t.get();
  return 0;
}

