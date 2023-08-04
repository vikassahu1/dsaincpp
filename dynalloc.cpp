#include <iostream>
using namespace std;


int numSum(int *arr,int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}


int main(){

    // Creating of an array of variable size dynamically. 
    // int n;
    // cin>>n;
    // int * arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    // cout<<numSum(arr,n)<<endl;


    // Creating of a 2D array of variable size dynamically.

    int row;
    cin >> row;

    int col;
    cin >> col;

    // creating 

    // This will create row with pointer 
    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        // This will create clums for each row 
        arr[i] = new int[col];
    }
    

    // Taking inputs 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    
    // Printing outputs 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j];
        } 
        cout<<endl;
    }

    // Releasing memory 
    for (int i = 0; i < row; i++)
    {
        delete [] arr[i];
    }
    delete []arr;


    return 0;
}