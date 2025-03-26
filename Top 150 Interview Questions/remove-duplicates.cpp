/*
REMOVE DUPLICATES

Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.
Then return the number of unique elements in nums.

1st attempt: 20/3/2025
2nd attemtp: 22/3/2025
3rd attempt: 22/3/2025
4th attempt: 25/3/2025
final attempt: 26/3/2025
*/

int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int size = nums.size();
    int move = 0;

    for (int i = 0; i < size; i++)
    {
        int left = i + 1;
        if (nums[i] != nums[left])
        {
            left++;
        }
        else if (nums[i] == nums[left])
        {
            k++;
            move = nums[left + 1];
            for (int j = left; j < size; j++)
            {
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

int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int size = nums.size();

    if (size == 1)
    {
        return nums.size() - k;
    }
    else if (size == 2)
    {
        if (nums[0] == nums[1])
        {
            k++;
            return nums.size() - k;
        }
    }
    else if (size >= 3)
    {
        for (int i = 0; i < size; i++)
        {
            int right = i - k;
            int left = right + 1;
            int move = left + 1;

            if (nums[right] == nums[left])
            {
                k++;
                if (left < size && move < size)
                {
                    for (int j = left; j < size - 1; j++)
                    {
                        swap(nums[left], nums[move]);
                        left++;
                        move++;
                    }
                }
            }
        }
    }
    if (size == k)
    {
        return nums.size() - k + 1;
    }
    else
    {
        return nums.size() - k;
    }
}

// Overthinking it led to the following code being ACCEPTED but being a whole mess and using some serious runtime.
// 22/3/2025
int removeDuplicates(vector<int> &nums)
{
    int size = nums.size() - 1;
    int end = nums.size();
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        int r = i - k;
        int l = r + 1;
        if (nums[r] == nums[l])
        {
            k++;

            int m = l + 1;
            while (m < end)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
        }
        else if (nums[r] != nums[l])
        {
            // do nothing
        }
    }
    return nums.size() - k;
}

// Reevaluated life choices. Had a pep talk with myself. Then realized that I was overcomplicating things by trying to
// have the pointers move in sync when I could simply have one holding onto the value that's unique and another moving
// through the vector searching for my next unique value.

// This resulted in the below code (ACCEPTED): 25/3/2025

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

// Then happenstance happened, and I ended up watching some YouTube videos and realizing that yep, it's called easy
// for a reason. Which ultimately, led to my final attempt for this problem.

int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int size = nums.size();

    auto it = unique(nums.begin(), nums.end());
    nums.erase(it, nums.end());

    int newSize = nums.size();
    k = size - newSize;

    return k;
}