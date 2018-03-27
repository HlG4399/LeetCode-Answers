/*
Problem Description:
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
*/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        deque<int> nums;
        int temp=N;
        while(temp>0)
        {
            nums.push_front(temp%10);
            temp/=10;
        }
        bool isDecrease=false;
        int pos=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                isDecrease=true;  
                pos=i-1;
                break;
            }
        }
        if(!isDecrease) return N;
        for(int i=0;i<pos;i++)
        {
            if(nums[i]==nums[pos])
            {
                pos=i;
                break;
            }
        }
        int result=0;
        for(int i=0;i<pos;i++)
        {
            result=result*10+nums[i];
        }
        result=result*10+nums[pos]-1;
        int n=nums.size();
        for(int i=pos+1;i<n;i++)
        {
            result=result*10+9;
        }
        return result;
    }
};