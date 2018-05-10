/*
Problem Description£º

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> hash1,hash2;
        for(auto num:nums) hash1[num]++;
        for(auto num:nums)
        {
            if(hash1[num]==0) continue;
            if(hash2[num]>0)
            {
                hash2[num]--;
                hash2[num+1]++;
                hash1[num]--;
            }
            else
            {
                if(hash1[num+1]>0 && hash1[num+2]>0)
                {
                    hash2[num+3]++;
                    hash1[num]--;
                    hash1[num+1]--;
                    hash1[num+2]--;
                }
                else return false;
            }
        }
        return true;
    }
};