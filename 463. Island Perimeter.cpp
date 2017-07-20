/*
Problem Description:
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result=0;
        vector<vector<int>> land_index(grid.size());
        for(int i=0;i!=grid.size();i++)
        {
            for(int j=0;j!=grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    land_index[i].push_back(j);
                    result+=4;
                    if(i>0)
                    {
                        if(std::find(land_index[i-1].begin(),land_index[i-1].end(),j)!=land_index[i-1].end())
                        {
                            result-=2;
                        }
                    }
                    if(j>0)
                    {
                        if(grid[i][j-1]==1)
                        {
                            result-=2;
                        }
                    }
                }
            }
        }
        return result;
    }
};