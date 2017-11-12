/*
Problem Description:
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<=0)
        {
            return;
        }
        k=k>nums.size()?k%nums.size():k;
        reverseArray(nums,0,nums.size()-1);
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,nums.size()-1);
    }
    
    void reverseArray(vector<int>& nums, int a,int b)
    {
        while(a<b)
        {
            swap(nums[a],nums[b]);
            a++;b--;
        }
    }
};