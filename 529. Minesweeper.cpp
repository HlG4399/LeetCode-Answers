/*
Problem Description:
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

Note:
The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<click.size();i+=2)
        {
            DFS(click[i],click[i+1],board,visited);
        }
        return board;
    }
    
    void DFS(int x,int y,vector<vector<char>>& board,vector<vector<bool>>& visited)
    {
        if(board[x][y]=='M')
        {
            board[x][y]='X';
            return;
        }
        if(board[x][y]!='E')
        {
            return;
        }
        visited[x][y]=true;
        int offset_x[8]={-1,-1,-1,0,0,1,1,1};
        int offset_y[8]={-1,0,1,-1,1,-1,0,1};
        int landMines=0,temp_x=0,temp_y=0;
        for(int i=0;i<8;i++)
        {
            temp_x=x+offset_x[i];
            temp_y=y+offset_y[i];
            if(temp_x>=0 && temp_x<board.size() && temp_y>=0 && temp_y<board[0].size() && !visited[temp_x][temp_y] && board[temp_x][temp_y]=='M')
            {
                landMines++;    
            }
        }
        if(landMines>0)
        {
            board[x][y]=landMines+'0';
        }
        else
        {
            board[x][y]='B';
            for(int i=0;i<8;i++)
            {
                temp_x=x+offset_x[i];
                temp_y=y+offset_y[i];
                if(temp_x>=0 && temp_x<board.size() && temp_y>=0 && temp_y<board[0].size() && !visited[temp_x][temp_y])
                {
                    DFS(temp_x,temp_y,board,visited);    
                }
            }
        }
    }
};