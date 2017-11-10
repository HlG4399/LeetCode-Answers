/*
Problem Description:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int a=0,b=s.size()-1;
        while(a<b)
        {
            if(!((s[a]>=48 && s[a]<=57) || (s[a]>=97 && s[a]<=122) || (s[a]>=65 && s[a]<=90)))
            {
                a++;
                continue;
            }
            if(!((s[b]>=48 && s[b]<=57) || (s[b]>=97 && s[b]<=122) || (s[b]>=65 && s[b]<=90)))
            {
                b--;
                continue;
            }
            if(s[a]==s[b] || (s[a]>= 65 && s[b]>=65 && abs(s[a]-s[b])==32))
            {
                a++;b--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};