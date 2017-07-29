/*
Problem Description:
Say you have an array for which the $i^{th}$ element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
        int result=0,temp=prices[0];
        for(int i=1;i!=prices.size();i++)
        {
            if(prices[i]>temp)
            {
                result+=prices[i]-temp;
            }
            temp=prices[i];
        }
        return result;
    }
};