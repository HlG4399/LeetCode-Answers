/*
Pronblem Description:
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

 

Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"
 

Note:

The number of nodes in the given tree will be between 1 and 1000.
Each node in the tree will have a value between 0 and 25.
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
    string smallestFromLeaf(TreeNode* root) {
        string result="~";
        string temp="";
        temp=(char)('a'+root->val)+temp;
        DFS(root,result,temp);
        return result;
    }
    
    void DFS(TreeNode* root,string& result,string& temp){
        if(!root->left && !root->right){
            result=min(result,temp);
            return;
        }
        if(root->left){
            string temp1=(char)('a'+root->left->val)+temp;
            DFS(root->left,result,temp1);
        }
        if(root->right){
            string temp2=(char)('a'+root->right->val)+temp;
            DFS(root->right,result,temp2);
        }
    }
};