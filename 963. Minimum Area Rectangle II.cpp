/*
Problem Description:
Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:
Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.

Example 2:
Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.

Example 3:
Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.

Example 4:
Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 

Note:

1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
Answers within 10^-5 of the actual value will be accepted as correct.
*/

class Solution {
public:
size_t d2(int x1, int y1, int x2, int y2) { 
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
  unordered_map<size_t, vector<vector<int>>> m;
  for (auto i = 0; i < ps.size(); ++i)
    for (auto j = i + 1; j < ps.size(); ++j) {
      auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
      m[center].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
    }
  for (auto it = begin(m); it != end(m); ++it)
    for (auto i = 0; i < it->second.size(); ++i)
      for (auto j = i + 1; j < it->second.size(); ++j) {
        auto &p1 = it->second[i], &p2 = it->second[j];
        if ((p1[0] - p2[0]) * (p1[0] - p2[2]) + (p1[1] - p2[1]) * (p1[1] - p2[3]) == 0) {
          auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
          if (res == 0 || res > area) res = area;
        }
      }
  return sqrt(res);
}
};