/*
Problem Description:
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len_A=A.size(),len_B=B.size(),result=0,a=0,b=1;
        vector<vector<int>> dp(2,vector<int>(len_B+1,0));
        for(int i=1;i<=len_A;i++)
        {
            for(int j=1;j<=len_B;j++)
            {
                dp[b][j]=(A[i-1]==B[j-1]?dp[a][j-1]+1:0);
                result=max(result,dp[b][j]);
            }
            swap(a,b);
        }
        return result;
    }
};