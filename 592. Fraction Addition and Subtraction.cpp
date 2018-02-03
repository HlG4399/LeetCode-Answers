/*
Problem Description:
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ¡Ànumerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

class Solution {
public:
    string fractionAddition(string expression) {
        int molecular=0,denominator=1,temp_molecular=0,temp_denominator=1,p=-1,p1=0,p2=0,len=expression.size();
        while(p<len)
        {
            p1=p+1;
            while(expression[p1]!='/' && p1<len) p1++;
            p2=p1+1;
            while(expression[p2]!='+' && expression[p2]!='-' && p2<len) p2++;
            temp_molecular=stoi(expression.substr(p+1,p1));
            if(expression[p]=='-') temp_molecular*=-1;
            temp_denominator=stoi(expression.substr(p1+1,p2-p1));
            molecular=molecular*temp_denominator+temp_molecular*denominator;
            denominator*=temp_denominator;
            p=p2;
        }
        int d=abs(GCD(molecular,denominator));
        return to_string(molecular/d)+"/"+to_string(denominator/d);
    }
    
    int GCD(int a,int b)
    {
        return b==0?a:GCD(b,a%b);
    }
};