/*
Problem Description£º
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:
    string convertToBase7(int num) {
        string result;
        if(num<0)
        {
            result+="-";
            num=abs(num);
        }
        vector<int> base7_string;
        do
        {
            base7_string.emplace_back(num%7);
            num/=7;
        }while(num!=0);
        for(int i=base7_string.size()-1;i>=0;i--)
        {
            result+=to_string(base7_string[i]);
        }
        return result;
    }
};