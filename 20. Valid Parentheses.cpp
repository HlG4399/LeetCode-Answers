/*
Problem Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stk.push(ch);
            }
            else
            {
                switch(ch)
                {
                    case ')':
                        if(!stk.empty() && stk.top()=='(')
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                   case '}':
                        if(!stk.empty() && stk.top()=='{')
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                   case ']':
                        if(!stk.empty() && stk.top()=='[')
                        {
                            stk.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                }
            }
        }
        return stk.empty();
    }
};