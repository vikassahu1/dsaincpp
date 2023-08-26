#include <iostream>
using namespace std;


// Two unique element from an array with 2 same elements 
void unique(int *arr,int n){
    int XOR = 0;

    for(int i=0;i<n;i++){
        XOR^=arr[i];
    }

    // S2: To find first set bit 
    int cnt = 0;
    while (XOR)
    {
        if (XOR&1)
            break;
        cnt++;
        XOR = XOR>>1;
    }

    // Creating 2 XOR and getting the numbers multiple numbers will be cancelled
    int XOR1 = 0,XOR2 = 0;
    for (int  i = 0; i < n; i++)
    {
        if(arr[i]&(1<<cnt) != 0 )
            XOR1^=arr[i];
        else
            XOR2^=arr[i];
    }
    
    cout<< XOR1 << "  "<<XOR2<<endl;
    
}

// Getting subsets of an array 
void subset(int *arr,int n){    
    int num = 1<<n;
    for(int i = 0;i<num;i++){
        int arr[100] = { };
        

    }
}


int main(){
    int arr[10] = {1,2,1,2,3,3,5,76,8,8};
    unique(arr,10);
}