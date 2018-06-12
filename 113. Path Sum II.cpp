/*
Problem Description:
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<vector<int>> results;
        vector<int> temp;
        temp.emplace_back(root->val);
        BackTracking(root,sum,results,temp,root->val);
        return results;
    }
    
    void BackTracking(TreeNode* root, int& sum,vector<vector<int>>& results,vector<int>& temp,int tempSum)
    {
        if(!root->left && !root->right)
        {
            if(tempSum==sum) results.emplace_back(temp);
            return;
        }
        if(root->left)
        {
            tempSum+=root->left->val;
            temp.emplace_back(root->left->val);
            BackTracking(root->left,sum,results,temp,tempSum);
            tempSum-=root->left->val;
            temp.pop_back();
        }
        if(root->right)
        {
            tempSum+=root->right->val;
            temp.emplace_back(root->right->val);
            BackTracking(root->right,sum,results,temp,tempSum);
            tempSum-=root->right->val;
            temp.pop_back();
        }
    }
};