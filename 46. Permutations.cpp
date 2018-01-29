/*
Problem Description:
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_set<int> visited_index;
        vector<int> visited_nums;
        BackTracking(visited_index,visited_nums,nums,results);
        return results;
    }
    
    void BackTracking(unordered_set<int>& visited_index,vector<int>& visited_nums,vector<int>& nums,vector<vector<int>>& results)
    {
        if(visited_nums.size()==nums.size())
        {
            results.emplace_back(visited_nums);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited_index.find(i)==visited_index.end())
            {
                visited_index.insert(i);
                visited_nums.emplace_back(nums[i]);
                BackTracking(visited_index,visited_nums,nums,results);
                visited_index.erase(i);
                visited_nums.pop_back();
            }
        }
    }
};