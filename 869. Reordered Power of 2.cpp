/*
Problem Description:
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9
*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> digits;
        while(N) digits.emplace_back(N%10),N/=10;
        sort(digits.begin(),digits.end());
        do{
            if(digits[0]==0) continue;
            int temp=0;
            for(auto d:digits) temp=temp*10+d;
            if((temp&temp-1)==0) return true; 
        }while(next_permutation(digits.begin(),digits.end()));
        return false;
    }
};
