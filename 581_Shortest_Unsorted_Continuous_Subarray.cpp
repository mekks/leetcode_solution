/*
Question:
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

//Sol:1 100ms
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        if (numsCopy == nums) return 0;

        
        int left = 0, right = nums.size() - 1;
        // Find the parts of the array that havent changed from the left and the right.
		// The difference between the two are the length of the subarray that needs to be sorted.
        while (nums[left] == numsCopy[left])
        {
            left++;
        }
        
        while (nums[right] == numsCopy[right])
        {
            right--;
        }
        
        return right - left + 1;
    }
};
