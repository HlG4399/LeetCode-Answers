/*
Problem Description:
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> results;
        if(root!=NULL)
        {
            deque<TreeNode*> q_first, q_second; 
            q_first.push_back(root);  
            while(!q_first.empty()) 
            {  
                double sum=0,num=0;
                while (!q_first.empty()) 
                {  
                    TreeNode *temp = q_first.front();  
                    q_first.pop_front();
                    sum+=temp->val;
                    num++;
                    if (temp->left) 
                    {
                        q_second.push_back(temp->left);                          
                    }
                    if (temp->right)  
                    {
                        q_second.push_back(temp->right);                          
                    }
                }   
                q_first.swap(q_second);
                results.push_back(sum/num);
            }  
        }
        return results;
    }
};