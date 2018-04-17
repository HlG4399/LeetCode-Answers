/*
Problem Description:
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string>> hash;
        string temp;
        for(auto str:strs)
        {
            temp=str;
            sort(temp.begin(),temp.end());
            hash[temp].insert(str);
        }
        vector<vector<string>> results;
        for(auto h:hash)
        {
            vector<string> temp(h.second.begin(),h.second.end());
            results.emplace_back(temp);
        }
        return results;
    }
};