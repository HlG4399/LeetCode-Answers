/*
Problem Description:
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> results;
        unordered_map<string,int> hash;
        int pre_pos=0,length_A=A.size(),length_B=B.size();
        for(int i=0;i<length_A;i++)
        {
            if(A[i]==' ')
            {
                hash[A.substr(pre_pos,i-pre_pos)]++;
                pre_pos=i+1;
            }
        }
        if(length_A>0) hash[A.substr(pre_pos, length_A-pre_pos)]++;
        pre_pos=0;
        for(int i=0;i<length_B;i++)
        {
            if(B[i]==' ')
            {
                hash[B.substr(pre_pos,i-pre_pos)]++;
                pre_pos=i+1;
            }
        }
        if(length_B>0) hash[B.substr(pre_pos, length_B-pre_pos)]++;
        for(auto it=hash.begin();it!=hash.end();it++)
            if(it->second<=1) results.emplace_back(it->first);
        return results;
    }
};