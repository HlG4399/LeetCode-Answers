/*
Problem Description:
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return RecursiveConstruct(nums,0,nums.size()-1);
    }
    
    TreeNode* RecursiveConstruct(vector<int>& nums,int a,int b)
    {
        if(a>b)
        {
            return NULL;
        }
        int max_index=a;
        for(int i=a+1;i<=b;i++)
        {
            max_index=(nums[i]>nums[max_index]?i:max_index);
        }
        TreeNode* root=new TreeNode(nums[max_index]);
        root->left=RecursiveConstruct(nums,a,max_index-1);
        root->right=RecursiveConstruct(nums,max_index+1,b);
        return root;
    }
};
