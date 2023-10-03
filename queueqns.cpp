#include <bits/stdc++.h>
#include <queue>
using namespace std;

// To reverse a queue
void reverse(queue<int> &q)
{
    if (q.empty())
        return;
    int a = q.front();
    q.pop();
    reverse(q);
    q.push(a);
}

queue<int> rev(queue<int> q)
{
    if (q.size() == 1)
        return q;
    else
        reverse(q);
    return q;
}

// to find first negative number in the k window
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    int negative = -1;

    // process first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // push ans for FIRST window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // now process for remaining windows
    for (int i = K; i < N; i++)
    {
        // first pop out of window element

        if (!dq.empty() && (i - dq.front()) >= K)
        {
            dq.pop_front();
        }

        // then push current element
        if (A[i] < 0)
            dq.push_back(i);

        // put in ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}



// Petrol pump question (INTERESTING)
// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int balance = 0, deficit = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        // peeche ke deficit ko store kar lenge taki wapas na traverse karna pare.
        if (balance < 0)
        {
            start = i + 1;
            deficit += balance;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
        return start;
    return -1;
}


// Sum of minimum and maximum elements of all subarrays of size k. tc o[n]
// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18    
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4 
int maxsum(int *arr,int n,int k ){
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window 
    for (int i = 0; i < k; i++)
    {
        // order m rakhkar sirf ek element bachne chahiye queue k andar
        while (!maxi.empty() && arr[maxi.back()]<=arr[i])
        {
            maxi.pop_back();
        }
        
        while (!mini.empty() && arr[mini.back()]>=arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans+=arr[maxi.front()]+arr[mini.front()];

    // remaining window process 
    for (int i = k; i < n; i++)
    {
        // next window 
        // removal 
        while (!maxi.empty() && i-maxi.front()>=k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i-mini.front()>=k)
        {
            mini.pop_front();
        }
        
        // addition 
        while (!maxi.empty() && arr[maxi.back()]<=arr[i])
        {
            maxi.pop_back();
        }
        
        while (!mini.empty() && arr[mini.back()]>=arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        ans+=arr[maxi.front()]+arr[mini.front()];
    }
    return ans;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    cout<< maxsum(arr,7,4)<<endl;
    return 0;
}