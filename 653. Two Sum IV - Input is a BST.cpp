/*
Problem Description:
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> map;      
        return PreorderTraverse(root,k,map);
    }
    
    bool PreorderTraverse(TreeNode* root,int k,unordered_map<int,int>& map)
    {
        if(!root)
        {
            return false;
        }
        if(map[k-root->val]==1)
        {
            return true;
        }
        map[root->val]++;
        return PreorderTraverse(root->left,k,map) || PreorderTraverse(root->right,k,map);
    }
};