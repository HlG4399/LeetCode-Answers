/*
Problem Description:
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int result=INT_MAX;
        unordered_map<int,set<int>> hash;
        for(auto p:points) hash[p[0]].insert(p[1]);
        for(auto h1=hash.begin();h1!=hash.end();++h1){
            for(auto h2=next(h1);h2!=hash.end();++h2){
                if(h1->second.size()<2 || h2->second.size()<2) continue;
                vector<int> y;
                set_intersection(h1->second.begin(),h1->second.end(),h2->second.begin(),h2->second.end(),back_inserter(y));
                int n=y.size();
                int x=abs(h1->first-h2->first);
                for(int i=1;i<n;++i) result=min(result,x*abs(y[i]-y[i-1]));
            }
        }
        return result==INT_MAX?0:result;
    }
};