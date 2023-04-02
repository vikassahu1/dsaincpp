#include <iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter your age: "<<endl;
    cin>>age;
    switch (age)
    {
    case 18:
        cout<<"You age is 18"<<endl;
        break;
    
    default:
        cout<<"You age is not 18"<<endl;
        break;
    }
    return 0;
}