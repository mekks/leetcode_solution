/*
Question:
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

//Sol:1 80ms
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int i = (temp.size()-1)/2;
        int j = temp.size()-1;
        int k = 0;
        while(k < nums.size())
        {
            if(k&1)
                nums[k++] = temp[j--];
            else
                nums[k++] = temp[i--];
        }          
    }
};
