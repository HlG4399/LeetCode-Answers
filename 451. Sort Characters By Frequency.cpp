/*
Problem Description:
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public: 
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto ch:s)
        {
            map[ch]++;
        }
        sort(s.begin(),s.end(),[&](char& ch1,char& ch2){
            return map[ch1]>map[ch2] || (map[ch1]==map[ch2] && ch1<ch2);
        });
        return s;
    }   
};