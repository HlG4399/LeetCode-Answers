/*
Problem Description:
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (¡°abcdabcdabcd¡±), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int result=1;
        string str=A;
        if(str.length()>=B.length())
        {
            if(str.find(B)!=-1)
            {
                return result;
            }
        }
        while(str.length()<B.length())
        {
            str+=A;
            result++;
            if(str.find(B)!=-1)
            {
                return result;
            }
        }
        for(int i=0;i<2;i++)
        {
            str+=A;
            result++;
            if(str.find(B)!=-1)
            {
                return result;
            }
        }
        return -1;
    }
};