/*
Problem Description:
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0<=x,y<2^31.

Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?
The above arrows point to positions where the corresponding bits are different.
*/

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=0;
        for(int i=31;i>=0;i--)
        {
            result+=abs(((x>>i)&1)-((y>>i)&1));
        }
        return result;
    }
};
