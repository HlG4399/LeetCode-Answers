/*
Problem Description:
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
public:
    vector<int> numArray;
    NumArray(vector<int> nums) {
        numArray.emplace_back(0);
        for(auto num:nums)
        {
            numArray.emplace_back(numArray.back()+num);
        }
    }
    
    int sumRange(int i, int j) {
        return numArray[j+1]-numArray[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */