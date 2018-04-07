/*
Problem Description:
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.


Note:
Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        }
        return 0;
    }
};