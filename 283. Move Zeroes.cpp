/*
Problem Description:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)
        {
            return;
        }
        int a=-1,b=-1,temp=0;
        for(int i=0;i!=nums.size();i++)
        {
            if(nums[i]==0 && a==-1)
            {
                a=i;
            }
            if(nums[i]!=0 && i>a && a>-1)
            {
                b=i;
            }
            if(b>a)
            {
                temp=nums[a];
                nums[a]=nums[b];
                nums[b]=temp;
                a++;
                b=-1;
            }
        }
    }
};