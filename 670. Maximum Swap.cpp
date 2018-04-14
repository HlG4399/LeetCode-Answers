/*
Problem Description:
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/

class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int maxNum=INT_MIN,maxIndex=-1,a=-1,b=-1,n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]<maxNum)
            {
                a=i;
                b=maxIndex;
            }
            if(s[i]>maxNum)
            {
                maxNum=s[i];
                maxIndex=i;
            }
        }
        if(a==-1) return num;
        swap(s[a],s[b]);
        return stoi(s);
    }
};