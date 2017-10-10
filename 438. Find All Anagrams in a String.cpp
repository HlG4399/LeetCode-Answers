/*
Problem Description:
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(26,0),pv(26,0),results;
        for(auto ch:p)
        {
            pv[ch-'a']++;
        }
        for(int i=0;i!=p.size();i++)
        {
            sv[s[i]-'a']++;
        }
        if(sv==pv)
        {
            results.emplace_back(0);
        }
        for(int a=1,b=p.size();b<s.size();a++,b++)
        {
            sv[s[b]-'a']++;
            sv[s[a-1]-'a']--;
            if(sv==pv)
            {
                results.emplace_back(a);
            }
        }
        return results;
    }
};