/*
Problem Description:
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1)
        {
            return true;
        }
        int flag=0;
        if(islower(word[0]))
        {
            flag=2;
        }
        else
        {
            if(isupper(word[1]))
            {
                flag=1;
            }
            else
            {
                flag=3;
            }
        }
        for(int i=1;i!=word.size();i++)
        {
            switch(flag)   
            {
                case 1:
                    if(islower(word[i]))
                    {
                        return false;
                    }
                    break;
                case 2:
                    if(isupper(word[i]))
                    {
                        return false;
                    }
                    break;
                case 3:
                    if(isupper(word[i]))
                    {
                        return false;
                    }
                    break;
            }

        }
        return true;
    }
};