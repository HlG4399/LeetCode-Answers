/*
Problem Description:
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1.size()!=2 || p2.size()!=2 || p3.size()!=2 || p4.size()!=2) return false;
        vector<vector<int>> p={p1,p2,p3,p4};
        vector<int> len;
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                len.emplace_back((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
            }
        }
        sort(len.begin(),len.end());
        if(len[0]==len[1] && len[1]==len[2] && len[2]==len[3] && len[4]==len[5] && len[4]>len[0]) return true;
        return false;
    }
};