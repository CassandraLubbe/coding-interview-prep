/*
REMOVE DUPLICATES

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.

1st attempt: 20/3/2025
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
