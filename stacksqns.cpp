#include <iostream>
#include <stack>
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






// To sort a stack using recursion
void sortkardo(stack<int> &stk, int num)
{

    // Base case
    // Jaha par condition satifty ho jaegi waha par number ko push karke return ho jaenge 
    if (stk.empty() || (stk.empty() && stk.top() < num))
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