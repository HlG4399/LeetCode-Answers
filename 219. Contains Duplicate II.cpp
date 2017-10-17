/*
Problem Description:
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int absolute_difference=INT_MAX;
        for(int i=0;i!=nums.size();i++)
        {
            if(hash[nums[i]]!=0)
            {
                absolute_difference=min(absolute_difference,abs(i+1-hash[nums[i]]));
                hash[nums[i]]=max(hash[nums[i]],i+1);
            }
            else
            {
                hash[nums[i]]=i+1;
            }          
        }
        return absolute_difference<=k && absolute_difference!=-1;
    }
};