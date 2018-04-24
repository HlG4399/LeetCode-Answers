/*
Problem Description:
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        vector<bool> visited(nums.size(),false);
        return Partition(nums,k,visited,sum/k,0,0);
    }
    
    bool Partition(vector<int>& nums,int k,vector<bool>& visited,int target,int tempSum,int start)
    {
        if(k==1) return true;
        if(tempSum==target) return Partition(nums,k-1,visited,target,0,0);
        int n=nums.size();
        for(int i=start;i<n;i++)
        {
            if(visited[i]) continue;
            visited[i]=true;
            if(Partition(nums,k,visited,target,tempSum+nums[i],i+1)) return true;
            visited[i]=false;
        }
        return false;
    }
};