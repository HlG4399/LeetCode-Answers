/*
Problem Description:
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()) return false;
        int n=A.size();
        int diff=0;
        vector<int> diff_index;
        bool isRepeat=false;
        map<char,int> m;
        for(int i=0;i<n;++i){
            if(A[i]!=B[i]){
                diff++;
                diff_index.emplace_back(i);
            } 
            if(m[A[i]]>0) isRepeat=true;
            else m[A[i]]++;
        }
        if(diff==0 && isRepeat) return true;
        if(diff!=2) return false;
        swap(A[diff_index[0]],A[diff_index[1]]);
        return A==B;
    }
};