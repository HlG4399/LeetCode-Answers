/*
Problem Description:
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),i=0,j=n-1,result=0;
        while(i<j)
        {
            result=max(result,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return result;
    }
};