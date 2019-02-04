#include <iostream>
using namespace std;
#define max 4
template <class T>
class Stack
{
private:
    T q[max];
    int i;
public:
    Stack()
    {
        i=-1;
    }

   void push(T s)
    {
        try{
        if (i>=3)
            throw(2);
        q[++i]=s;
        }
        catch(int)
        {
            cout<<"EXCEPTION: maximum size of stack has reached"<<endl;
        }

    }
    int Size()
    {
        return (i+1);
    }
    T pop()
    {
        try{
        if (i==-1)
            throw('s');
         return q[i--];

        }
        catch(char)
        {
            cout<<"EXCEPTION: NO items on the stack to pop out"<<endl;
        }

    }
};
int main()
{+
    Stack<int> mitesh;
    cout<<"size :"<<mitesh.Size()<<endl;
    mitesh.pop();//this throws exception stating there is no any element to pop out
    mitesh.push(22);
    mitesh.push(31);
    mitesh.push(21);
    mitesh.push(22);
    mitesh.push(31);//this throws exception stating there is no more space on the stack to add more items.
    cout<<"Size :"<<mitesh.Size()<<endl;
    cout<<"popped item is :"<<mitesh.pop()<<endl;
    cout<<"Size :"<<mitesh.Size()<<endl;

    return 0;
}
