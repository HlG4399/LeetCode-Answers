/*
Problem Description:
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n : nums) 
        {
            m[n]++;
        }
        int max=0,result=0;
        for(auto n:nums) 
        {
            if(max<m[n])
            {
                max=m[n];
                result=n;
            }
        }
        return result;
    }
};