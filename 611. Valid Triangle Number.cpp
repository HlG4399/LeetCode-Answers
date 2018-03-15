/*
Problem Description:
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1,k=i+2;k<n;k++)
            {
                while(j<k && nums[i]+nums[j]<=nums[k]) j++;
                result+=k-j;
            }
        }
        return result;
    }
};