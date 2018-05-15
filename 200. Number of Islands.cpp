/*
Problem Description:
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        unordered_map<int,unordered_map<int,int>> hash;
        int num=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='0' || hash[i][j]!=0) continue;
                DFS(grid,m,n,i,j,hash,num);
                num++;
            }
        }
        return num-1;
    }
    
    void DFS(vector<vector<char>>& grid,int& m,int& n,int i,int j,unordered_map<int,unordered_map<int,int>>& hash,int& num)
    {
        hash[i][j]=num;
        vector<int> Dx={-1,0,0,1},Dy={0,-1,1,0};
        for(int d=0;d<4;d++)
        {
            if(i+Dx[d]>=0 && i+Dx[d]<m && j+Dy[d]>=0 && j+Dy[d]<n && grid[i+Dx[d]][j+Dy[d]]=='1' && hash[i+Dx[d]][j+Dy[d]]==0)
            {
                DFS(grid,m,n,i+Dx[d],j+Dy[d],hash,num); 
            }
        }
    }
};