#include <iostream>
#include <set>

using namespace std;
int main(){
    // Set has only unique values  
    set<int> s;
    s.insert(7);
    s.insert(2);
    s.insert(4);
    s.insert(2);
    s.insert(3);
    s.insert(8);
    s.insert(9);

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    set<int>::iterator itr = s.find(4);

    // Count is used to check an element present or not 
    cout<<"Number of 2 --> "<<s.count(2)<<endl;
    // Note: 
    // insert,find,erase,count complexity O[n]. 
    // size,begin,empty,end complexity O[1]. 

}
