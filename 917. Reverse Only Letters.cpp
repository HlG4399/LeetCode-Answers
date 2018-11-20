/*
Problem Description:
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n=S.size();
        if(n==0) return "";
        string letter_str="";
        for(auto c:S)
            if((c>=65 && c<=90) || (c>=97 && c<=122)) letter_str+=c;
        reverse(letter_str.begin(),letter_str.end());
        for(int i=0,j=0;i<n;i++)
        {
            if((S[i]>=65 && S[i]<=90) || (S[i]>=97 && S[i]<=122)) S[i]=letter_str[j++];
        }
        return S;
    }
};