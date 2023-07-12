#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    v.push_back(9);
    v.push_back(16);

    cout<<"Binary Search -->"<<binary_search(v.begin(),v.end(),7)<<endl;

    int a=3,b=6;
    max(a,b);
    min(a,b);
    swap(a,b);

    string str = "abcd";
    reverse(str.begin(),str.end());
    rotate(v.begin(),v.begin()+1,v.end());

}