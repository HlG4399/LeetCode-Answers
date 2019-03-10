/*
Problem Description:
Share
A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Note:

1 <= S.length <= 20000
S only consists of '0' and '1' characters.
*/

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n=S.size();
        vector<int> v_1to0(n+1,0),v_0to1(n+1,0);
        for(int i=1,j=n-1;i<n+1 && j>=0;++i,--j){
            v_1to0[i]=v_1to0[i-1]+(S[i-1]=='1'?1:0);
            v_0to1[j]=v_0to1[j+1]+(S[j]=='0'?1:0);
        }
        int result=INT_MAX;
        for(int i=0;i<n+1;++i) result=min(v_1to0[i]+v_0to1[i],result);
        return result;
    }
};