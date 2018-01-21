/*
Problem Description£»
Given a non-empty array of numbers, a0, a1, a2, ¡­ , an-1, where 0 ¡Ü ai < 231.

Find the maximum result of ai XOR aj, where 0 ¡Ü i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result=0,mark=0,temp=0;
        unordered_set<int> set;
        for(int i=31;i>=0;i--)
        {
            mark|=(1<<i);
            set.clear();
            for(auto num:nums)
            {
                set.insert(num&mark);
            }
            temp=result|(1<<i);
            for(auto it=set.begin();it!=set.end();it++)
            {
                if(set.find(temp^(*it))!=set.end())
                {
                    result=temp;
                    break;
                }
            }
        }
        return result;
    }
};