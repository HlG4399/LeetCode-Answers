/*
Problem Description:
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result=0,n=words.size();
        vector<bitset<32>> words_bits(n);
        for(int i=0;i!=n;i++)
        {
            for(auto ch:words[i])
            {
                words_bits[i][ch-'a']=1;
            }
            for(int j=0;j<i;j++)
            {
                if((words_bits[i]&words_bits[j]).none())
                {
                    result=max(result,(int)(words[i].size()*words[j].size()));        
                }
            }
        }
        return result;
    }
};