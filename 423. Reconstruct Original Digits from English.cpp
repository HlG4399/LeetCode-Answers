/*
Problem Description:
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> map;
        vector<int> digits(10,0);
        for(auto ch:s)
        {
            map[ch]++;
        }
        digits[0]=map['z'];
        digits[2]=map['w'];
        digits[4]=map['u'];
        digits[6]=map['x'];
        digits[8]=map['g'];
        digits[1]=map['o']-map['z']-map['w']-map['u'];
        digits[3]=map['h']-map['g'];
        digits[5]=map['f']-map['u'];
        digits[7]=map['s']-map['x'];
        digits[9]=map['i']-map['x']-map['g']-digits[5];
        string result="";
        for(int i=0;i!=10;i++)
        {
            if(digits[i]>0)
            {
                result.append(digits[i],i+'0');
            }
        }
        return result;
    }
};