/*
Problem Description:
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        PlusSum(root,sum);
        return root;
    }
    
    void PlusSum(TreeNode* root,int& sum) {
        if(root==NULL)
        {
            return;
        }
        PlusSum(root->right,sum);
        sum+=root->val;
        root->val=sum;
        PlusSum(root->left,sum);
    }
};