/*
Problem Description:
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int lDepth=GetDepth(root->left);
        int rDepth=GetDepth(root->right);
        if(std::abs(lDepth-rDepth)<=1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else
        {
            return false;
        }
    }
    
    int GetDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lDepth=GetDepth(root->left);
        int rDepth=GetDepth(root->right);
        return max(lDepth,rDepth)+1;
    }
};