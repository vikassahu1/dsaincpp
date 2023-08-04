// To find the index of pivot element form the rotated sorted array .

// VERY IMPORTANT *
#include <iostream>
using namespace std;

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

int main()
{
    int arr[12] = {23,45,56,78,80,1,2,3,4,6,7,10};
    cout << pivot(arr, 12) << endl;
    return 0;
}