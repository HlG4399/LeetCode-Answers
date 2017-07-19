/*
Problem Description:
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    char alphabet1_[] = { 'q','w','e','r','t','y','u','i','o','p' };
	std::vector<char> alphabet1;
	for (int i = 0; i != sizeof(alphabet1_) / sizeof(alphabet1_[0]); i++)
	{
		alphabet1.push_back(alphabet1_[i]);
	}
	char alphabet2_[] = { 'a','s','d','f','g','h','j','k','l'};
	std::vector<char> alphabet2;
	for (int i = 0; i != sizeof(alphabet2_) / sizeof(alphabet2_[0]); i++)
	{
		alphabet2.push_back(alphabet2_[i]);
	}
	char alphabet3_[] = { 'z','x','c','v','b','n','m'};
	std::vector<char> alphabet3;
	for (int i = 0; i != sizeof(alphabet3_) / sizeof(alphabet3_[0]); i++)
	{
		alphabet3.push_back(alphabet3_[i]);
	}
	std::vector<std::vector<char>> alphabet;
	alphabet.push_back(alphabet1);
	alphabet.push_back(alphabet2);
	alphabet.push_back(alphabet3);
	std::vector<string> results;
    for (int i = 0; i != words.size(); i++)
	{
		int j = 0, flag = -1;
		for (; j != words[i].size(); j++)
		{
			int k = 0;
			for (; k != alphabet.size(); k++)
			{
				auto it = std::find(alphabet[k].begin(), alphabet[k].end(), (char)tolower(words[i][j]));
				if (it != alphabet[k].end())
				{
					if (flag == -1)
					{
						flag = k;
					}
					if (flag != -1 && k != flag)
					{
						break;
					}
				}
			}
			if (k != alphabet.size())
			{
				break;
			}
		}
		if (j == words[i].size() && flag != -1)
		{
			results.push_back(words[i]);
		}
    }
    return results;
    }
};