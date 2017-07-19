/*
Problem Description:
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        for (int a = 0, b = 0; b != s.size()+1; b++)
	    {
		    if (s[b] == ' ' || b==s.size())
		    {
			    std::reverse(&s[a], &s[b]);
			    a = b + 1;
		    }
	    }
        return s;     
    }
};