/*
Problem Description:
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre,post,0,0,pre.size()-1);
    }
    
    TreeNode* helper(vector<int>& pre,vector<int>& post,int root,int L,int R){
        int n=pre.size();
        if(root>=n || L>R) return NULL;
        if(root<n && L==R) return new TreeNode(pre[root]);
        TreeNode* node=new TreeNode(pre[root]);
        int mid=L;
        if(root+1<n) for(;mid<=R && pre[root+1]!=post[mid];++mid);
        node->left=helper(pre,post,root+1,L,mid);
        node->right=helper(pre,post,root+1+(mid-L+1),mid+1,R-1);
        return node;
    }
};