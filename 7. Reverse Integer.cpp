/*
Problem Description:
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        int a=0,b=s.size()-1;
        while(a<b)
        {
            if(s[a]=='-')
            {
                a++;
                continue;
            }
            swap(s[a],s[b]);
            a++;b--;
        }
        a=(s[0]=='-'?1:0);
        for(b=a;s[b]=='0';b++);
        if(b-1>=0)
        {
            s.erase(s.begin()+a,s.begin()+b);
        }
        int result=atoi(s.c_str());
        return to_string(result)==s?result:0;
    }
};