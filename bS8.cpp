// Agressive Cows 
// We have to place k number of cows in the stalls(element of the array represent sthe position of the stalls)
// So that the minimum ditance between two cows is minimum.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int k,int size,int mid){
    int countCows = 1;
    int lastPosition = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i]-lastPosition>=mid)
        {
            countCows++;
            if(countCows==k){
                return true;
            }
            lastPosition = arr[i];
        }
    }
    return false;
}

int aggressiveCows(int arr[],int size,int k){
    sort(arr,arr+size);
    int s = 0;
    int e = arr[size-1];
    int ans = -1;
    int mid = s+(e-s)/2;
    while (s<=e)
    {
        if (isPossible(arr,k,size,mid))
        {
            ans = mid;
            s=mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    int arr[] = {3,2,1,4,6};
    cout<< "Answer is "<< aggressiveCows(arr,5,2)<<endl;
    return 0;
}