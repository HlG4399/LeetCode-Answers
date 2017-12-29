/*
Problem Description:
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto num:nums)
        {
            map[num]++;
        }
        for(auto m:map)
        {
            heap.push(make_pair(m.second,m.first));
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        vector<int> results;
        while(!heap.empty())
        {
            results.emplace_back(heap.top().second);
            heap.pop();
        }
        return results;
    }
};