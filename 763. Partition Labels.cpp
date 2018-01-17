/*
Problem Description:
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

class Solution {
private:
    struct compare
    {
        bool operator() (const vector<int>& v1,const vector<int>& v2)
        {
            return v1[0]>v2[0];
        }
    };
public:
    vector<int> partitionLabels(string S) {
        int len=S.size();
        unordered_map<char,vector<int>> map;
        for(int i=0;i!=len;i++)
        {
            if(map[S[i]].empty())
            {
                map[S[i]]={i,i};
            }
            else
            {
                map[S[i]][1]=i;
            }
        }
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        for(auto it=map.begin();it!=map.end();it++)
        {
            pq.push(it->second);
        }
        vector<vector<int>> pqs;
        pqs.emplace_back(pq.top());
        pq.pop();
        while(!pq.empty())
        {
            if(pq.top()[0]<pqs.back()[1])
            {
                pqs.back()[1]=max(pq.top()[1],pqs.back()[1]);
            }
            else
            {
                pqs.emplace_back(pq.top());
            }
            pq.pop();
        }
        vector<int> results;
        for(auto pq:pqs)
        {
            results.emplace_back(pq[1]-pq[0]+1);
        }
        return results;
    }
};