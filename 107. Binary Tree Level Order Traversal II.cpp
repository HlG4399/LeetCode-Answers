/*
Problem Description:
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if(!root)
        {
            return results;
        }
        vector<int> temp;
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(q1.size()!=0)
        {        
            if(q1.front()->left)
            {
                q2.push(q1.front()->left);
            }
            if(q1.front()->right)
            {
                q2.push(q1.front()->right);
            }
            temp.emplace_back(q1.front()->val);
            q1.pop();
            if(q1.size()==0)
            {
                results.insert(results.begin(),temp);
                swap(q1,q2);               
                temp.clear();
            }
        }
        return results;
    }
};