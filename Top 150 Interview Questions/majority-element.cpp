/*
Given an unordered array, identify the majority element in the array. Assume that the majority element is equal to 
n / 2 (where n is the size of the array).

Attempt 1: 26/3/2025
Attemtp 2: 28/3/2025
Attempt 3 and 4: 31/3/2025
*/

// Attempt 1

int majorityElement(vector<int>& nums) {
    int k = 0;
    int counter = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        int r = 0;
        if (nums[r] == nums[i]) {
            counter ++;
            k = nums[r];
        }
        else if (nums[r] != nums[i]) {
            k = nums[i];
            r = i;
            counter = 0;
        }
    }
    return k;
}

// works but doesn't stop when the majority element is found, instead continues the search.

// Attempt 2
int majorityElement(vector<int>& nums) {
    int k = 0;
    int counter = 0;
    int n = nums.size() / 2 + 1;
  
    sort(nums.begin(), nums.end());
  
    for (int i = 0; i < nums.size(); i++) {
        int r = 0;
        if (nums[r] == nums[i]) {
            counter ++;
            k = nums[r];
  
        }
        else if (nums[r] != nums[i]) {
            k = nums[i];
            r = i;
            counter = 0;
        }
  
        if (counter >= n) {
            return k;
        }
    }
    return k;
}

// Running into an issue wheere the wrong majority element is being returned, specifically when it's one off of the n / 2.

// Attempt 3
int majorityElement(vector<int>& nums) {
    int k = 0;
    int counter = 0;
    int r = 0;
    int size = nums.size();
    int n = 0;

    if (size % 2 == 0) {
        n = size / 2;
    }
    else {
        n = size / 2 + 1;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++) {
        if (nums[r] == nums[i]) {
            counter ++;
            k = nums[r];
        }
        else if (nums[r] != nums[i]) {
            k = nums[i];
            r = i;
            counter = 0;
        }
        
        if (counter >= n) {
            return k;
        }
    }
    return k;
}

// attempt to correct incorrect element being returned when it matches n/2, however, while mostly accepted, runs into errors.

// Attempt 4
// realized the issue came when the counter was being reset for the next element to be counter. Therefore
// the solution was to reset the counter to 1, as this ensures that the new element is counted correctly, and 
// removes the complexity of an if statement to handle n/2.
int majorityElement(vector<int>& nums) {
    int k = 0;
    int counter = 0;
    int r = 0;
    int size = nums.size();
    int n = size / 2 + 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++) {
        if (nums[r] == nums[i]) {
            counter ++;
            k = nums[r];
        }
        else if (nums[r] != nums[i]) {
            k = nums[i];
            r = i;
            counter = 1;
        }
        
        if (counter >= n) {
            return k;
        }
    }
    return k;
}


