#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    
    // If number will be too big this formula might fail...so
    // int mid = (start+end)/2;

    int mid  = start + (end-start)/2;

    while (start<=end)
    {
        if(arr[mid]==key)
            return mid;
        if (key>arr[mid])
        {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid  = start + (end-start)/2;
    }
    
    return -1;
}
int main(){
int odd[5] = {1,3,5,7,9};
int even[5] = {2,4,6,8,10};

cout<< binarySearch(odd,5,9) <<endl;
}