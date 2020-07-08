/*
Question:
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

//Sol:1 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
        int i;
        
        for(i = 0 ;i < pow(2,nums.size());i++)
        {
            bitset<32> M(i);
            vector<int> a;
            for(int j=0; j<nums.size();j++)
            {
                if(M.test(j))
                {
                    a.push_back(nums[j]);
                }
        
            }
            res.push_back(a);
        }
        return res;
    }
};
