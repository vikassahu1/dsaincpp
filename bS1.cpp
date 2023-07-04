#include <iostream>
using namespace std;
// To find first and last occurance of an input elements from a sorted array using bs.

int loccurence(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if (arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if (arr[mid]>key)
            end = mid-1;
        else
            start = mid+1;
        mid = start + (end-start)/2;
    }
    return ans;
}

int hoccurence(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        if (arr[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if (arr[mid]>key)
            end = mid-1;
        else
            start = mid+1;
        mid = start + (end-start)/2;
    }
    return ans;
}