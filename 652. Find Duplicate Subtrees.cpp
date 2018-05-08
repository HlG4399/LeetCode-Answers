/*
Problem Description:
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        unordered_map<string,vector<TreeNode*>> hash;
        Serialization(root,hash);
        vector<TreeNode*> results;
        for(auto it=hash.begin();it!=hash.end();it++)
        {
            if(it->second.size()>1) results.emplace_back(it->second[0]);
        }
        return results;
    }
    
    string Serialization(TreeNode* root,unordered_map<string,vector<TreeNode*>>& hash)
    {
        if(!root) return "";
        string s="("+Serialization(root->left,hash)+","+to_string(root->val)+","+Serialization(root->right,hash)+")";
        hash[s].emplace_back(root);
        return s;
    }
};