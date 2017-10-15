/*
Problem Description:
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        char* p=strtok(&str[0]," ");
        vector<string> p_str;
        unordered_map<char,string> p2s;
        unordered_map<string,char> s2p;
        while(p)
        {
            p_str.emplace_back(p);
            p=strtok(NULL," ");
        }
        if(p_str.size()!=pattern.size())
        {
            return false;
        }
        for(int i=0;i!=p_str.size();i++)
        {
            if(p2s[pattern[i]]!="")
            {
                if(p2s[pattern[i]]!=p_str[i])
                {
                    return false;
                }
            }
            else
            {
                p2s[pattern[i]]=p_str[i];               
            }
        }
        for(int i=0;i!=p_str.size();i++)
        {
            if(s2p[p_str[i]]!=NULL)
            {
                if(s2p[p_str[i]]!=pattern[i])
                {
                    return false;
                }
            }
            else
            {
                s2p[p_str[i]]=pattern[i];               
            }
        }
        return true;

    }
};