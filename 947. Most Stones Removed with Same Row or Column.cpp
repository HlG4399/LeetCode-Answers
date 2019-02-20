/*
Problem Description:
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/

class Solution {
private:
    vector<int> parents;
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parents.resize(n,-1);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j)
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) merge_mfset(i,j);
        }
        set<int> s;
        for(int i=0;i<n;++i) s.insert(find_mfset(i));
        return n-s.size();
    }
    

    int find_mfset(int i,int j=0){
        if(i<0 || i>parents.size()) return -1;
        for(j=i;parents[j]>=0;j=parents[j]);
        return j;
    }
    
    void merge_mfset(int i,int j){
        if (i<0 || i>parents.size() || j<0 || j>parents.size()) return;
        int pi = find_mfset(i);
        int pj = find_mfset(j);
        if(pi==pj) return;
        if (pi > pj) {
            parents[pj] += parents[pi];
            parents[pi] = pj;
        } 
        else {
            parents[pi] += parents[pj];
            parents[pj] = pi;
        }
    }
};