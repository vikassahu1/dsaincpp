#include <iostream>
#include <vector>
using namespace std;


// To print the names of the digits of a number 

void Digit(int n) {
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    if (n==0)
        return ; 
    int digit = n%10;
    n/=10;
    Digit(n);
    cout<<arr[digit]<<" ";
}

// To check whether an array is sorted or not. 

bool Check(int *arr,int size){
    if(size==0 || size==1){
        return true;
    }
    if (arr[0]>arr[1])
        return false;
    else
    {
        return Check(arr+1,size-1);
    }
    
}

// Linear search in an array using linear search 

bool linearSearch(int *arr,int size,int key){
    if(size==0)
        return false;
    if(arr[0] == key)
        return true;
    else
        return linearSearch(arr+1,size-1,key);
}

// Binary search using recursion 
bool binarySearch(int *arr,int s,int e,int k){
    if(s>e)
        return false;
    int mid = s+(e-s)/2;
    if (arr[mid]==k)
        return true;
    if (arr[mid]<k)
    {
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return binarySearch(arr,s,mid-1,k);
    }
}

// Phone keypad question

void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
        //Base Case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index]-'0';
        string value = mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
}
    
vector<string> letterCombinations(string digits){
        vector<string> ans;

        if(digits.length()==0)
            return ans;

        string output = "";
        int index = 0;

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits,output,index,ans,mapping);
        return ans;
    }


// Permutations of a string 

void solving(vector<int> nums,int index,vector<vector<int>>& ans){

    // Base case 
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        solving(nums,index+1,ans);

        swap(nums[index],nums[i]);
    }
    
}

vector<vector<int>> permutations(vector<int> &nums){
    vector<vector<int>> ans;
    int index = 0;
    solving(nums,index,ans);
    return ans;
}



int main(){
    // int n;
    // cin>>n;
    // Digit(n);

    int arr[5] = {1,2,34,56,66};
    // cout<<Check(arr,5)<<endl;

    // cout<<linearSearch(arr,5,34)<<endl;
    cout<<binarySearch(arr,0,4,65)<<endl;
    return 0;
}
