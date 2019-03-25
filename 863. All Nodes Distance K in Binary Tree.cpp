/*
Problem Description:
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
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
private:
    vector<TreeNode*> parents;
    vector<bool> visited;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        parents.resize(501,nullptr);
        visited.resize(501,false);
        getParents(root);
        vector<int> results;
        visited[target->val]=true;
        findTarget(target,results,0,K);
        return results;
    }
    
    void getParents(TreeNode* root){
        if(!root) return;
        if(root->left){
            parents[root->left->val]=root;
            getParents(root->left);
        }
        if(root->right){
            parents[root->right->val]=root;
            getParents(root->right);            
        }
    }
    
    void findTarget(TreeNode* root,vector<int>& results,int d,int K){
        if(d==K){
            results.push_back(root->val);
            return;
        }
        if(root->left && !visited[root->left->val]){
            visited[root->left->val]=true;
            findTarget(root->left,results,d+1,K);
        }
        if(root->right && !visited[root->right->val]){
            visited[root->right->val]=true;
            findTarget(root->right,results,d+1,K);
        }
        auto parent=parents[root->val];
        if(parent && !visited[parent->val]){
            visited[parent->val]=true;
            findTarget(parent,results,d+1,K);
        }
    }
};