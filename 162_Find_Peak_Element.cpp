/*
Question:
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Follow up: Your solution should be in logarithmic complexity.
*/

//Sol:1 24ms
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        for(int i=0;i<nums.size();i++)
        {
            int prev = (i == 0) ? nums[nums.size()-1] : nums[i-1];
            int next = (i == nums.size()-1) ? nums[0] : nums[i+1];
            if (nums[i]>prev && nums[i]>next) return i;
        }
        return 0;
    }
};
*/

//Sol:2 8ms
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int high=nums.size()-1;
        int mid=(high)/2;
        while(1)
        {
            
            if(mid==0)
            {
                if(high==0)
                    return mid;
                if(nums[mid]>nums[mid+1])
                    return mid;
                else
                    mid=mid+1;
            }
            else if(mid==high)
            {
                if(nums[mid]>nums[mid-1])
                    return mid;
                else
                    mid=mid-1;
            }
            else
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                else if(nums[mid]<nums[mid-1])
                {
                    mid=mid-1;
                }
                else
                {
                    mid=mid+1;
                }
            }
            
        }
        return -1;
    }
};
*/


//Sol:3 8ms
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       return max_element(nums.begin(),nums.end())-nums.begin(); 
    }
};
