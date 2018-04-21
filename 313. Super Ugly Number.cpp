/*
Problem Description:
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n<1) return 0;
        int len=primes.size();
        vector<int> indexs(len,0),dp(n);
        dp[0]=1;
        int minIndex=-1,minValue=INT_MAX,temp;
        for(int i=1;i<n;)
        {
            minValue=INT_MAX;
            for(int j=0;j<len;j++)
            {
                temp=dp[indexs[j]]*primes[j];
                if(temp<minValue){
                    minValue=temp;
                    minIndex=j;
                }                
            }
            indexs[minIndex]++;
            if(dp[i-1]!=minValue){
                dp[i]=minValue;
                i++;
            }
        }
        return dp[n-1];
    }
};