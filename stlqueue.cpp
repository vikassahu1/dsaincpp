#include <iostream>
#include <queue>
using namespace std;

int main(){
    // Work on fifo concept
    queue<string> q;
    q.push("Vikas");
    q.push("Kumar");
    q.push("Sahu");
    // First element 
    q.front();
    // Last element 
    q.back();
    // Size 
    q.size();

    // max-heap 
    // In max heap when we find top element it comes out in descending order. 
    priority_queue<int> maxi;

    maxi.push(1);
    maxi.push(5);
    maxi.push(6);
    maxi.push(8);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;
    
    // max-heap
    // opposite of max-heap  
    priority_queue<int, vector<int>,greater<int> > mini;

    mini.push(1);
    mini.push(5);
    mini.push(6);
    mini.push(8);
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    // mini.empty() -- To check empty  

}