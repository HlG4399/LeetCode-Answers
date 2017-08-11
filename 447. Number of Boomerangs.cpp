/*
Problem Description:
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result=0;
        unordered_map<double,int> points_distance;
        for(auto p1:points)
        {
            points_distance.clear();
            for(auto p2:points)
            {
                if(p1==p2)
                {
                    continue;
                }
                points_distance[distance(p1,p2)]++;
            }
            for(auto it:points_distance)
            {
                if(it.second>1)
                {
                    result+=it.second*(it.second-1);
                }
            }
        }
        return result;
    }
    
    double distance(pair<int, int> p1,pair<int, int> p2)
    {
        return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
    }
};