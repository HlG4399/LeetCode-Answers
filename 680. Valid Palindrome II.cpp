/*
Problem Description:
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        return LCS(s,0,s.size()-1,1);
    }    
    
    bool LCS(string s,int l,int r,int depth)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return depth>0 && (LCS(s,l+1,r,depth-1) || LCS(s,l,r-1,depth-1));
            }
            l++;r--;
        }
        return true;
    }
};