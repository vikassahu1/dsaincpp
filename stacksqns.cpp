#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// To remove middle element from a stack .
void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        // middle wala remove kia
        inputStack.pop();
        return;
    }

    // top ko store karte jaenge aur recursive call k baad fir push kar denge .
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call .
    solve(inputStack, count + 1, size);
    inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}





// VERY IMPORTANT QUESTION
// To check whether a given string has valid parenthesis or not

bool match(char ch, char t)
{
    if ((t == '(' && ch == ')') || (t == '[' && ch == ']') ||
        (t == '{' && ch == '}'))
        return true;
    return false;
}

bool isValidParenthesis(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // if opening bracket - push karna h agar closing bracket h to check karke pop kar dena h.
        if (ch == '(' || ch == '[' || ch == '{')
        {
            stk.push(ch);
        }
        else
        {
            if (!stk.empty())
            {
                char t = stk.top();
                if (match(ch, t))
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (stk.empty())
        return true;
    else
        return false;
}



// To put an element to te bottom of the stack.
void Lagado(stack<int> &myStack, int x)
{
    // Base Case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    // Top element ko save kar lenge
    int num = myStack.top();
    myStack.pop();

    // Recursion kar lo
    Lagado(myStack, x);

    // Ab num ko ewapas laga do
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
        myStack.push(x);
    else
        Lagado(myStack, x);
    return myStack;
}






// To reverse a stack using recursion
void insertBottom(stack<int> &stk, int num)
{
    // Base Case
    if (stk.empty())
    {
        stk.push(num);
        return;
    }
    int n = stk.top();
    stk.pop();

    insertBottom(stk, num);

    stk.push(n);
}

void reverseStack(stack<int> &stk)
{
    // Base Case
    if (stk.empty())
        return;

    int num = stk.top();
    stk.pop();
    reverseStack(stk);

    insertBottom(stk, num);
}






// To sort a stack using recursion (top to bottom descending order)
void sortkardo(stack<int> &stk, int num)
{

    // Base case
    // Jaha par condition satifty ho jaegi waha par number ko push karke return ho jaenge 
    if (stk.empty() || (!stk.empty() && stk.top() < num))
    {
        stk.push(num);
        return;
    }

    int n = stk.top();
    stk.pop();

    sortkardo(stk, num);

    stk.push(n);
}

// call hoga
void sortStack(stack<int> &stk)
{
    // Base case
    if (stk.empty())
    {
        return;
    }
    int num = stk.top();
    stk.pop();

    sortStack(stk);
    // Stack khaali ho jaega 

    sortkardo(stk, num);
}


// To check if there is redundant brackets in an equation  
bool findRedundantBrackets(string &s) {
    stack<char> stk;

    for (int i = 0; i < s.size(); i++){
    
    if(s[i]=='(')
        stk.push('(');

    else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        stk.push(s[i]);

    else if(s[i]==')'){
        int cnt = 0;
        while(stk.top()!='('){
                cnt++;
                stk.pop();   
        }
        stk.pop();
        if(cnt==0){
            return true;
        }
    }
}
return false;
}



// Number of reversals to make a valid string 
// invalid strings patterns 
// 1. }}}}
// 2. {{{{
// 3. }}{{ 
int findMinimumCost(string str) {
    if(str.length()%2!=0)
    return -1;
    
    stack<char> stk;
    for (int i = 0; i < str.length(); i++) {
    if (str[i] == '{') 
        stk.push(str[i]);
    else{
        if (!stk.empty() && stk.top() == '{') {
        stk.pop();
        } else
        stk.push('}');
    }
    }
    int a=0,b=0;
    while(!stk.empty()){
        if(stk.top()=='{')
            a++;
        else
            b++;
        stk.pop();
    }

    // General expression bana lia cases ko uthakar 
    return ((a+1)/2) + ((b+1)/2);       
}


// Gives an array with next smaller element corresponding a given array (Prerequesite for largets rectangle question).
vector<int> nextSmallerElement0(vector<int> &arr, int n)
{
    stack<int> stk;
    vector<int> ans(n);
    stk.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(stk.top()>=curr){
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(curr);
    }
    return ans;
}



// Largest rectangle area in histogram .
vector<int> nextSmallerElement(vector<int> arr,int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(stk.top()!=-1 && curr<=arr[stk.top()])
                stk.pop();
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr,int n){
        stack<int> stk;
        vector<int> ans(n);
        stk.push(-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(stk.top()!=-1 && curr<=arr[stk.top()])
                stk.pop();
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        vector<int> prev(n); 
        prev = prevSmallerElement(heights,n);
        int maxi = -1;
        for(int i=0;i<n;i++){
            int l = heights[i];

            // To handle case where all elements are same so next will become -1. 
            if(next[i]==-1){
                next[i] = n;
            }

            int b = next[i] - prev[i] -1;
            
            int newArea = l*b;
            maxi = max(newArea,maxi);
        }
        return maxi;
    }

// Celebrity problem (celebrity knows no-one, everyone knows celebrity)
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i=0;i<n;i++)
            s.push(i);
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(M[a][b]==1)
                s.push(b);
            else
                s.push(a);
        }
        
        int candidate = s.top();
        
        // conditon 1
        int check=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0)
                check++;  
        }
        if(check!=n)
            return -1;
        
        // conditon 2
        int check1=0;
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1)
                check1++;  
        }
        if(check1!=n-1)
            return -1;
        return candidate;
    }

// Maximum rectangle area of a rectangle in a given matrix 
// 1100
// 1111    ans=12
// 1111

// int maxArea(int M[MAX][MAX], int n, int m) {
//         // S1: Calculate for first row 
//         int area = largestRectangleArea(M[0],m);
        
//         // S2: Baki k rows ke elements ko plus krte jana h aur area nikalte jana h
//         for(int i=1;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(M[i][j]!=0)
//                     M[i][j] = M[i][j] + M[i-1][j];
//                 else
//                     M[i][j] = 0;
//             }
//                 int maxi = largestRectangleArea(M[i],m);
                
//                 // S3: Maximum area le leni h 
//                 area = max(area,maxi);
//         }
//         return area;
//     }





// Stack with all operations   operator  O[1]
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;

    public:
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            mini = data;
        } 
        else
        {
        if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        return mini;
    } 
};



int main()
{

    // Reverse in string
    /* string str;
    cin>>str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    string ans = "";
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    cout<<ans;*/

    return 0;
}