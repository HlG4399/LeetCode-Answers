/*
Problem Description:
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        if(len1==0 || len2==0 || len1>len2) return false;
        vector<int> hash1(26),hash2(26);
        for(int i=0;i<len1;i++)
        {
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }
        if(hash1==hash2) return true;
        for(int i=0;i+len1<len2;i++)
        {
            hash2[s2[i]-'a']--;
            hash2[s2[i+len1]-'a']++;
            if(hash1==hash2) return true;
        }
        return false;
    }
};