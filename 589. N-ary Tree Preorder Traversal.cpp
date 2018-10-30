/*
Problem Description:
Given an n-ary tree, return the preorder traversal of its nodes' values. 

Return its preorder traversal as: [1,3,5,6,2,4].

Note:

Recursive solution is trivial, could you do it iteratively?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> results;
        Recursive(root,results);
        return results;
    }
    
    void Recursive(Node* root,vector<int>& results)
    {
        if(!root) return;
        results.emplace_back(root->val);
        for(auto c:(root->children))
        {
            Recursive(c,results);
        }
    }
};