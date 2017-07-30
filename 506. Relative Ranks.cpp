/*
Problem Description:
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> results(nums.size());
        vector<size_t> idx(nums.size());
        for (int i = 0; i != nums.size(); i++)
	    {
		    idx[i] = i;
	    }
        std::sort(idx.begin(),idx.end(),[& nums](size_t i1,size_t i2){return nums[i1]<nums[i2];});
        for(int i=idx.size()-1;i>=0;i--)
        {
            if(i==idx.size()-1)
            {
                results[idx[i]]="Gold Medal";
                continue;
            }
            if(i==idx.size()-2)
            {
                 results[idx[i]]="Silver Medal";
                 continue;
            }
            if(i==idx.size()-3)
            {
                results[idx[i]]="Bronze Medal";
                continue;
            }
            results[idx[i]]=to_string(idx.size()-i);
        }
        return results;
    }
};