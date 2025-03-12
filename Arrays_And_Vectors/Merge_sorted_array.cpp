/*
Leetcode: 88. Merge Sorted Array

First attempt: 12/03/2025


INSTRUCTIONS:

Given two arrays in non-descending order, MERGE the two arrays and sort the numbers within nums1.
You are given: nums1 and nums2, your two arrays.

m and n representing the values in the two arrays, respectively.
Where m notes the elements that should be merged. The last n elements are set to zero and should be ignored.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // insert the values of nums2 into nums1, effectively merging the two
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // remove the zero values in the array
        nums1.erase(std::remove(nums1.begin(), nums1.end(), 0), nums1.end());
        // sort the final array
        sort(nums1.begin(), nums1.end());
    }
};

/*
REFLECTION:
While this code DID pass the 3 test cases provided, the code does lack the ability to fully meet all test cases, and ultimately
the code requires further coding to correct it.
*/
