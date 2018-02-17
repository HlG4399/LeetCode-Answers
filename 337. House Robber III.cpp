/*
Problem Description:
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        vector<int> results=CaculateMoney(root);
        return max(results[0],results[1]);
    }
    
    vector<int> CaculateMoney(TreeNode* root)
    {
        if(!root) return {0,0};
        vector<int> leftMoney=CaculateMoney(root->left);
        vector<int> rightMoney=CaculateMoney(root->right);
        vector<int> money(2,0);
        money[0]=root->val+leftMoney[1]+rightMoney[1];
        money[1]=max(leftMoney[0],leftMoney[1])+max(rightMoney[0],rightMoney[1]);
        return money;
    }
};