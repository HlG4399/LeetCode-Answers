/*
Problem Description:
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[B.length - 1]
 

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n=A.size();
        if(n<3) return false;
        bool flag1=false,flag2=false;
        for(int i=0;i<n-1;i++){
            if(A[i]<A[i+1]){
                if(flag2) return false;
                flag1=true;
            }
            else{
                if(A[i]>A[i+1]) flag2=true;
                else return false;
            }
        }
        return flag1 && flag2;
    }
};