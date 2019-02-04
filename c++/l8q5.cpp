#include<iostream>
#include<fstream>
using namespace std;
class trans
{
private:
    int acn;
    char las[15];
    char fir[15];
 float totb;
public:
    read()
    {
        cout<<"enter account no. ::"<<endl;
        cin>>acn;
        cout<<"enter the first name"<<endl;
        cin>>fir;
        cout<<"enter the last name"<<endl;
        cin>>las;
        cout<<"enter the total balance"<<endl;
        cin>>totb;
    }
    show()
    {
        cout<<"ACCOUNT NO:"<<acn<<endl<<"LAST NAME::"<<las<<endl<<"FIRST NAME"<<fir<<endl<<"TOTAL BALANCE"<<totb<<endl;
    }
};
    write()
    {
       trans t;
       ofstream outfile("jk1.dat",ios::binary|ios::app);
       t.read();
       outfile.write(reinterpret_cast<char*>(&t),sizeof(t));
    }
    dis()
    {
        trans t;
        cout<<"READING DATA FROM FILE"<<endl;
        ifstream infile("jk1.dat",ios::binary);
        while(!infile.eof())
        {
            if(infile.read(reinterpret_cast<char*>(&t),sizeof(t)>0))
               {
               t.show();
               }
        }
    }
    update()
    {

        trans t;
        int n;
        ifstream infile("jk1.dat",ios::binary);
        cout<<"enter the record no."<<endl;
        cin>>n;
        infile.seekg((n-1)*sizeof(t));
        t.show();
    }

int main()
{
    int ch;
    cout<<"transaction processing unit"<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"select one option from below \n \t1--add data \n\t2--update data \n\t3--delete data \n\t 4--display information \n\t 5--exit"<<endl;

    while(true)
    {
        cout<<"enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            write();
            break;
        case 2:
            update();
            break;
        case 3:
            //exit(0);
            //del();
            break;
        case 4:
            dis();
            break;
        case 5:
            //exit(0);
            break;
        default:
            cout<<"invalid input"<<endl;
            break;

        }
    }
    return 0;

}
