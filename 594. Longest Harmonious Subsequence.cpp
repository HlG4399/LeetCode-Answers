/*
Problem Description:
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int a=1,b=0,pre_num=nums[0],result=0;
        for(int i=1;i!=nums.size();i++)
        {
            if(nums[i]==pre_num)
            {
                a++;
            }
            else if(nums[i]-pre_num==1)
            {
                pre_num=nums[i];
                b=a;
                a=1;
            }
            else
            {
                pre_num=nums[i];
                b=0;
                a=1;                      
            }
            result=(b!=0?max(result,a+b):result);
        }
        return result;
    }
};