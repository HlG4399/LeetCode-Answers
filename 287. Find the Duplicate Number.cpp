/*
Problem Description:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size()==0?-1:(nums[0]==0?0:-1);
        }
        int i=0,j=0;
        do
        {
            i=nums[nums[i]];
            j=nums[j];
        }while(i!=j);
        i=0;
        do
        {   
            i=nums[i];
            j=nums[j];
        }while(i!=j);
        return i;
    }
};