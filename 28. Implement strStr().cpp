/*
Problem Description:
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=1,j=1;
        vector<int> nextval(needle.size()+1,0);
        get_nextval(needle,nextval);
        while(i<=haystack.size() && j<=needle.size())
        {
            if(j==0 || haystack[i-1]==needle[j-1])
            {
                ++i;++j;
            }
            else
            {
                j=nextval[j];
            }
        }
        return j>needle.size()?i-needle.size()-1:-1;
    }
    
    void get_nextval(string T,vector<int>& nextval)
    {
        //求模式串T的next函数修正值并存入数组nextval
        int i=1,j=0;
        nextval[1]=0;
        while(i<T.size())
        {
            if(j==0 || T[i-1]==T[j-1])
            {
                ++i;++j;
                nextval[i]=(T[i-1]!=T[j-1]?j:nextval[j]);
            }
            else
            {
                j=nextval[j];
            }
        }
    }
};