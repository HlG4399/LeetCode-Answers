/*
Problem Description:
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> results;
        if(!root)
        {
            return results;
        }
        deque<TreeNode> q1,q2;
        int max_value=INT_MIN;
        q1.push_back(*root);
        while(!q1.empty())
        {
            for(auto it=q1.begin();it!=q1.end();it++)
            {
                max_value=max(it->val,max_value);
                if(it->left)
                {
                    q2.push_back(*(it->left));
                }
                if(it->right)
                {
                    q2.push_back(*(it->right));
                }                
            }
            results.emplace_back(max_value);
            swap(q1,q2);
            q2.clear();
            max_value=INT_MIN;
        }
        return results;
    }
};