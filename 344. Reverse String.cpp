/*
Problem Description:
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        std::reverse(&s[0],&s[s.size()]);
        return s;
    }
};