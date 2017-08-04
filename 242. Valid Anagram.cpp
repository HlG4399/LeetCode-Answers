/*
Problem Description:
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        for(auto ch:s)
        {
            int pos=t.find(ch,0);
            if(pos!=-1)
            {
                t.erase(pos,1);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};