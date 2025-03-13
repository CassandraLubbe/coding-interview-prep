/*
Leetcode:

27. Remove element

First attempt: 12/3/2025
Final attempt: 13/3/2025

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
        int insertPos = 0;    // temporary pointer

        for (int i = 0; i < size; i++) {
            // if the elements doesn't match val, swap with temporary pointer + 1
            if (nums[i] != val) {
                nums[insertPos++] = nums[i];
            }
            // if the element matches, incremenet k (which needs to be returned)
            if (nums[i] == val) {
                k++;
            }
        }
        // fill the remaining positions with the val element
        while (insertPos < size) {
            nums[insertPos++] = val;
        }

        return k;
    }
};

/*
REFLECTION:
I had the right idea in mind but no valid way to excecute it. I realized that I was overthinking the problem and needed to approach it
in a different way. A way that would allow me to swap the non-val elements forward while moving the val elements backwards. Which is 
why I changed by approach for attempt 2 (final attempt).
*/

// Final Attempt
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int left = 0;    // left side pointer
        
        for (int right = 0; right < nums.size(); right++) {
            // if element pointer to by right is not a val element, flip with element pointed to by left
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;    // incremenet left
            }
            // if element matches val, increase k
            else {
                k++;
            }
        }
        return nums.size() - k; // return value of non-val elements
    }
};
