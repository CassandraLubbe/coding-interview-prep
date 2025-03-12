/*
Leetcode:

27. Remove element

First attempt: 12/3/2025

INSTRUCTIONS:

Given an integer array nums and a integer value val, remove all occurences of val in nums using in-place algorithm
Order of elements may be changed.
Return the number of elements in nums NOT equal to val.

K = number of elements in nums not equal to val. Return k.

Do the following:

* Change nums so that the first k elements of nums contain the elements which are not eqaul to val. 
(The remaining elements of nums are not important as well as the size of nums.)

* Return k.

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int size = nums.size();
        int insertPos = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[insertPos++] = nums[i];
            }
            if (nums[i] == val) {
                k++;
            }
        }
        while (insertPos < size) {
            nums[insertPos++] = val;
        }

        return k;
    }
};
