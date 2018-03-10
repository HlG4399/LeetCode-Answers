/*
Problem Description:
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

class Solution {
private:
    unordered_map<string,unordered_map<string,double>> map;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n=equations.size();
        for(int i=0;i<n;i++)
        {
            map[equations[i].first][equations[i].second]=values[i];
            map[equations[i].second][equations[i].first]=1.0/values[i];
        }
        unordered_set<string> visited;
        vector<double> results;
        for(auto query:queries)
        {
            visited.clear();
            results.emplace_back(DFS(query.first,query.second,1.0,visited));
        }
        return results;
    }
    
    double DFS(const string& start,const string& end,double quad,unordered_set<string>& visited)
    {
        if(map.count(start)<=0 || visited.count(start)>0) return -1.0;
        if(start==end) return quad;
        visited.insert(start);
        double temp=0;
        for(auto it=map[start].begin();it!=map[start].end();it++)
        {
            temp=DFS(it->first,end,quad*it->second,visited);
            if(temp>=0) return temp;
        }
        visited.erase(start);
        return -1.0;
    }
};