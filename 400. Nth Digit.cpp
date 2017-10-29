/*
Problem Description:
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        int level=1;
        while(n-level*9*pow(10,level-1)>0)
        {
            n-=level*9*pow(10,level-1);
            level++;
        }
        int temp=pow(10,level-1)+(n-1)/level;
        return to_string(temp)[(n-1)%level]-'0';
    }
};