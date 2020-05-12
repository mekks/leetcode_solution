/*
Question:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

//Sol_1 44 ms  XOR solution
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing=nums.size();
        for(int i=0; i < nums.size() ; i++)
        {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};
*/

//Sol_2 40ms 
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int expected_Sum = nums.size() * (nums.size() + 1)/2;
        int actual_Sum =0;
        for(int num : nums)
        {
            actual_Sum += num;
        }
        return expected_Sum - actual_Sum;
    }
};
