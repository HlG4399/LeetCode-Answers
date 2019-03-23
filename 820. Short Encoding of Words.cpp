/*
Problem Description:
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 

Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.
*/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> hash(words.begin(),words.end());
        for(auto word:hash){
            int n=word.size();
            for(int i=1;i<n;++i) hash.erase(word.substr(i));
        }
        int result=0;
        for(auto word:hash) result+=word.size()+1;
        return result;
    }
};