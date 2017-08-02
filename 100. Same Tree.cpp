/*
Problem Description:
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result=true;
        if(p || q)
        {
            checkEqual(p,q,result);
        }
        return result;
    }
    
    void checkEqual(TreeNode* p, TreeNode* q,bool& result)
    {
        if(p && q)
        {
            if(p->val!=q->val)
            {
                result=false;
            }
            checkEqual(p->left,q->left,result);
            checkEqual(p->right,q->right,result);
        }
        if((p&&!q) || (!p&&q))
        {
            result=false;
        }
    }
};