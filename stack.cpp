#include <iostream>
using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int top;

    // Constructor 
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if (size-top>1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void pop(){
        if (top>=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if (top>=0 && top<size)
        {
            return arr[top];
        }
        else
            cout<<"Error"<<endl;
            return -1;
    }

    bool isEmpty(){
        if (top==-1)
        {
            return true;
        }
        return false;
    }
};




int main(){
    Stack st(10);
    st.push(10);
    st.push(9);
    st.push(30);
    st.push(100);
    cout<<st.peek();
    return 0;
}