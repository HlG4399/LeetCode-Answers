/*
Problem Description:
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
	    int result = 0;
	    string str = "";
	    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
	    for (; i >= 0 && j >= 0; i--, j--)
	    {
		    if (num1[i] - '0' + num2[j] - '0' + carry >= 10)
		    {
			    str = to_string(num1[i] - '0' + num2[j] - '0' + carry - 10) + str;
			    carry = (num1[i] - '0' + num2[j] - '0' + carry) / 10;
		    }
		    else
		    {
			    str = to_string(num1[i] - '0' + num2[j] - '0' + carry) + str;
                carry = 0;
		    }
	    }
	    while (i >= 0)
	    {
		    if (num1[i] - '0' + carry >= 10)
		    {
			    str = to_string(num1[i] - '0' + carry - 10) + str;
			    carry = (num1[i] - '0' + carry) / 10;
		    }
		    else
		    {
			    str = to_string(num1[i] - '0' + carry) + str;
                carry = 0;
		    }
		    i--;
	    }
	    while (j >= 0)
	    {
		    if (num2[j] - '0' + carry >= 10)
		    {
			    str = to_string(num2[j] - '0' + carry - 10) + str;
			    carry = (num2[j] - '0' + carry) / 10;
		    }
		    else
		    {
			    str = to_string(num2[j] - '0' + carry) + str;
                carry = 0;
		    }
		    j--;
	    }
        if (carry != 0)
	    {
		    str = to_string(carry) + str;
	    }
	    return str;
    }
};