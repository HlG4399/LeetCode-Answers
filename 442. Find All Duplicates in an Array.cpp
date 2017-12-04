/*
Problem Description:
Given an array of integers, 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> results;
        for(auto num:nums)
        {
            if(nums[abs(num)-1]<0)
            {
                results.emplace_back(abs(num));
            }
            nums[abs(num)-1]*=-1;
        }
        return results;
    }
};