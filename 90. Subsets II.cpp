/*
Problem Description:
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> results;
        vector<int> temp;
        BackTracking(nums,results,temp,0);
        return vector<vector<int>>(results.begin(),results.end());
    }
    
    void BackTracking(vector<int>& nums,set<vector<int>>& results,vector<int>& temp,int start)
    {
        results.insert(temp);
        int n=nums.size();
        for(int i=start;i<n;i++)
        {
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.emplace_back(nums[i]);
            BackTracking(nums,results,temp,i+1);
            temp.pop_back();
        }
    }
};