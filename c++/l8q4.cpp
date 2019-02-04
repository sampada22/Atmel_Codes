#include<iostream>
#include<fstream>
using namespace std;
class student{



public:
    char name[25], address[25],dep[25];
    int id;
    void get(){
    cout<<"Enter the name of student: ";
    cin.getline(name,25);
    cout<<"Student id:";
    cin>>id;
    cin.ignore();
    cout<<"Department: ";
    cin.getline(dep,25);
    cout<<"Address: ";
    cin.getline(address, 25);
    }

};
int main(){

    ofstream ofile("Student.txt");
    student s;
    s.get();

    ofile<<s.name<<endl;
    ofile<<s.id<<endl;
    ofile<<s.address<<endl;
    ofile<<s.dep<<endl;

    ifstream ifile("Student.txt");
    ifile.getline(s.name,25);
    ifile>>s.id;
    ifile.ignore();

    ifile.getline(s.address,25);
    ifile>>s.dep;


    cout<<endl<<"Reading data from the file: "<<endl;
    cout<<"Name: "<<s.name<<endl<<"Id: "<<s.id<<endl<<"Address: "<<s.address<<endl<<"Department: "<<s.dep<<endl;




    return 0;
}
