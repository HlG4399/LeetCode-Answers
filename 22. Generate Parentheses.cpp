/*
Problem Description:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)
        {
            return {""};
        }
        stack<char> s;
        vector<string> results;
        BackTracking(s,"",results,n);
        return results;
    }
    
    void BackTracking(stack<char> s,string str,vector<string>& results,int n)
    {
        if(s.empty()&&n==0)
        {
            results.emplace_back(str);
            return;
        }
        if(n>0)
        {
            s.push('(');
            BackTracking(s,str+'(',results,n-1);
            s.pop();
        }
        if(s.size()>0)
        {
            s.pop();
            BackTracking(s,str+')',results,n);                    
        }       
    }
};