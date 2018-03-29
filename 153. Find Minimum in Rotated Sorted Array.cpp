/*
Problem Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        int a=0,b=n-1,mid=0;
        while(a<b)
        {
            if(nums[a]<=nums[b]) return nums[a];
            mid=(a+b)/2;
            if(nums[mid]>=nums[a])
            {
                a=mid+1;
            }
            else
            {
                b=mid;
            }
        }
        return nums[a];
    }
};