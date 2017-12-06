/*
Problem Description:
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        string t(2*s.size()+1,'#');
        for(int i=0;i!=s.size();i++)
        {
            t[2*i+1]=s[i];
        }
        vector<int> Len(t.size());
        int P=0,po=0,result=0;
        for(int i=0;i!=t.size();i++)
        {
            if(i<P)
            {
                Len[i]=min(P-i,Len[2*po-i]);
            }
            while(i-Len[i]-1>=0 && i+Len[i]+1<t.size() && t[i-Len[i]-1]==t[i+Len[i]+1]) 
            {
                Len[i]++;
            }
            if(i+Len[i]>P)
            {
                po=i;
                P=i+Len[i];
            }
            result+=(Len[i]+1)/2;
        }
        return result;
    }
};