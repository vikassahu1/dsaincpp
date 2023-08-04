#include <iostream>
#include<vector>
using namespace std;

// To print or store a 2d array as a sin wave in 1d array 
vector<int> wavePrint(vector<vector<int>> arr,int nRows,int mCols){
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if(col&1){
            // This will execute if index is odd
            for (int row = nRows-1;row  >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else{
            // This will execute if index is even
            for (int row = 0;row  < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}




// VERY IMPORTANT QUESTION 
// Asked in many big companies 
// Program to show spiral print of a matrix.

void spiralOrder(vector<vector<int>> & matrix){

    vector<int> ans; 
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row*col;

    // index initialization 
    int startRow = 0;
    int endRow = row-1;
    int startCol = 0;
    int endCol = col-1;

    while (count<total)
    {
        // Priting starting row 
        for (int index = startCol;count<total && index <= endCol; index++)
        {
            ans.push_back(matrix[startRow][index]);
            count++;
        }
        startRow++;
        
        // Priting End column
        for (int index = startRow;count<total && index <= endRow; index++)
        {
            ans.push_back(matrix[index][endCol]);
            count++;
        } 
        endCol--;

        // Priting End row 
        for (int index = endCol;count<total && index >= startCol; index--)
        {
            ans.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;

        // Priting starting column
        for (int index = endRow;count<total && index >= startRow; index--)
        {
            ans.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }cout<<endl;
}




// VERY IMPORTANT QUESTION 
// Rotating an array by 90 degress 

void rotate90(vector<vector<int>> & matrix){
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < col; i++)
    {
        for (int j = row-1; j>=0; j--)
        {
            ans.push_back(matrix[j][i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }cout<<endl;
    

}



int main()
{
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    // wavePrint(arr,2,2);
    // spiralOrder(arr);
    rotate90(arr);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<"  ";
    // }cout<<endl;
    return 0;
}