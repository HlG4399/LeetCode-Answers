/*
Problem Description:
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

 

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true
 

Note:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] and equations[i][3] are lowercase letters
equations[i][1] is either '=' or '!'
equations[i][2] is '='
*/

class Solution {
private:
    vector<int> parents;
public:
    bool equationsPossible(vector<string>& equations) {
        parents.resize(26,-1);
        for(auto equation:equations){
            if(equation[1]=='=') merge_mfset(equation[0]-'a',equation[3]-'a');
        }
        for(auto equation:equations){
            if(equation[1]=='!') if(find_mfset(equation[0]-'a')==find_mfset(equation[3]-'a')) return false;
        }
        return true;
    }

    int find_mfset(int i,int j=0){
        if(i<0 || i>parents.size()) return -1;
        for(j=i;parents[j]>=0;j=parents[j]);
        return j;
    }
    void merge_mfset(int i,int j){
        if (i<0 || i>parents.size() || j<0 || j>parents.size()) return;
        int pi = find_mfset(i);
        int pj = find_mfset(j);
        if(pi==pj) return;
        if (pi > pj) {
            parents[pj] += parents[pi];
            parents[pi] = pj;
        } 
        else {
            parents[pi] += parents[pj];
            parents[pj] = pi;
        }
    }
};