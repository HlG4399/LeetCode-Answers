/*
Problem Description:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> results;
        vector<int> temp;
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                if(q1.front()->left) q2.push(q1.front()->left);
                if(q1.front()->right) q2.push(q1.front()->right);
                temp.emplace_back(q1.front()->val);
                q1.pop();
            }
            results.emplace_back(temp);
            temp.clear();
            swap(q1,q2);     
        }
        return results;
    }
};