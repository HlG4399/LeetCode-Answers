/*
Problem Description:
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> results;
        for(auto num:nums)
        {
            if(nums[abs(num)-1]>0)
            {
                nums[abs(num)-1]*=-1;
            }
            else
            {
                results.emplace_back(abs(num));
            }
        }
        for(int i=0;i!=nums.size();i++)
        {
            if(nums[i]>0)
            {
                results.emplace_back(i+1);
                break;
            }
        }
        return results;
    }
};