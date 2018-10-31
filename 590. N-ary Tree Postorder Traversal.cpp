/*
Problem Description:
Given an n-ary tree, return the postorder traversal of its nodes' values.

Return its postorder traversal as: [5,6,3,2,4,1].

 
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
    vector<int> postorder(Node* root) {
        if(!root) return{};
        stack<Node*> s;
        s.push(root);
        list<int> lst;
        Node* temp;
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            lst.push_front(temp->val);
            if((temp->children).empty()) continue;
            for(auto c:(temp->children)) s.push(c);
        }
        return vector<int>(lst.begin(),lst.end());
    }
};