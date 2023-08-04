#include <iostream>
using namespace std;


// Creating a jaggered array using dynamic memory allocation. 

int main(){
    cout<< "Enter num of rows "<<endl;
    int row;
    cin>>row;

    int **arr = new int*[row];
    
    int size[100];

    // Creating 
    for (int i = 0; i < row; i++)
    {
        cout<< "Enter num of elements in row "<<i+1<<endl;
        int n;
        cin>>n;
        arr[i] = new int[n];
        size[i] = n;
    }
    
    // Input 

    for (int i = 0; i < row; i++)
    {
        cout<<"Enter elements for row "<< i+1 <<endl;
        for (int j = 0; j < size[i]; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    cout<<endl;
    
    // Printing outputs 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cout<<arr[i][j]<<" ";
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
