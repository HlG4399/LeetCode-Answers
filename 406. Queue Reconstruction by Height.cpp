/*
Problem Description:
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> results;
        sort(people.begin(),people.end(),compare);
        for(auto p:people)
        {
            results.insert(results.begin()+p.second,p);
        }
        return results;
    }
    
    static bool compare(pair<int,int> pair1,pair<int,int> pair2)
    {
        return pair1.first>pair2.first || (pair1.first==pair2.first && pair1.second<pair2.second);
    }
};