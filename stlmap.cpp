#include <iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> m;
    // map is like dictionary in c++ 
    m[1] = "Babbar";
    m[2] = "Kumar";
    m[3] = "Sahu";
    m.insert({3,"Vikas"});

    // To print
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    // to Erase 
    m.erase(1);

    // to find 
    auto it = m.find(3);

    for(auto i=it;i!=m.end();i++)
    cout<<(*i).first<<endl;

    
}