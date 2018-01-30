/*
Problem Description:
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return {};
        }
        vector<int> results,temp_nums;
        bool isEven=true;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=i,k=0;j>=0 && k<n;j--,k++)
            {
                temp_nums.emplace_back(matrix[j][k]);
            }
            if(isEven)
            {
                results.insert(results.end(),temp_nums.begin(),temp_nums.end());
            }
            else
            {
                results.insert(results.end(),temp_nums.rbegin(),temp_nums.rend());
            }
            isEven=!isEven;
            temp_nums.clear();
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i,k=m-1;j<n && k>=0;j++,k--)
            {
                temp_nums.emplace_back(matrix[k][j]);
            }
            if(isEven)
            {
                results.insert(results.end(),temp_nums.begin(),temp_nums.end());
            }
            else
            {
                results.insert(results.end(),temp_nums.rbegin(),temp_nums.rend());
            }
            isEven=!isEven;
            temp_nums.clear();            
        }
        return results;
    }
};