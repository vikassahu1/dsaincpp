// To find  element from a sorted array by bs sum of lh elements equal to sum of right hand elements.  

#include <iostream>
using namespace std;

int pivot(int arr[],int size){
    int s = 0;
    int e = size - 1 ;
    int mid = s +(e-s)/2;
    while (s<=e)
    {
        int countl=0,countr=0;
        for (int i = 0; i < mid ; i++)
            countl+=arr[i];
        for (int j = mid+1; j <= size-1; j++)
            countr+=arr[j];
        if (countl>countr)
            e=mid-1;
        else if (countl<countr)
            s=mid+1;
        else
            return arr[mid];
        mid = s +(e-s)/2; 
    }
    return -1;
}

int main()
{
    int arr[7] = {0,0,1, 2, 3, 4,6};
    cout << pivot(arr, 7) << endl;
    return 0;
}