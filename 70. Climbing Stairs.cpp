/*
Problem Description:
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

class Solution {
public:
    int climbStairs(int n) {
        return (pow((1+sqrt(5))/2.0,n+1)-pow((1-sqrt(5))/2.0,n+1))/sqrt(5);
    }
};