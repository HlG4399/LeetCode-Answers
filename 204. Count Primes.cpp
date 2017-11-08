/*
Problem Description:
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        int result=0;
        vector<bool> isPrime(n-1,true);
        isPrime[0]=false;
        for(int i=2;i<=sqrt(n);i++)
        {
            for(int j=i*i;j<n;j+=i)
            {
                isPrime[j-1]=false;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            result=isPrime[i]?result+1:result;
        }
        return result;
    }
};