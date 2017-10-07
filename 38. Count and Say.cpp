/*
Problem Description:
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        string result="1",temp_str="1";
        for(int i=1;i<n;i++)
        {
            result="";
            char temp_ch=temp_str[0];
            int temp_count=0;
            for(auto ch:temp_str)
            {
                if(ch==temp_ch)
                {
                    temp_count++;
                }
                else
                {
                    result=result+to_string(temp_count)+temp_ch;
                    temp_ch=ch;
                    temp_count=1;
                }
            }
            result=result+to_string(temp_count)+temp_ch;
            temp_str=result;
        }
        return result;
    }
};