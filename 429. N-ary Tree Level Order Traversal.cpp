/*
Problem Description:
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

We should return its level order traversal:

[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> results;
        vector<int> temp;
        deque<Node*> p,q;
        p.emplace_back(root);
        temp.emplace_back(root->val);
        results.emplace_back(temp);
        while(!p.empty() || !q.empty())
        {
            temp.clear();
            while(!p.empty())
            {
                for(auto c:(p.front()->children))
                {
                    q.emplace_back(c);
                    temp.emplace_back(c->val);
                }
                p.pop_front();
            }
            if(temp.size()) results.emplace_back(temp);
            swap(p,q);
        }
        return results;
    }
};