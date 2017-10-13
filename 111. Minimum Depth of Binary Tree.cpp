/*
Problem Description:
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return 1;
        }
        return min((root->left?minDepth(root->left):INT_MAX),(root->right?minDepth(root->right):INT_MAX))+1;
    }
};