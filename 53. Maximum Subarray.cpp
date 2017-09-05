/*
Problem Description:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0],temp=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            temp=max(temp+nums[i],nums[i]);
            result=max(result,temp);
        }
        return result;
    }
};