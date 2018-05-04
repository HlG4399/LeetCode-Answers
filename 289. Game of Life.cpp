/*
Problem Description:
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> oldBoard(board);
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        if(n==0) return;
        vector<int> area_x={-1,-1,-1,0,0,1,1,1},area_y={-1,0,1,-1,1,-1,0,1};
        int live=0,dead=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<8;k++)
                {
                    if(i+area_x[k]>=0 && i+area_x[k]<m && j+area_y[k]>=0 && j+area_y[k]<n)
                    {
                        if(oldBoard[i+area_x[k]][j+area_y[k]]==1) live++;
                        else dead++;
                    }
                }
                if((live<2 || live>3) && oldBoard[i][j]==1) board[i][j]=0;
                if(((live==2 || live==3) && oldBoard[i][j]==1) || ((live==3 && oldBoard[i][j]==0))) board[i][j]=1;
                live=0;
                dead=0;
            }
        }
    }
};