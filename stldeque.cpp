#include <iostream>
#include <deque>

using namespace std;
int main(){
    // In deque operations can be done from both the directions. 
    deque<int> d;
    d.push_front(1);
    d.push_back(2);

    // At index 
    cout<<"Element at 1-->"<<d.at(1)<<endl;

    // Check Empty 
    cout<<d.empty()<<endl;

    // Get size 
    cout<<d.size()<<endl;
    
    // To erase
    // to give from where to where  
    d.erase(d.begin(),d.begin()+1);

    // To PRINT 
    for (int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;
} 