/*
Problem Description:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size(),p1=0,p2=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                p1=(i-1>0?dp[i-1][j]:INT_MAX);
                p2=(j-1>0?dp[i][j-1]:INT_MAX);
                dp[i][j]=(p1==INT_MAX && p2==INT_MAX?grid[i-1][j-1]:min(p1,p2)+grid[i-1][j-1]);
            }
        }
        return dp[m][n];
    }
};