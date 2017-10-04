/*
Problem Description:
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int a=0,b=s.size()-1;
        bool result=true;
        while(a<b)
        {
            if(s[a]==s[b])
            {
                a++;
                b--;
            }
            else
            {
                result=false;
                break;
            }
        }
        return result;
    }
};