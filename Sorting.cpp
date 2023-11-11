#include <iostream>
using namespace std;

void selectionSort(int arr[],int size){
    // Unstable sorting algorithm 
    // smallest element se element ko swap karte jaenge 
    for (int i = 0; i < size; i++)
    {
        int minindex = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]<arr[minindex])
            {
                minindex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
}

void bubbleSort(int arr[],int n){
    // Stable sorting algorithm 
    // "i" sirf loop k lie h jo i=0 se i=n-1 tak chalega .
    // Biggest element last me settle hota jaega. 
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
}

void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {

        // temp me arr[i] store kr lia ab ise sabse compare kar lenge. 
        // shuru se array ko sort karte jaenge. first element ko sorted assume karenge.  
        int temp = arr[i];
        int j = i-1;
        for (j; j >= 0; j--)
        {
            if (arr[j]>temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
}

void heapify(int arr[],int n,int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i + 2;
        
        if(left<n && arr[largest]<arr[left])
            largest = left;
        
        if(right<n && arr[largest]<arr[right])
            largest  = right;
        
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }



void heapSort(int arr[],int n){
    while (n>1)
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
}



int main(){
    int arr[] = {12,6,11,2,3};
    // insertionSort(arr,7);

    int n = 5;

    for(int i = n/2-1; i >=0 ; i--)
    {
        heapify(arr,n,i);
    }


    heapSort(arr,5);
    for (int i = 0; i < 5 ; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}