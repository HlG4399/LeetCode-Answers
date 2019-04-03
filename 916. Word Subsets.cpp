/*
Problem Description:
We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

 

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
 

Note:

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j].
*/

class Solution {;
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int n_A=A.size(),n_B=B.size();
        vector<vector<int>> count_A(n_A,vector<int>(26,0));
        vector<vector<int>> count_B(n_B,vector<int>(26,0));
        vector<int> maxCount(26,0);
        for(int i=0;i<n_A;++i)
            for(auto a:A[i]) ++count_A[i][a-'a'];
        for(int i=0;i<n_B;++i){
            for(auto b:B[i]){
                ++count_B[i][b-'a'];
                maxCount[b-'a']=max(maxCount[b-'a'],count_B[i][b-'a']);
            }
        }
        vector<string> results;
        for(int i=0;i<n_A;++i){
            bool flag=true;
            for(int j=0;j<26;++j){
                if(maxCount[j]!=0 && maxCount[j]>count_A[i][j]){
                    flag=false;
                    break;
                }
            }
            if(flag) results.push_back(A[i]);
        }
        return results;
    }
};