#include<iostream>
using namespace std;
class user
{

public:
    long long int no;
    char nam[25];
    float mo;

    get()
    {
        cout<<"enter mobile no."<<endl;
        cin>>no;
        cout<<"enter name "<<endl;
        cin.ignore();
        cin.getline(nam,25);
        cout<<"enter money"<<endl;
        cin>>mo;
    }

};
  ostream& wid(ostream &wi)
{
    wi<<cout.width(10)<<flush;
    return wi;
}
 ostream& fil(ostream &fi)
{
    fi<<cout.fill('@')<<flush;
    return fi;
}
 ostream& pre(ostream &pr)
{
    pr<<cout.precision(4)<<flush;
    return pr;
}
int main()
{
    user g;
    g.get();
    cout<<wid<<g.no<<endl;
        cout<<fil<<g.nam<<endl;
        cout<<pre<<g.mo<<endl;


    return 0;
}
