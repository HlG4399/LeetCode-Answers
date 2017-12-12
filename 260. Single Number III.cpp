/*
Problem Description:
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int resultExclusive=0,i=31;
        for(auto num:nums)
        {
            resultExclusive^=num;
        }
        bitset<32> b(resultExclusive);
        for(;i>=0;i--)
        {
            if(b[i]==1)
            {
                break;
            }
        }
        vector<int> results(2);
        for(auto num:nums)
        {
            bitset<32> b(num);
            if(b[i]==1)
            {
                results[0]^=num;
            }
            else
            {
                results[1]^=num;
            }
        }
        return results;
    }
};