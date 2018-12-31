/*
Problem Description:
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m-2;++i)
            for(int j=0;j<n-2;++j)
                if(isMagicSquare(i,j,grid)) ++result;
        return result;
    }
    
    bool isMagicSquare(int i,int j,vector<vector<int>>& grid)
    {
        vector<int> count(9,0);
        for(int a=i;a<=i+2;a++)
        {
            for(int b=j;b<=j+2;b++)
            {
                if(grid[a][b]<=0 || grid[a][b]>9) return false;
                if(count[grid[a][b]-1]>0) return false;
                ++count[grid[a][b]-1];
            }            
        }
        int row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        int row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        int row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
        int col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
        int col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        int col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
        int diag=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        if(row1==row2 && row2==row3 && row3==col1 && col1==col2 && col2==col3 && col3==diag && diag==row1)  return true;
        else return false;
    }
};