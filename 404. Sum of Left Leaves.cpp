/*
Problem Description:
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool isLeftLeaves=false;
        if(root)
        {
            traverseLeftSubtree(root,sum,isLeftLeaves);           
        }
        return sum;
    }
    
    void traverseLeftSubtree(TreeNode* root,int& sum,bool& isLeftLeaves)
    {
        if(!root->left && !root->right)
        {
            if(isLeftLeaves)
            {
                sum+=root->val; 
            }
        }
        if(root->left)
        {
            isLeftLeaves=true;
            traverseLeftSubtree(root->left,sum,isLeftLeaves);
        }
        if(root->right)
        {
            isLeftLeaves=false;
            traverseLeftSubtree(root->right,sum,isLeftLeaves);
        }
    }
};