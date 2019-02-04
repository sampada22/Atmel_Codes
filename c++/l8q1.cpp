#include<iostream>
using namespace std;
class invoice
{

public:
    int n,q;
    char name[50];
    float price,d;
    float total;
    void amount(){
        total=n*price;
    }
    friend    ostream& operator<<(ostream &o, invoice i);
    friend    istream& operator>>(istream &o, invoice i);
};



 ostream& operator<<(ostream &o, invoice i)
{
  o<<i;
}
  istream& operator>>(istream &o, invoice i){
  o>>i;
  }

int main()
{
        int k;
        invoice g[25];
        cout<<"Enter the number of types of good"<<endl;
        cin>>k;
        for( int i=0;i<k;i++){
        cout<<"Enter the name of product"<<i+1<<": "<<endl;
        cin.ignore();
        cin.getline(g[i].name, 50);
        cout<<"Enter price of this product: "<<endl;
        cin>>g[i].price;
        cout<<"Quantity of the product: "<<endl;
        cin>>g[i].n;
        g[i].amount();
        }


        cout<<"Name: ";
        cout.width(10);
        cout.fill(' ');
        cout<<"Price: ";
        cout.width(10);
        cout.fill(' ');
        cout<<"Quantity: ";
        cout.width(10);
        cout.fill(' ');
        cout<<"Total: "<<endl;
        cout<<"-----------------------------------------------------"<<endl;

        for(int i=0;i<=k;i++){
        cout<<g[i].name;
        cout.width(10);
        cout.fill(' ');
        cout<<g[i].price;
        cout.width(10);
        cout.fill(' ');
        cout<<g[i].n;
        cout.width(10);
        cout.fill(' ');
        cout<<g[i].total<<endl;

        }
    return 0;
}

