// To merged two sorted array so that the resulted array is also sorted. 

#include <iostream>
#include<vector>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m){
    int i=0,j=0,k=0;
    int arr3[n];
    while (i<n-m && j<m)
    {
        if (arr1[i]<=arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
            arr3[k++]=arr2[j++];  
    }
    while (i<n-m)
    {
        arr3[k++]=arr1[i++];
    }
    while (j<m)
    {
        arr3[k++]=arr2[j++];
    }
    for (int l = 0; l < n; l++)
    {
        cout<<arr3[l]<<" ";
    }cout<<endl;
}

// Moving zeroes ro the end of the array. 

void noZero(vector<int>& arr, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[k++]);
        }
    }
    for (int l = 0; l < n; l++) {
        cout << arr[l] << " ";
    }
    cout << endl;
}

// Rotating array by a factor of k terms. 
void rotate(vector<int>& arr, int k){
    for (int i = 0; i < k; i++)
    {
        int last = arr[arr.size()-1];
        for (int j = arr.size()-1; j > 0 ; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }
    for (int l = 0; l < arr.size(); l++) {
        cout << arr[l] << " ";
    }
    cout << endl;
}
// Another approach 
void rotate1(vector<int>& arr, int k){
    vector<int> temp(arr.size());
    for (int i = 0; i < arr.size(); i++){
        temp[(i+k)%arr.size()] = arr[i];
    }
    arr = temp;

    for (int l = 0; l < arr.size(); l++) {
        cout << arr[l] << " ";
    }
    cout << endl;
}

// To check whether an array is sorted and rotated or not .
bool rotsort(vector<int>& arr){
    int c=0;
    for (int i = 0; i < arr.size()-1; i++)
    {
        if (arr[i+1]<arr[i])
        {
            c++;
        }
    }
    if (c<=1 && arr[0]>=arr[arr.size()-1])
    {
        return true;
    }
    return false;
}

// Array that is sum of 2 arrays
// Good Question 

void reverse(vector<int>& arr){
    for (int i = arr.size()-1; i >=0; i--)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void arraySum(vector<int>& arr1,int n,vector<int>& arr2,int m){
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int> ans;

    // General Case 
    while (i>=0 && j>=0)
    {
        int sum = arr1[i--] + arr2[j--] + carry;
        carry = sum/10;
        sum%=10;
        ans.push_back(sum);
    }
    // When first array is larger 
    while (i>=0)
    {
        int sum = arr1[i--] + carry;
        carry = sum/10;
        sum%=10;
        ans.push_back(sum);
    }
    // When second array is larger 
    while (j>=0)
    {
        int sum = arr2[j--] + carry;
        carry = sum/10;
        sum%=10;
        ans.push_back(sum);
    }
    // When a carry is increasing the size of the answer array 
    while (carry!=0)
    {
        int sum = carry;
        carry = sum/10;
        sum%=10;
        ans.push_back(sum);
    }
    reverse(ans);
}



int main(){
    // int arr1[10] = {1,3,5,0,0,0,0,0,0,0};
    // int arr2[7] = {2,4,6,11,22,33,65};
    // merge(arr1,10,arr2,7);
    // vector<int> arr ={2,4,6,11,22,33,65};
    // rotate1(arr,4);
    // vector<int> arr ={45,55,66,88,1,2,43};
    // cout<<rotsort(arr);
    vector<int> arr1 ={1,2,3,3};
    vector<int> arr2 ={9,2,3,3};
    arraySum(arr1,4,arr2,4);
    return 0;
}