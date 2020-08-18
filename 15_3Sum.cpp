/*
Question:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//Sol:1 80ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i < n-2;i++)
        {
            int left=i+1 , right=n-1;
            while(left < right)
            {
                int s=nums[i]+nums[left]+nums[right];
                if(s<0)left++;
                else if(s>0)right--;
                else
                {
                    vector<int> t(3);
                    t[0]=nums[i];
                    t[1]=nums[left];
                    t[2]=nums[right];
                    ans.push_back(t);
                    //if same left position value further then left ++
                    while(left < right && nums[left]==t[1])left++;
                }
            }
            while(i<n-2 &&  nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
