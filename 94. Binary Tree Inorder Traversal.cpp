/*
Problem Description:
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                results.emplace_back(s.top()->val);
                root=s.top()->right;  
                s.pop();                         
            }
        }
        return results;
    }
};