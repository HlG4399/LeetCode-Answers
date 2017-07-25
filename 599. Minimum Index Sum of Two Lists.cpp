/*
Problem Description:
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> results;
        int min_index_sum=1000000;
        for(int i=0;i!=list1.size();i++)
        {
            auto it=std::find(list2.begin(),list2.end(),list1[i]);
            if(it!=list2.end())
            {
                if(min_index_sum>=i+it-list2.begin())
                {
                    if(min_index_sum>i+it-list2.begin())
                    {
                       results.clear();      
                       min_index_sum=i+it-list2.begin();
                    }
                    results.push_back(list1[i]);
                }
            }
        }
        return results;
    }
};