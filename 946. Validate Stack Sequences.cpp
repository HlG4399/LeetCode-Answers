/*
Problem Description:
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n=pushed.size();
        for(int i=0,j=0;i<n || j<n;++i){
            if(i<n) s.push(pushed[i]);
            if(i>=n && popped[j]!=s.top()) break;
            while(j<n && !s.empty() &&popped[j]==s.top()) s.pop(),++j;
        }
        return s.empty();
    }
};