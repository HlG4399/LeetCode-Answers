/*
Problem Description:
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> subset;
        BackTracking(nums,results,subset,0);
        return results;
    }
    
    void BackTracking(vector<int>& nums,vector<vector<int>>& results,vector<int>& subset,int start)
    {
        results.emplace_back(subset);
        int n=nums.size();
        for(int i=start;i<n;i++)
        {
            subset.emplace_back(nums[i]);
            BackTracking(nums,results,subset,i+1);
            subset.pop_back();
        }
    }
};