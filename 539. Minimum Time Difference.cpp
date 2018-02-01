/*
Problem Description:
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end(),[](const string& s1,const string& s2){
           return s1[0]*10+s1[1]<s2[0]*10+s2[1] || (s1[0]*10+s1[1]==s2[0]*10+s2[1] && s1[3]*10+s1[4]<s2[3]*10+s2[4]); 
        });
        int result=INT_MAX,n=timePoints.size();
        for(int i=1;i<n;i++)
        {
            result=min(result,CountDifference(timePoints[i-1],timePoints[i]));
        }
        return min(result,CountDifference(timePoints[n-1],timePoints[0]));
    }
    
    int CountDifference(string s1,string s2)
    {
        int hour1=s1[0]*10+s1[1],hour2=s2[0]*10+s2[1];
        int min1=s1[3]*10+s1[4],min2=s2[3]*10+s2[4];
        int carry=(min2<min1?1:0);
        min2+=(min2<min1?60:0);
        hour2+=(hour2-carry<hour1?24:0);
        return (hour2-carry-hour1)*60+(min2-min1);
    }
};