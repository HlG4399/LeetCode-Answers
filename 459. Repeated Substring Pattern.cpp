/*
Problem Description:
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size()+1,0);
        next[0]=-1;
        int i=0,k=-1;
        while(i<s.size())
        {
            if(k==-1 || s[i]==s[k])
            {
                next[++i]=++k;
            }
            else
            {
                k=next[k];
            }
        }
        return next[s.size()] && next[s.size()]%(s.size()-next[s.size()])==0;
    }
};