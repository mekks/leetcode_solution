/*
Question:
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

//sol:1 28ms
class Solution {
public:
    int findStartingIndex(vector<int> nums, int target)
    {
        
        int index=-1;
        
        int start=0;
        int end = nums.size()-1;
        
        while(start<=end)
        {
            int midPoint = start+(end-start)/2;
            
            if(nums[midPoint]>=target)
            {
                end = midPoint-1;
            }
            else
            {
                start = midPoint+1;
            }
            
            
            if(nums[midPoint] == target)
            {
                index = midPoint;
            }
        }
        
        return index;
        
    }
    
    int findEndingIndex(vector<int> nums, int target)
    {
        int index=-1;
        
        int start=0;
        int end = nums.size()-1;
        
        while(start<=end)
        {
            int midPoint = start+(end-start)/2;
            
            if(nums[midPoint]<=target)
            {
                start = midPoint+1;
            }
            else
            {
                end = midPoint-1;
            }
            
            if(nums[midPoint]==target)
            {
                index = midPoint;
            }
        }
        
        return index;
        
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result{-1,1};
        
        result[0] = findStartingIndex(nums, target);
        result[1] = findEndingIndex(nums, target);
        
        return result;
        
    }
};

//sol:2 32ms stl
/*
class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {        
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        if(int(lower-nums.begin())==nums.size())
            return vector<int>{-1,-1};
        
        if(nums[lower-nums.begin()]==target)
            return vector<int> {int(lower-nums.begin()), int(upper-nums.begin())-1};
        
        return vector<int>{-1,-1};
        
    }
};
*/
