/*
Question:
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/
//Solution_1  20ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        if(k%nums.size())
        {
            reverse(nums.begin(),nums.end());
            reverse(nums.begin(),nums.begin()+k%nums.size());
            reverse(nums.begin()+k%nums.size(),nums.end());
        }
    }
};

//Solution_2 28ms
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        k=k%nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size()- 1);
        
    }
    void reverse(vector<int>& nums,int begin , int  end)
    {
        int temp;
        while(begin < end)
        {
            temp=nums[begin];
            nums[begin]=nums[end];
            nums[end]=temp;
            begin++;
            end--;
        }
    }
};

*/
