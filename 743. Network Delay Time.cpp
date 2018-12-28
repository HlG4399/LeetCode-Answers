/*
Problem Description:
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.empty()) return -1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        unordered_map<int,vector<vector<int>>> hash;
        for(auto time:times)
        {
            if(hash.find(time[0])!=hash.end())
            {
                vector<vector<int>> temp=hash[time[0]];
                temp.push_back({time[1],time[2]});
                hash[time[0]]=temp;
            }
            else
                hash[time[0]]={{time[1],time[2]}};
        }
        vector<int> distance(N+1,INT_MAX);
        distance[K]=0;
        pq.push({K,0});
        while(!pq.empty())
        {
            int u=pq.top().first;
            pq.pop();
            if(hash.find(u)!=hash.end())
            {
                vector<vector<int>> Adjs=hash[u];
                for(auto adj:Adjs)
                {
                    int v=adj[0];
                    int w=adj[1];
                    if(distance[v]>distance[u]+w)
                    {
                        distance[v]=distance[u]+w;
                        pq.push({v,distance[v]});
                    }
                }
            }
        }
        int result=0;
        for(int i=1;i<=N;i++)
        {
            if(distance[i]==INT_MAX) return -1;
            result=max(result,distance[i]);
        }
        return result;
    }
    
    struct compare{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return a.second>b.second;
        }
    };
};