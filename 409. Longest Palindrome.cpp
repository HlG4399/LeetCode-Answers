/*
Problem Description:
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int result=0;
        unordered_map<char,int> ch_nums;
        for(auto ch:s)
        {
            ch_nums[ch]++;
        }
        for(unordered_map<char,int>::iterator iter=ch_nums.begin();iter!=ch_nums.end();iter++ )
        {
            if(iter->second>=2)
            {
                result+=iter->second/2*2;
            }
        }
        return result!=s.size()?result+1:result;
    }
};