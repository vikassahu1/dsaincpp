#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Getting highest and lowest occurance from a sorted array. 
int hOccurance(int *arr,int s,int e,int k,int occ = -1){
    if(s>e)
        return occ;

    int mid = s+(e-s)/2;

    if(arr[mid]==k){
        occ = mid;
        return hOccurance(arr,mid+1,e,k,occ);
    }
    
    if(arr[mid]<k){
        
        return hOccurance(arr,mid+1,e,k,occ);
    }
    else{
        return hOccurance(arr,s,mid-1,k,occ);
    }
}

int lOccurance(int *arr,int s,int e,int k,int occ = -1){
    if(s>e)
        return occ;

    int mid = s+(e-s)/2;

    if(arr[mid]==k){
        occ = mid;
        return lOccurance(arr,s,mid-1,k,occ);
    }
    
    if(arr[mid]<k){
        
        return lOccurance(arr,mid+1,e,k,occ);
    }
    else{
        return lOccurance(arr,s,mid-1,k,occ);
    }
}



// Getting the peak element fron a mountain array. 

int mountain(int *arr,int s,int e){
    if (s>e)
        return -1;
    
    int mid = s+(e-s)/2;

    if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        return mid;
    else if (arr[mid+1]>arr[mid])
        return mountain(arr,mid+1,e);
    else
        return mountain(arr,s,mid);
}


// Getting the pivot element from rotated sorted array. 

int pivot(int *arr,int s,int e){
    if (s>e)
        return -1;
    
    int mid = s+(e-s)/2;

    if(s==e)
        return mid;

    if(arr[mid]>=arr[0])
        return pivot(arr,mid+1,e);
    else
        return pivot(arr,s,mid);
}



// Searching an element in sorted rotated array 

int binarySearch(int *arr,int s,int e,int k){
    if(s>e)
        return -1;
    int mid = s+(e-s)/2;
    if (arr[mid]==k)
        return mid;
    if (arr[mid]<k)
    {
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return binarySearch(arr,s,mid-1,k);
    }
}

int searchInRotated(int *arr,int s,int e,int k){
    int piv = pivot(arr,s,e);
    int ans = -1;
    int mid = s+(e-s)/2;

    if(k>=arr[0])
        ans = binarySearch(arr,s,piv-1,k);
    else
        ans = binarySearch(arr,piv,e,k);
    return ans;
}

// Square root of a perfect square number using binary search  

int root(int n,int s=0,int e = 0){

    int mid = s+(e-s)/2;
    if(mid*mid == n)
        return mid;
    if(mid*mid>n)
        return root(n,s,mid-1);
    else
        return root(n,mid+1,e);
}

int main(){
    // int arr[10] = {1,3,4,5,5,5,5,57,57,78};
    // cout<<lOccurance(arr,0,9,5)<<endl;

    // int arr[7] = {1,2,4,55,7,3,1};
    // cout<<mountain(arr,0,4)<<endl;


    // int arr[10] = {4,5,6,55,666,55666,55966,1,2,3};
    // cout<<pivot(arr,0,9)<<endl;

    // cout<<searchInRotated(arr,0,9,666)<<endl;

    cout<<root(4225,0,4225)<<endl;
    return 0;
}