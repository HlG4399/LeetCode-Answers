/*
Problem Description:
We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.
 

Note:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.
*/

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n=S.size();
        vector<string> results,S1,S2;
        for(int i=1;i<n-2;i++)
        {
            S1=Split(S.substr(1,i));
            S2=Split(S.substr(i+1,n-2-i));
            for(auto s1:S1)
            {
                for(auto s2:S2)
                {
                    results.emplace_back("("+s1+", "+s2+")");
                }
            }
        }
        return results;
    }
    
    vector<string> Split(string S)
    {
        int n=S.size();
        if(n==0 || (n>1 && S[0]=='0' && S[n-1]=='0')) return {};
        if(n==1 && S[0]=='0' || (n>1 && S[n-1]=='0')) return {S};
        if(n>1 && S[0]=='0') return {"0."+S.substr(1)};
        vector<string> results;
        results.emplace_back(S);
        for(int i=1;i<n;i++)
        {
            results.emplace_back(S.substr(0,i)+"."+S.substr(i));
        }
        return results;
    }
};