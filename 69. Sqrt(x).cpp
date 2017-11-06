/*
Problem Description:
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
        {
            return 0;
        }
        int a=1,b=46341,mid=0;
        while(a<b)
        {
            if(mid==(a+b)/2)
            {
                break;
            }
            mid=(a+b)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else
            {
                if(mid*mid>x)
                {
                    b=mid;
                }
                else
                {
                    a=mid;
                }
            }
        }
        return mid;
    }
};