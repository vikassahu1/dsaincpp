// Book allocation problem 
// Painter's partition problem 
// To allocate 'n' number of books amongs m students so that number of maximum page to a student is minimum. 

#include <iostream>
using namespace std;

bool isPossible(int arr[],int mid,int n,int m){
    int studentCount = 1,Pagesum=0;
    for (int i = 0; i < n; i++)
    {
        if (Pagesum + arr[i]<=mid)
        {
            Pagesum += arr[i];
        }
        else{
            studentCount++;
            // Agar arr[i]>mid nahi kia to agar arr[i] mid se jyada hoga to answer galt ho jaega. Condition hi false ho jaega.  
            if(studentCount>m || arr[i]>mid)
                return false;
            Pagesum=arr[i];
        }
        
    }
}

int bookAllocate(int arr[],int n,int m){
    int s = 0,ans=-1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum+=arr[i];
    int e = sum;
    int mid = s+(e-s)/2;
    while (s<=e)
    {
        if (isPossible(arr,mid,n,m) )
        {
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
} 

int main()
{
    int arr[4] = {10,20,30,40};
    cout << bookAllocate(arr, 4,2) << endl;
    return 0;
}