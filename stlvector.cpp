#include <iostream>
#include <vector>
using namespace std;
int main(){
    // Initiate vector 
    vector<int> v;

    // To insert in vector 
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // To get total capacity of vector (doubles itself)
    cout<<"Capacity-->"<<v.capacity()<<endl;

    // To get stored size of the vector.
    cout<<"Size-->"<<v.size()<<endl;

    // Index Element 
    cout<<"At Index 2-->"<<v.at(2)<<endl;
    cout<<"First element-->"<<v.front()<<endl;
    cout<<"Last element-->"<<v.back()<<endl;

    // Pop element 
    v.pop_back();

    // Vector after pop 
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl; 

    // vector with size 5 and all elements a 
    vector<int> a(5,1); 

    // vector same as a 
    vector<int> b(a); 


}