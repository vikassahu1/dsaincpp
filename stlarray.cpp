#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int,4> a = {1,2,3,4};
    int size = a.size();

    cout << "Element at 2nd index  "<<a.at(2)<<endl;
    cout << "Check empty or not  "<<a.empty()<<endl;
    cout << "First Element  "<<a.front()<<endl;
    cout << "Last Element  "<<a.back()<<endl;
}  


