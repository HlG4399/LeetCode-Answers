/*
Problem Description:
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> set;
        for(auto d:dict)
        {
            set.insert(d);
        }
        
        //const char* convert to char*
        char* strc = (char*)sentence.c_str();
        string pattern=" ";
        char* p=(char*)pattern.c_str();
        char* tempStr=strtok(strc,p);
        int len=sentence.size(),n=0;
        unordered_set<string>::iterator it;
        bool flag=false;
        string result="";
        while(tempStr)
        {   
            flag=false;
            n=string(tempStr).size();
            for(int i=1;i<=n;i++)
            {
                it=set.find(string(tempStr).substr(0,i));
                if(it!=set.end())
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                result.append(*it);              
            }
            else
            {
                result.append(string(tempStr));
            }
            result.append(" ");
            tempStr=strtok(NULL,p);
        }
        
        if(sentence[0]==' ')
        {
            result=" "+result;
        }
        if(sentence[len-1]!=' ')
        {
            result.erase(result.size()-1,1);
        }
        return result;
    }
};