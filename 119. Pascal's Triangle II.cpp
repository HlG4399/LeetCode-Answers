/*
Problem Description:
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> results(rowIndex+1);
        results[0]=1;
        for(int i=0;i!=rowIndex+1;i++)
        {
            for(int j=i;j>=1;j--)
            {
                results[j]+=results[j-1];
            }
        }
        return results;
    }
};