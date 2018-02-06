/*
Problem Description:
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

class Solution {
private:
    unordered_map<string,vector<int>> map;
public:
    vector<int> diffWaysToCompute(string input) {
        if(map.count(input)>0)
        {
            return map[input];
        }
        int len=input.size();
        char ch=' ';
        vector<int> results;
        for(int i=0;i!=len;i++)
        {
            ch=input[i];
            if(ch=='+' || ch=='-' || ch=='*')
            {
                for(auto leftNum:diffWaysToCompute(input.substr(0,i)))
                {
                    for(auto rightNum:diffWaysToCompute(input.substr(i+1,len-i)))
                    {
                        switch(ch)
                        {
                            case '+':
                                results.emplace_back(leftNum+rightNum);
                                break;
                            case '-':
                                results.emplace_back(leftNum-rightNum);
                                break;
                            case '*':
                                results.emplace_back(leftNum*rightNum);
                            default:
                                break;
                        }
                    }
                }
            }
        }
        if(results.empty())
        {
            results.emplace_back(stoi(input));
        }
        map[input]=results;
        return results;
    }
};