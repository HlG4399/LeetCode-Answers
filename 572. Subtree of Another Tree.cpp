/*
Problem Description:
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
        {
            return true;
        }
        if((!s && t) || (s && !t))
        {
            return false;
        }
        vector<bool> results;
        findRoot(s,t,results);
        for(int i=0;i!=results.size();i++)
        {
            if(results[i])
            {
                return true;
            }
        }
        return false;
    }
    
    void findRoot(TreeNode* s, TreeNode*  t,vector<bool>& results)
    {
        bool isStopFinding=false;
        if(s && t && s->val==t->val)
        {
            isStopFinding=checkStructure(s, t);
            results.emplace_back(isStopFinding);
        }
        if(s->left && !isStopFinding)
        {
            findRoot(s->left, t,results);
        }
        if(s->right && !isStopFinding)
        {
            findRoot(s->right, t,results);
        }
    }
    
    bool checkStructure(TreeNode* s, TreeNode* t)
    {
        if(!s && !t)
        {
            return true;
        }
        if((!s && t) || (s && !t))
        {
            return false;
        }
        return (s->val==t->val)&&checkStructure(s->left, t->left)&&checkStructure(s->right, t->right);
    }
};