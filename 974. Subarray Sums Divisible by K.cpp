/*
Problem Description:
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        vector<int> prefixSum(n+1,0);
        for(int i=1;i<n+1;++i) prefixSum[i]=prefixSum[i-1]+A[i-1];
        vector<int> counts(K,0);
        for(int i=0;i<n+1;++i) ++counts[(prefixSum[i]%K+K)%K];
        int result=0;
        for(auto count:counts) result+=(count)*(count-1)/2;
        return result;
    }
};
