/*
Problem Description:
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum=0,min_value=10000000000;
        for(int i=0;i!=nums.size();i++)
        {
            sum+=nums[i];
            if(min_value>nums[i])
            {
                min_value=nums[i];
            }
        }
        return sum-min_value*nums.size();
    }
};