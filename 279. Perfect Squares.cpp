/*
Problem Description:
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            dp[i]=i;
        }
        int m=sqrt(n),temp=0,num=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=m;j++)
            {
                temp=j*j;
                if(temp>i) continue;
                num=i/temp;
                dp[i]=min(dp[i],dp[i-num*temp]+num);
            }
        }
        return dp[n];
    }
};