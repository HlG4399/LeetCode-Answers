/*
Problem Description:
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        Traverse(root,k,pq);
        return pq.top();
    }
    
    void Traverse(TreeNode* root,int k,priority_queue<int>& pq)
    {
        if(!root)
        {
            return;
        }
        if(pq.size()<k || root->val<pq.top())
        {
            pq.emplace(root->val);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        Traverse(root->left,k,pq);
        Traverse(root->right,k,pq);
    }
};