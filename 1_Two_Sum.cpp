/*
QUESTION:

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> unmap;
        int i;
        for(i=0 ;i<nums.size();i++)
        {
            unmap[nums[i]]=i;
        }
        
        for( i=0 ;i<nums.size();i++)
        {
            int temp=target-nums[i];
            
            if(unmap.find(temp)!=unmap.end() && unmap[temp]!=i)
            {
                return {i,unmap[temp]};
            }
        }
        return {-1,-1};
    }
};
