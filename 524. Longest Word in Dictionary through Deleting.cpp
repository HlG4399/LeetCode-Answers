/*
Problem Description:
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
    string findLongestWord(string str, vector<string>& ds) {
        if(str.size()==0 || ds.size()==0) return "";
        set<string> s;
        int p=0,q=0,d_len=0,s_len=str.size(),pre_len=0;
        for(auto d:ds)
        {
            d_len=d.size();
            if(pre_len>d_len) continue;
            p=0;
            q=0;
            while(p<s_len && q<d_len)
            {
                if(str[p]==d[q]) q++;
                p++;
            }
            if(q==d_len) 
            {
                if(pre_len<d_len && !s.empty()) s.clear();
                s.insert(d);
                pre_len=d_len;
            }
        }
        return s.empty()?"":*s.begin();
    }
};