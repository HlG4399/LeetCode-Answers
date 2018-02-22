/*
Problem Description:
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        map<int,int> map;
        for(auto num:nums)
        {
            map[num]++;
        }
        vector<int> _nums;
        for(auto it=map.begin();it!=map.end();it++)
        {
            _nums.emplace_back(it->first);
        }
        int n=_nums.size();
        vector<int> dp(n,0);
        dp[0]=_nums[0]*map[_nums[0]];
        if(n<2) return dp[0];
        dp[1]=(_nums[1]-_nums[0]==1?max(_nums[1]*map[_nums[1]],dp[0]):dp[0]+_nums[1]*map[_nums[1]]);
        for(int i=2;i<n;i++)
        {
            if(_nums[i]-_nums[i-1]==1)
            {
                dp[i]=max(_nums[i]*map[_nums[i]]+dp[i-2],dp[i-1]);
            }
            else
            {
                dp[i]=dp[i-1]+_nums[i]*map[_nums[i]];
            }
        }
        return dp[n-1];
    }
};