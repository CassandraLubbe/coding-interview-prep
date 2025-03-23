/*
REMOVE DUPLICATES

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.

1st attempt: 20/3/2025
2nd attemtp: 22/3/2025
*/

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    int size = nums.size();
    int move = 0;
    
    for (int i = 0; i < size; i++) {
        int left = i + 1;
        if (nums[i] != nums[left]) {
            left++;
        }
        else if (nums[i] == nums[left]) {
            k++;
            move = nums[left + 1];
            for (int j = left; j < size; j++) {
                swap(nums[left], nums[move]);
                left++;
                move++;
            }
        }
    }
    return nums.size() - k;
}

/*
REFLECTION:

Removes all duplicates if there are only one, still figuring out how to correct the logic so that it removes all instances.
I know that my first pointer i moves to the next too early.
*/

// Attempt 2

// Starting to over think the code. This passes 211 of 362 test cases.
// The if return statement is a quick fix to when it doesn't pass an array of [1, 1, 1, 1]
// BUT it's messy and should be simplified.
// (But that's how you learn :D ) 

int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int size = nums.size();
        
        
        if (size == 1) {
            return nums.size() - k;
        }
        else if (size == 2) {
            if (nums[0] == nums[1]) {
                k++;
                return nums.size() - k;
            }
        }
        else if (size >= 3) { 
            for (int i = 0; i < size; i++) {
                int right = i - k;
                int left = right + 1;
                int move = left + 1;

                if (nums[right] == nums[left]) {
                    k++;
                    if (left < size && move < size) {
                        for (int j = left; j < size - 1; j++) {
                            swap(nums[left], nums[move]);
                            left++;
                            move++;
                        }
                    }
                }
            }
        }
        if (size == k) {
            return nums.size() - k + 1;
        }
        else {
            return nums.size() - k;
        }
    }
