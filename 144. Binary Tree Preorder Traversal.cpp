/*
Problem Description:
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                results.emplace_back(root->val);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                root=root->right;
            }
        }
        return results;
    }
};