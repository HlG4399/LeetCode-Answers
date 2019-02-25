/*
Problem Description:
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int area=n*n;
        vector<int> LA,LB;
        for(int i=0;i<area;++i){
            int row=i/n;
            int col=i%n;
            if(A[row][col]==1) LA.emplace_back(row*100+col);
        }
        for(int i=0;i<area;++i){
            int row=i/n;
            int col=i%n;
            if(B[row][col]==1) LB.emplace_back(row*100+col);
        }
        unordered_map<int,int> hash;
        for(auto la:LA){
            for(auto lb:LB) ++hash[la-lb];
        }
        int result=0;
        for(auto h:hash) result=max(result,h.second);
        return result;
    }
};