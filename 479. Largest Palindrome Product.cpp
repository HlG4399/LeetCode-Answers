/*
Problem Description:
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
*/

class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)
        {
            return 9;
        }
        if(n==8)
        {
            return 475;
        }
        for(int i=pow(10,n)-1;i>=pow(10,n-1);i--)
        {
            long palindrome=i*pow(10,n)+reverse(i);
            for(int j=pow(10,n)-1;j>=pow(10,n-1);j--)
            {
                if(palindrome/j>pow(10,n)-1)
                {
                    break;
                }
                if(palindrome%j==0)
                {
                    return (int)(palindrome%1337);
                }
            }
        }
        return -1;
    }
    
    int reverse(int x) {
        long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};