/*
Problem Description:
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        for(auto num:nums)
        {
            pq.push(num);
        }
        for(int i=1;i<k;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};