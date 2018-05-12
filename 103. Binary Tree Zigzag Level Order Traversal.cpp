/*
Problem Description:
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> results;
        vector<int> temp;
        queue<TreeNode*> q1,q2;
        q1.push(root);
        bool isLeft=false;
        TreeNode* tempRoot=NULL;
        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                tempRoot=q1.front();
                if(tempRoot->left) q2.push(tempRoot->left);
                if(tempRoot->right) q2.push(tempRoot->right);
                temp.emplace_back(tempRoot->val);
                q1.pop();
            }
            if(isLeft) reverse(temp.begin(),temp.end());
            results.emplace_back(temp);
            temp.clear();
            isLeft=!isLeft;
            swap(q1,q2);
        }
        return results;
    }
};