#include <iostream>
#include <list>
using namespace std;

int main(){
    // List is like deque only just here we cannot access a perticular index directly.
    list<int> l;
    l.push_back(3);
    l.push_front(5);
    l.erase(l.begin());
    cout<<l.size()<<endl;
}