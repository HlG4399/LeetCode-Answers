/*
Problem Description:
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum;
        sum.emplace_back(0);
        for(int i=0;i!=n;i++)
        {
            sum.emplace_back(sum.back()+2*nums[i]-1);
        }
        unordered_map<int,int> map;
        int result=0;
        for(int i=0;i<=n;i++)
        {
            if(map.count(sum[i])>0)
            {
                result=max(result,i-map[sum[i]]);
            }
            else
            {
                map[sum[i]]=i;
            }
        }
        return result;
    }
};