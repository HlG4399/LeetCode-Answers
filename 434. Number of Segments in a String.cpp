/*
Problem Description:
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

class Solution {
public:
    int countSegments(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
        if(s.empty())
        {
            return 0;
        }
        int result=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==' ' && s[i-1]!=' ')
            {
                result++;
            }
        }
        return result;
    }
};