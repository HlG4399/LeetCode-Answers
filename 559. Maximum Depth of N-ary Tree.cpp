/*
Problem Description:
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

We should return its max depth, which is 3.

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
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
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> p,q;
        p.push(root);
        int depth=1;
        while(!p.empty() || !q.empty())
        {
            while(!p.empty())
            {
                for(auto c:(p.front()->children)) q.push(c);
                p.pop();
            }
            swap(p,q);
            if(!p.empty()) depth++;
        }
        return depth;
    }
};