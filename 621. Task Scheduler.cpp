/*
Problem Description:
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size()==0) return n==0?0:25-n;
        unordered_map<char,int> map;
        int maxCount=0,sameCount=0;
        for(auto task:tasks)
        {
            maxCount=max(maxCount,++map[task]);
        }
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(it->second==maxCount) sameCount++;
        }
        return max((int)tasks.size(),(maxCount-1)*(n+1)+sameCount);
    }
};