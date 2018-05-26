/*
Problem Description:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> results;
        vector<int> temp;
        BackTracking(candidates, target,results,temp,0);
        return vector<vector<int>>(results.begin(),results.end());
    }
    
    void BackTracking(vector<int>& candidates, int target,set<vector<int>>& results,vector<int>& temp,int start)
    {
        if(target<0) return;
        if(target==0) results.insert(temp);
        int n=candidates.size();
        for(int i=start;i<n;i++)
        {
            temp.emplace_back(candidates[i]);
            BackTracking(candidates, target-candidates[i],results,temp,i+1);
            temp.pop_back();
        }
    }
};