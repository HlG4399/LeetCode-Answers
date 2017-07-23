/*
Problem Description:
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

class Solution {
public:
    int getSum(int a, int b) {
        int result=a^b;
        while(a&b)
        {
            int temp=(a&b)<<1;
            a=result;
            b=temp;
            result=a^b;
        }
        return result;
    }
};