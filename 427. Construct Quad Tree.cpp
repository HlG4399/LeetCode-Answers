/*
Problem Description:
We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

Note:

N is less than 1000 and guaranteened to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int N=grid.size();
        if(N==0) return nullptr;
        return DFS(grid,0,0,N);
    }
    
    Node* DFS(vector<vector<int>>& grid,int x,int y,int N)
    {
        if(N==1) return new Node(grid[x][y]==1?true:false,true,nullptr,nullptr,nullptr,nullptr);
        N/=2;
        Node* topLeft=DFS(grid,x,y,N);
        Node* topRight=DFS(grid,x,y+N,N);
        Node* bottomLeft=DFS(grid,x+N,y,N);
        Node* bottomRight=DFS(grid,x+N,y+N,N);
        
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val==topRight->val && topRight->val==bottomLeft->val && bottomLeft->val==bottomRight->val)
        {
            bool val=topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(val,true,nullptr,nullptr,nullptr,nullptr);
        }
        else
            return new Node(true,false,topLeft,topRight,bottomLeft,bottomRight);
    }
};