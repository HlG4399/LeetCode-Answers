/*
Problem Description:
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> temp;
        int j=0;
        BackTracking(n,k,results,temp,j);
        return results;
    }
    
    void BackTracking(int& n,int& k,vector<vector<int>>& results,vector<int>& temp,int& j)
    {
        if(temp.size()==k)
        {
            results.emplace_back(temp);
            return;
        }
        for(int i=j+1;i<=n;i++)
        {
            temp.emplace_back(i);
            BackTracking(n,k,results,temp,i);
            temp.pop_back();
        }
    }
};