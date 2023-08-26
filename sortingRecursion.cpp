#include<iostream>
// #include <bits/stdc++.h>
using namespace std;



// Bubble Sort 
void bsortArray(int *arr, int n){
    if(n==0||n==1)
        return ;
    
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bsortArray(arr,n-1);
}




// Insertion Sort 
void isortArray(int *arr,int n, int i = 1){
    // Termiation 
    if(i==n)
        return ;

    int j = i-1;
    int temp = arr[i];
    for (j; j >= 0; j--)
    {
        if (arr[j]>temp)
        {
            arr[j+1] = arr[j];
        }
        else
        {
            break;
        }
    }
    arr[j+1] = temp;
    isortArray(arr,n,i+1);
}




// Selection Sort
void ssortArray(int *arr,int n,int i=0){
    if (i==n)
    {
        return ;
    }
    
    int minindex = i;
    for (int j = i+1; j < n; j++)
    {
        if (arr[j]<arr[minindex])
        {
            minindex = j;
        }
    }
    swap(arr[i],arr[minindex]);
    ssortArray(arr,n,i+1);
}


// Merge Sort (VERY IMPORTANT)

void merge(int *arr,int s,int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values 
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merging two sorted arrays.
    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while (index1<len1 && index2<len2)
    {
        if (first[index1] > second[index2])
        {
            arr[mainArrayIndex++] = second[index2++];
        }
        else
            arr[mainArrayIndex++] = first[index1++];
    }
    
    while (index1<len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    
    while (index2<len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete[] first;
    delete[] second;

}

void msortArray(int *arr,int s,int e){
    if (s>=e)
        return ;

    int mid = s+(e-s)/2;
    
    // left part sorting 
    msortArray(arr,s,mid);

    // right part sorting 
    msortArray(arr,mid+1,e);

    // merging both parts 
    merge(arr,s,e); 
}





// Quick Sort 

int partition(int *arr,int s,int e){

    int pivot = arr[s];

    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
        
    }
    
    // Place pivot at right place 
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex],arr[s]);

    // Left and right wala 
    int i = s,j=e;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
        
    }
    return pivotIndex;
}


void quickSort(int *arr,int s,int e){

    // base case 
    if (s>=e)
    {
        return ;
    }

    // Partition Karenge 
    int p = partition(arr,s,e);

    // left part sort karenge 
    quickSort(arr, s,p-1);

    // right part ko sort karenge 
    quickSort(arr,p+1,e);
    
}

int main(){

    int arr[5] = {2,33,4,22,3};
    // ssortArray(arr,5);
    quickSort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}