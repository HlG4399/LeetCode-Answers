/*
Problem Description:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> results(n,vector<int>(n,0));
        int i=0,j=0,k=0,l=1;
        for(;i<n/2;i++)
        {
            for(j=i;j<n-i;j++) results[i][j]=l++;
            for(k=i+1,j--;k<n-i;k++) results[k][j]=l++;
            for(j=--k,j--;j>=i;j--) results[k][j]=l++;
            for(k--;k>i;k--) results[k][i]=l++;
        }
        if(n%2!=0) results[i][i]=l;
        return results;
    }
};