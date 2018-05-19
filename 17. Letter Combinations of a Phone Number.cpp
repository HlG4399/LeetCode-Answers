/*
Problem Description:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        unordered_map<char,vector<char>> hash;
        hash['2']={'a','b','c'};
        hash['3']={'d','e','f'};
        hash['4']={'g','h','i'};
        hash['5']={'j','k','l'};
        hash['6']={'m','n','o'};
        hash['7']={'p','q','r','s'};
        hash['8']={'t','u','v'};
        hash['9']={'w','x','y','z'};
        vector<string> results;
        string temp="";
        BackTracking(digits,results,temp,hash,0,n);
        return results;
    }
    
    void BackTracking(string& digits,vector<string>& results,string& temp,unordered_map<char,vector<char>>& hash,int start,int& n)
    {
        if(temp.size()==n) results.emplace_back(temp);
        for(int i=start;i<n;i++)
        {
            if(digits[i]=='1') continue;
            for(auto c:hash[digits[i]])
            {
                temp+=c;
                BackTracking(digits,results,temp,hash,i+1,n);
                temp.erase(temp.size()-1,1);
            }
        }
    }
};