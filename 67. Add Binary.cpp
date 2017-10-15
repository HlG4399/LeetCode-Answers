/*
Problem Description:
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,i,j;
        string result="";
        for(i=a.size()-1,j=b.size()-1;i>=0 && j>=0;i--,j--)
        {
            result=to_string((a[i]-'0'+b[j]-'0'+carry)%2)+result;
            carry=(a[i]-'0'+b[j]-'0'+carry>1?1:0);
        }
        while(i>=0)
        {
            result=to_string((a[i]-'0'+carry)%2)+result;
            carry=(a[i]-'0'+carry>1?1:0);
            i--;
        }
        while(j>=0)
        {
            result=to_string((b[j]-'0'+carry)%2)+result;
            carry=(b[j]-'0'+carry>1?1:0);
            j--;
        }
        return carry>0?to_string(carry%2)+result:result;
    }
};