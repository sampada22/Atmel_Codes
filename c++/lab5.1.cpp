#include <iostream>
using namespace std;
class coord3;
class coord2;
class coord1;

class coord2{
private:
public:
    coord1 add( coord1 c11,coord1 c12){
        coord1 c2( c11.x + c12.x, c11.y + c12.y);
        return c2;
    }

    void showdata(){
        cout<<x <<","<<y;
    }
};


class coord1 {
private:
    int x,y;
public:
    coord1 (int a, int b){
        x = a;
        y =b;
    }
friend coord1 coord2::add (coord1,coord1);
};



int main (){
coord1 c11(1,2);
coord1 c12(1,2);
coord2 c2;
coord1 c13 = c2.add(c11,c12);
c2.showdata();
return 0;

}
