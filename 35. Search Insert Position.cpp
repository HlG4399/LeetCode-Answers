/*
Problem Description:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a=0,b=nums.size()-1;
        while(a<b)
        {
            int mid=a/2+b/2;
            if(nums[mid]<target)
            {
                if(mid+1<nums.size() && target<=nums[mid+1])
                {
                    return mid+1;
                }
                a=mid+1;
            }
            else
            {
                if(nums[mid]==target)
                {
                    return mid;
                }
                else
                {
                    if(mid-1>=0 && target>=nums[mid-1])
                    {
                        return target>nums[mid-1]?mid:mid-1;
                    }
                    b=mid-1;
                }
            }
        }
        if(a==0 && a==b && nums[0]>=target)
        {
            return 0;
        }
        if(b==nums.size()-1 && a==b && nums[nums.size()-1]<=target)
        {
            return nums[nums.size()-1]<target?nums.size():nums.size()-1;
        }
        return 0;
    }
};