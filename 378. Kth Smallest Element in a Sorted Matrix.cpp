/*
Problem Description:
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü n2.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return 0;
        }
        priority_queue<int> pq;
        for(auto row:matrix)
        {
            for(auto e:row)
            {
                if(pq.size()<k || e<pq.top())
                {
                    pq.emplace(e);
                    if(pq.size()>k)
                    {
                        pq.pop();
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return pq.top();
    }
};