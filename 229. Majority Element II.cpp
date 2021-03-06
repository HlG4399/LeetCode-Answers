/*
Problem Description:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> results;
        int num1=INT_MAX,num2=INT_MAX;
        int count1=0,count2=0;
        for(auto num:nums)
        {
            if(num==num1)
            {
                count1++;
            }
            else if(num==num2)
            {
                count2++;
            }
            else if(count1==0)
            {
                num1=num;
                count1++;
            }
            else if(count2==0)
            {
                num2=num;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;count2=0;
        for(auto num:nums)
        {
            if(num==num1)
            {
                count1++;
            }
            else if(num==num2)
            {
                count2++;
            }
        }
        if(count1>nums.size()/3)
        {
            results.push_back(num1);
        }
        if(count2>nums.size()/3)
        {
            results.push_back(num2);
        }
        return results;
    }
};