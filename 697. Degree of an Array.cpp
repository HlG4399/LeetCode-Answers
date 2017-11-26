/*
Problem Description:
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> num_count,min_index,max_index;
        int max_count=0,result=INT_MAX;
        for(int i=0;i!=nums.size();i++)
        {
            num_count[nums[i]]++;
            if(min_index[nums[i]]==0)
            {
                min_index[nums[i]]=i+1;
            }
            max_index[nums[i]]=i+1;
            max_count=max(max_count,num_count[nums[i]]);
        }
        for(auto it=num_count.begin();it!=num_count.end();it++)
        {
            if(it->second==max_count)
            {
                result=min(result,max_index[it->first]-min_index[it->first]+1);
            }
        }
        return result;
    }
};