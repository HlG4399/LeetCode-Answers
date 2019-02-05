/*
Problem Description:
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
*/

class Solution {
private:
    vector<int> parent;
public:
    int regionsBySlashes(vector<string>& grid) {
        int N=grid.size();
        int area=4*N*N;
        parent.resize(area,-1);
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int k=4*(i*N+j);
                switch(grid[i][j]){
                    case ' ':
                        merge_mfset(k,k+1);
                        merge_mfset(k+1,k+2);
                        merge_mfset(k+2,k+3);
                        break;
                    case '/':
                        merge_mfset(k,k+3);
                        merge_mfset(k+1,k+2);
                        break;
                    case '\\':
                        merge_mfset(k,k+1);
                        merge_mfset(k+2,k+3);
                        break;
                }
                if(i<N-1) merge_mfset(k+2,k+4*N);
                if(j<N-1) merge_mfset(k+1,k+4+3);
            }
        }
        set<int> regions;
        for(int i=0;i<area;++i) regions.insert(find_mfset(i));
        return regions.size(); 
    }
    
    int find_mfset(int i,int j=0){
        if(i<0 || i>parent.size()) return -1;
        for(j=i;parent[j]>=0;j=parent[j]);
        return j;
    }
    
    void merge_mfset(int i,int j){
	    if (i<0 || i>parent.size() || j<0 || j>parent.size()) return;
	    int pi = find_mfset(i);
	    int pj = find_mfset(j);
        if(pi==pj) return;
	    if (pi > pj) {
		    parent[pj] += parent[pi];
		    parent[pi] = pj;
	    } 
	    else {
		    parent[pi] += parent[pj];
		    parent[pj] = pi;
	    }
    }
};