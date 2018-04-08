/*
Problem Description:
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<1) return 0;
        vector<int> IS;
        IS.emplace_back(nums[0]);
        for(auto num:nums)
        {
            if(num>IS.back())
            {
                IS.emplace_back(num);
            }
            else
            {
                IS[lower_bound(IS.begin(),IS.end(),num)-IS.begin()]=num;
            }
        }
        return IS.size();
    }
};