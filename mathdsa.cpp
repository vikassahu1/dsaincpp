// Sieve of Eratosthenes 

#include <iostream>
#include <vector>
using namespace std;



// To find number of prime numbers between 1 and a number n. 
// TC:   O[nlog(logn)]

int isPrime(int n){
    int cnt=0;
    vector<bool> prime(n+1,true); 
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2*i; j < n; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    return cnt;
}

// GCD = gcd(a,b) = gcd(a-b, b) = gcd(a%b, b)
// gcd(a,b) * lcm(a,b) = a*b  

int gcd(int a,int b){
    if(a==0)
        return a;
    if(b==0)
        return b;
    while (a!=b)
    {
        if (b>a){
            b=b-a;
        }
        else
            a=a-b;
    }
    return a;
}


// Answer in the 10^9+7 
unsigned long long factorial(int num){
    const unsigned int M = 1000000007;

    unsigned long long f = 1;
    for (int i = 1; i <= num; i++)
        f = (f*i) % M;  // Now f never can
                        // exceed 10^9+7
    return f;
}

int main(){
    // cout<<isPrime(40)<<endl;
    cout<< factorial(212) << endl;
    return 0;
}