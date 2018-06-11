/*
Problem Description:
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    string reorganizeString(string S) {
        int n=S.size();
        if(n==0) return "";
        unordered_map<char,int> hash;
        int maxChar=S[0];
        for(int i=0;i<n;i++) 
        {
            hash[S[i]]++;
            if(hash[S[i]]>hash[maxChar]) maxChar=S[i];
        }
        int m=hash[maxChar];
        if(2*m-1>n) return "";
        vector<string> temp(m);
        for(int i=0;i<m;i++) temp[i]+=maxChar;
        hash[maxChar]=0;
        for(int i=0,k=0;i<n;i++)
        {
            for(int j=hash[S[i]];j>0;j--)
            {
                temp[k]+=S[i];
                k=(k+1)%m;
            }
            hash[S[i]]=0;
        }
        string result="";
        for(int i=0;i<m;i++) result+=temp[i];
        return result;
    }
};