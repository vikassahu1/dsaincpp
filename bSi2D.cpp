#include <iostream>
#include <vector>
using namespace std;

// binary search in 2d sorted array (linearly) .
void searchMatrix(vector<vector <int>> &matrix,int target){
    int row = matrix.size();
    int col = matrix[0].size();
    int s = 0;
    int e = row*col-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if (matrix[mid/col][mid%col]==target)
        {
            cout<<"Element is at index "<<mid/col<<" "<<mid%col<<endl;
            break;
        }
        else if (target>matrix[mid/col][mid%col])
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid= s+(e-s)/2;
    }
}


// Searching element in an array in which the element is sorted row and column wise. 
// For example...  
// 1  4  7 
// 2  5  8
// 3  6  9 
void binaryUnosorted(vector<vector <int>> &matrix,int target){
    int row = 0;
    int col = matrix[0].size()-1;
    
    while (row<matrix.size() && col>=0)
    {
        int element = matrix[row][col];
        if (element==target)
        {
            cout<<"Element is at index "<<row<<" "<<col<<endl;
            break;
        }
        else if (element<target)
        {
            row++;
        }
        else{ 
            col--;
        }
    }
}


int main(){
    // vector<vector <int>> matrix = {{1,22,33,44},{55,66,88,99},{100,101,121,222}};
    vector<vector <int>> matrix = {{1,4,7},{2,5,8},{3,6,9}};
    // searchMatrix(matrix,55);
    binaryUnosorted(matrix,8);
    return 0;
}