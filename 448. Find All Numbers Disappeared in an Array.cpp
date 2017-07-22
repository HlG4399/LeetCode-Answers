/*
Problem Description:
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i!=nums.size();i++)
        {
            int temp=(nums[i]>nums.size()?nums[i]-nums.size():nums[i]);
            if(nums[i]>nums.size())
            {
                if(nums[nums[i]-nums.size()-1]<=nums.size())
                {
                    nums[nums[i]-nums.size()-1]+=nums.size();
                }
            }
            else
            {
                if(nums[nums[i]-1]<=nums.size())
                {
                    nums[nums[i]-1]+=nums.size();
                }
            }
        }
        for(int i=0;i!=nums.size();i++)
        {
            if(nums[i]<=nums.size())
            {
                result.push_back(i+1);
            }
        }
        return result;
    }
};