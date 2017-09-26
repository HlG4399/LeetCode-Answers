/*
Problem Description:
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        vector<int> result,temp;
        unordered_map<int,int> rootMap;
        if(!root)
        {
            return result;
        }
        OrderTraversal(root,rootMap);
        int max_count=1;
        for(auto it=rootMap.begin();it!=rootMap.end();it++)
        {
            if(it->second==max_count)
            {
                result.emplace_back(it->first);
            }
            else if(it->second>max_count)
            {
                max_count=it->second;
                result.clear();
                result.emplace_back(it->first);
            }
        }
        return result;
    }
    
    void OrderTraversal(TreeNode* root,unordered_map<int,int>& rootMap)
    {
        if(!root)
        {
            return;
        }
        OrderTraversal(root->left,rootMap);
        rootMap[root->val]++;
        OrderTraversal(root->right,rootMap);
    }
};