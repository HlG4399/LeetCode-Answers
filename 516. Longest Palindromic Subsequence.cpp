/*
Problem Description:
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=len-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<len;j++)
            {
                dp[i][j]=(s[i]==s[j]?dp[i+1][j-1]+2:max(dp[i+1][j],dp[i][j-1]));
            }
        }
        return dp[0][len-1];
    }
};