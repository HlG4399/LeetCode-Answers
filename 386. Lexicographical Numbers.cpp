/*
Problem Description:
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> results;
        int num=1;
        for(int i=1;i<=n;i++)
        {
            results.emplace_back(num);
            if(num*10<=n)
            {
                num*=10;
            }
            else
            {
                if(num%10!=9 && num<n)
                {
                    num++;
                }
                else
                {
                    while((num/10)%10==9)
                    {
                        num/=10;
                    }
                    num=num/10+1;
                }
            }
        }
        return results;
    }
};