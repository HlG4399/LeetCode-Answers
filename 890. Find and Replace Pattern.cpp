/*
Problem Description:
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> results;
        int n=pattern.size();
        for(auto word:words){
            if(n!=word.size()) continue;
            unordered_map<char,char> p2w,w2p;
            int i;
            for(i=0;i<n;++i){
                auto p=pattern[i];
                auto w=word[i];
                if(p2w.count(p)>0 && p2w[p]!=w) break;
                p2w[p]=w;
                if(w2p.count(w)>0 && w2p[w]!=p) break;
                w2p[w]=p;
            }
            if(i==n) results.emplace_back(word);
        }
        return results;
    }
};