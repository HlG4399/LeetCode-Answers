/*
Problem Description:
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> combinations;
        BackTracking(combinations,results,1,k,n);
        return results;
    }
    
    void BackTracking(vector<int>& combinations,vector<vector<int>>& results,int level,int k,int n)
    {
        if(n<0)
        {
            return;
        }
        if(k==0&&n==0)
        {
            results.emplace_back(combinations);
        }
        for(int i=level;i<=9;i++)
        {
            combinations.emplace_back(i);
            BackTracking(combinations,results,i+1,k-1,n-i);
            combinations.pop_back();
        }
    }
};