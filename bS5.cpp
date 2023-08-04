// To search an element in sorted rotated array . 

#include <iostream>
using namespace std;

int binarySearch(int arr[],int s,int e,int element){
    int mid = s+ (e-s)/2;
        while (s<=e)
        {
            if (arr[mid]==element)
            {
                return mid;
            }
            else if (arr[mid]>element)
            {
                e=mid-1;
            }
            else
                s= mid+1;
            mid = s+ (e-s)/2;
        }
}

int pivot(int arr[],int size){
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;
    while (s<e)
    {
        if (arr[mid]>=arr[0])
            s = mid+1;
        else
            e = mid;
        mid = s+(e-s)/2;
    }
    return s;
}

int getElement(int arr[],int size,int element){
    // first we get the pivot element
    int s = 0;
    int e = size-1;
    int piv = pivot(arr,size);

    if (element<arr[0])
        return binarySearch(arr,piv,e,element);
    else
        return binarySearch(arr,s,piv-1,element);
    }
    

int main()
{
    int arr[12] = {10,23,45,56,78,80,1,2,3,4,6,7};
    cout << getElement(arr, 12,45) << endl;
    return 0;
}