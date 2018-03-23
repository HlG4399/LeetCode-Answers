/*
Problem Description:
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> temp;
        int sum=0,j=0;
        BackTracking(candidates, target,results,temp,sum,j);
        return results;
    }
    
    void BackTracking(vector<int>& candidates, int& target,vector<vector<int>>& results,vector<int>& temp,int& sum,int& j)
    {
        if(sum==target)
        {
            results.emplace_back(temp);
            return;
        }
        if(sum>target) return;
        int n=candidates.size();
        for(int i=j;i<n;i++)
        {
            temp.emplace_back(candidates[i]);
            sum+=candidates[i];
            BackTracking(candidates, target,results,temp,sum,i);
            temp.pop_back();
            sum-=candidates[i];
        }
    }
};