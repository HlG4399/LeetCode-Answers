/*
Problem Description:
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int d1=diameterOfBinaryTree(root->left);
        int d2=diameterOfBinaryTree(root->right);
        int result=max(d1,d2);
        result=max(result,getDepth(root->left)+getDepth(root->right));
        return result;
    }
    
    int getDepth(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int lDepth=getDepth(root->left);
        int rDepth=getDepth(root->right);
        return max(lDepth,rDepth)+1;
    }
};