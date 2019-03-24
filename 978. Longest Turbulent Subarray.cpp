/*
Problem Description:
A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

 

Example 1:

Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
Example 2:

Input: [4,8,12,16]
Output: 2
Example 3:

Input: [100]
Output: 1
 

Note:

1 <= A.length <= 40000
0 <= A[i] <= 10^9
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n=A.size();
        if(n==1) return 1;
        int start=0,end=1;
        bool israise=A[end]>A[start];
        int result=1;
        while(end<n-1){
            if(A[end]!=A[end-1] && (israise && A[end+1]<A[end] || (!israise && A[end+1]>A[end]))){
                ++end,israise=!israise;
                continue; 
            }
            result=A[end]!=A[end-1]?max(result,end-start+1):result;
            start=end++;
            israise=A[end]>A[start];
        }
        return A[end]!=A[end-1]?max(result, end - start + 1):result;
    }
};