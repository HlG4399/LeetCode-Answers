/*
Problem Description:
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(),nums1.end());
        nums1.erase(std::unique(nums1.begin(),nums1.end()),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        nums2.erase(std::unique(nums2.begin(),nums2.end()),nums2.end());
        vector<int> results(nums1.size());
        auto it=std::set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),results.begin()); 
        results.resize(it-results.begin());
        return results;
    }
};