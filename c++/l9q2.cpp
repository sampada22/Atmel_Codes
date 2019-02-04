#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX=10;
template<class T>
class Queue
{
private:
    T arr[MAX];
    int top;
public:
    Queue()
    {
        top=-1;
    }
    void push(T data)
    {
        arr[++top]=data;
    }
    T pop()
    {
        return arr[top--];
    }
    int Size()
    {
        return (top+1);
    }
};
int main()
{
    cout<<"stack for integer data type"<<endl;
    Queue<int> q1;
    cout<<"Size of stack: "<<q1.Size()<<endl;
    q1.push(11);
    q1.push(22);
    q1.push(33);
    cout<<"size of stack: "<<q1.Size()<<endl;
    cout<<"number popped: "<<q1.pop()<<endl;
    cout<<"number popped: "<<q1.pop()<<endl;
    cout<<"size of stack: "<<q1.Size()<<endl;
    q1.push(44);
    cout<<"size of stack: "<<q1.Size()<<endl;

    cout<<"stack for float data type"<<endl;
    Queue<float> q2;
    cout<<"Size of stack: "<<q2.Size()<<endl;
    q2.push(11.22);
    q2.push(22.44);
    q2.push(33.11);
    cout<<"size of stack: "<<q2.Size()<<endl;
    cout<<"number popped: "<<q2.pop()<<endl;
    cout<<"number popped: "<<q2.pop()<<endl;
    cout<<"size of stack: "<<q2.Size()<<endl;
    q2.push(44.56);
    cout<<"size of stack: "<<q2.Size()<<endl;

    cout<<"stack for char  data type"<<endl;
    Queue<char> q3;
    cout<<"Size of stack: "<<q3.Size()<<endl;
    q3.push('a');
    q3.push('b');
    q3.push('c');
    cout<<"size of stack: "<<q3.Size()<<endl;
    cout<<"number popped: "<<q3.pop()<<endl;
    cout<<"number popped: "<<q3.pop()<<endl;
    cout<<"size of stack: "<<q3.Size()<<endl;
    q3.push('d');
    cout<<"size of stack: "<<q3.Size()<<endl;


    return 0;
}
