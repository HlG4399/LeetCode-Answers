/*
Problem Description:
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> results;
        vector<int> temp;
        BackTracking(nums,results,temp,0);
        return vector<vector<int>>(results.begin(),results.end());
    }
    
    void BackTracking(vector<int>& nums,set<vector<int>>& results, vector<int>& temp,int start)
    {
        if(temp.size()>1) results.insert(temp);
        int n=nums.size();
        for(int i=start;i<n;i++)
        {
            if(temp.empty() || nums[i]>=temp.back())
            {
                temp.emplace_back(nums[i]);
                BackTracking(nums,results,temp,i+1);
                temp.pop_back();
            }
        }
    }
};