/*
Problem Description:
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> map;
        DFS(root,map);
        int temp=INT_MIN;
        vector<int> results;
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(it->second>temp)
            {
                temp=it->second;
                results.clear();
                results.emplace_back(it->first);
            }
            if(it->second==temp && find(results.begin(),results.end(),it->first)==results.end())
            {
                results.emplace_back(it->first);
            }
        }
        return results;
    }
    
    int DFS(TreeNode* root,unordered_map<int,int>& map)
    {
        if(!root)
        {
            return 0;
        }
        int sum1=DFS(root->left,map);
        int sum2=DFS(root->right,map);
        map[root->val+sum1+sum2]++;
        return root->val+sum1+sum2;
    }
};