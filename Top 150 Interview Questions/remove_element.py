## Remove element
## 27 [Remove Element](https://leetcode.com/problems/remove-element/description/) 

def removeElement(self, nums, val):
        ptr1 = 0
        ptr2 = len(nums) - 1
        k = 0

        while ptr1 <= ptr2:
            if val == nums[ptr1]:
                k += 1
                if val != nums[ptr2]:
                    temp = nums[ptr1]
                    nums[ptr1] = nums[ptr2]
                    nums[ptr2] = temp
                    ptr2 -= 1
                    ptr1 += 1
                else:
                    ptr2 -= 1
            elif val != nums[ptr1]:
                ptr1 += 1
        return len(nums) - k
