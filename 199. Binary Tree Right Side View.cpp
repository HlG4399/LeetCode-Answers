/*
Problem Description:
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q1,q2;
        vector<int> results;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            results.emplace_back(q1.back()->val);
            while(!q1.empty())
            {
                if(q1.front()->left) q2.push(q1.front()->left);
                if(q1.front()->right) q2.push(q1.front()->right);
                q1.pop();
            }
            swap(q1,q2);
        }
        return results;
    }
};