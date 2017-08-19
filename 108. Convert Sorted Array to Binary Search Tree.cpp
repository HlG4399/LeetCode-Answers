/*
Problem Description:
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(0,nums.size()-1,nums);
    }
    
    TreeNode* sortedArrayToBST(int a,int b,vector<int>& nums) 
    {
        if(a>b)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(nums[(a+b)/2]);
        root->left=sortedArrayToBST(a,(a+b)/2-1,nums);
        root->right=sortedArrayToBST((a+b)/2+1,b,nums);
        return root;
    }
};