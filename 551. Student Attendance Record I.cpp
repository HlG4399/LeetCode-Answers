/*
Problem Description:
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int A_nums=0,L_nums=0;
        for(int i=0;i!=s.size();i++)
        {
            if(s[i]=='A')
            {
                A_nums++;
            }
            if(s[i]=='L' && s[i-1]=='L')
            {
                if(++L_nums>1)
                {
                    return false;
                }
            }
            else
            {
                L_nums=((--L_nums<0)?0:L_nums);
            }
        }
        return (A_nums>1 || L_nums>1)?false:true;
    }
};