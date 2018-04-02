/*
Problem Description:
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K==0) return 1;
        vector<int> moves={2, 1, -2, -1, -2, 1, 2, -1, 2};
        unordered_map<int,unordered_map<int,unordered_map<int,double>>> hash;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                hash[0][i][j]=1.0;
            }
        }
        for(int i=1;i<=K;i++)
        {
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(j+moves[l]>=0 && j+moves[l]<N && k+moves[l+1]>=0 && k+moves[l+1]<N)
                        {
                            hash[i][j][k]+=hash[i-1][j+moves[l]][k+moves[l+1]];
                        }
                    }
                    hash[i][j][k]/=8.0;
                }
            }
        }
        return hash[K][r][c];
    }
};