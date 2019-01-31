/*
Problem Description:
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

Note:

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        for(int i=0;i<m;++i)
            if(A[i][0]==0) rowFlipping(A,n,i);
        for(int j=0;j<n;++j){
            vector<int> count(2,0);
            for(int i=0;i<m;++i) count[A[i][j]]++;
            if(count[0]>count[1]) colFlipping(A,m,j);
        }
        int result=0;
        for(int j=0;j<n;++j){
            for(int i=0;i<m;++i) 
                if(A[i][j]==1) result+=pow(2,n-1-j);
        }       
        return result;
    }
    
    void rowFlipping(vector<vector<int>>& A,int n,int i){
        for(int j=0;j<n;++j) A[i][j]=(A[i][j]+1)%2;
    }
    
    void colFlipping(vector<vector<int>>& A,int m,int j){
        for(int i=0;i<m;++i) A[i][j]=(A[i][j]+1)%2;
    }
};