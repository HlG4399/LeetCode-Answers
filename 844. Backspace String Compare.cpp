/*
Problem Description:
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1,s2;
        for(auto s:S)
        {
            if(s!='#') s1.push(s);
            else if(!s1.empty()) s1.pop();
        }
        for(auto t:T)
        {
            if(t!='#') s2.push(t);
            else if(!s2.empty()) s2.pop();
        }
        if(s1.size()!=s2.size()) return false;
        while(!s1.empty())
        {
            if(s1.top()!=s2.top()) return false;
            s1.pop(),s2.pop();
        }
        return true;
    }
};