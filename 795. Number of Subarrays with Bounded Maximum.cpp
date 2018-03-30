/*
Problem Description:
We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n=A.size(),result=0,j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>=L && A[i]<=R)
            {
                result+=i-j+1;
                k=i+1;
            }
            else
            {
                if(A[i]<L)
                {
                    result+=i-j+1-(i-k+1);
                }
                else
                {
                    k=i+1;
                    j=k;
                }
            }
        }
        return result;
    }
};