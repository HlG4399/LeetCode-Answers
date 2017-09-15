/*
Problem Description:
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        returnPaths(root,results,"");
        return results;
    }
    
    void returnPaths(TreeNode* root,vector<string>& results,string temp_str)
    {
        if(!root)
        {
            return;
        }
        temp_str=(temp_str==""?to_string(root->val):temp_str+"->"+to_string(root->val));
        if(root->left)
        {
            returnPaths(root->left,results,temp_str);
        }
        if(root->right)
        {
            returnPaths(root->right,results,temp_str);
        }
        if(!root->left && !root->right)
        {
            results.push_back(temp_str);
        }
    }
};
