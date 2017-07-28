/*
Problem Description:
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
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
    int getMinimumDifference(TreeNode* root) 
    {
        int min_difference=INT_MAX;
        TreeNode* pre_root=NULL;
        orderTraversal(root, pre_root, min_difference);
        return min_difference;
    }
    void orderTraversal(TreeNode* root, TreeNode*& pre_root, int& min_difference) 
    {
        if(!root)
        {
            return;
        }
        orderTraversal(root->left, pre_root, min_difference); 
        if(pre_root)
        {
            min_difference=min(min_difference,root->val-pre_root->val);
        }
        pre_root=root;
        orderTraversal(root->right, pre_root, min_difference); 
    }
};