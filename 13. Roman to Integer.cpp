/*
Problem Description:
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        for(int i=0;i!=s.size();i++)
        {
            switch(s[i])
            {
                case 'I':
                    if(s[i+1]=='V' || s[i+1]=='X')
                    {
                        result--;
                    }
                    else
                    {
                        result++;
                    }
                    break;
                case 'V':
                    result+=5;
                    break;
                case 'X':
                    if(s[i+1]=='L' || s[i+1]=='C')
                    {
                        result-=10;
                    }
                    else
                    {
                        result+=10;
                    }
                    break;   
                case 'L':
                    result+=50;
                    break;
                case 'C':
                    if(s[i+1]=='D' || s[i+1]=='M')
                    {
                        result-=100;
                    }
                    else
                    {
                        result+=100;
                    }
                    break;  
                case 'D':
                    result+=500;
                    break;
                case 'M':
                    result+=1000;
            }
        }
        return result;
    }
};