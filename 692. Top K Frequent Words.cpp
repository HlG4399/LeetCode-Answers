/*
Problem Description:
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

class Solution {
private:
    struct s_count
    {
        int count;
        string s;
    };
    struct cmp
    {
        bool operator()(s_count a,s_count b)
        {
            if(a.count!=b.count) return a.count<b.count;
            return a.s>b.s;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(auto word:words)
        {
            map[word]++;
        }
        priority_queue<s_count,vector<s_count>,cmp> pq;
        s_count temp;
        for(auto it=map.begin();it!=map.end();it++)
        {
            temp.count=it->second;
            temp.s=it->first;
            pq.push(temp);          
        }
        vector<string> results;
        for(int i=0;i<k;i++)
        {
            results.emplace_back(pq.top().s);
            pq.pop();
        }
        return results;
    }
};