// Square root of a number using binary search to a specific precision point. 

#include <iostream>
using namespace std;

long long int Sqrt(int num){
    int s = 1;
    int e = num;
    float mid = s+(e-s)/2;
    long long int ans = -1;
    while (s<=e)
    {
        // cause mid*mid can vbe a huge number, we stored it in long int . 
        long long int square = mid*mid;
        if (square == num)
        {
            return mid;
        }
        else if (square > num)
        {
            e = mid-1;
        }
        else{
            // here since mid is smaller than actual solution. It can be a root. So, We have to store it.
            ans = mid;
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

double morePrecision(int n,int precision,int tempsol){
    double ans = tempsol;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor/=10;
        for (double j = ans; j*j < n; j=j+factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int tempsol = Sqrt(37);
    cout<< "Answer is "<<morePrecision(37,3,tempsol)<<endl;
    return 0;
}