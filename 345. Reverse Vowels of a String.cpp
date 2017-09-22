/*
Problem Description:
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        string temp_str="";
        for(int i=0;i!=s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||                    s[i]=='U')
            {
                temp_str+=s[i];
                index.emplace_back(i);
            }
        }
        reverse(temp_str.begin(),temp_str.end());
        for(int i=0;i!=index.size();i++)
        {
            s[index[i]]=temp_str[i];
        }
        return s;
    }
};