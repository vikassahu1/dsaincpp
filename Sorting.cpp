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

int main(){
    int arr[] = {3,2,1,4,6,8,12};
    insertionSort(arr,7);
    return 0;
}