/*
Problem Description:
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int result=0,len_S=S.size(),len_words=words.size(),x=-1;
        bool flag=true;
        unordered_map<char,vector<int>> hash;
        for(int i=0;i<len_S;i++) hash[S[i]].emplace_back(i);
        for(int j=0;j<len_words;j++)
        {
            x=-1;
            flag=true;
            for(auto w:words[j])
            {
                auto it=upper_bound(hash[w].begin(),hash[w].end(),x);
                if(it!=hash[w].end()) x=*it;
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag) result++;
        }
        return result;
    }
};