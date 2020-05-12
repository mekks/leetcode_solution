/*
Question:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations
*/

//Sol-1 8ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         for (int i = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[i++], nums[cur]);
        }
    }
    }
};

//sol_2 8 ms
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            if (nums[i] != 0) {
                i++;
            }
            j++;
        }
    }
};
*/
