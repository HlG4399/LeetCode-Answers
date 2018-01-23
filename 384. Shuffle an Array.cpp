/*
Problem Description:
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
private:
    vector<int> original_nums;
public:
    Solution(vector<int> nums) {
        original_nums=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> results(original_nums);
        int n=original_nums.size();
        if(n==0)
        {
            return results;
        }
        for(int i=0;i!=n;i++)
        {
            int temp=rand()%n;
            swap(results[i],results[temp]);
        }
        return results;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */