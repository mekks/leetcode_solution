/*
Question:
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

//Sol:1 12ms recursive
class Solution {
public:
    void helper(int&sum,vector<vector<int>>&result,vector<int>&curr,int index,const vector<int>&candidates,const int&target)
    {
        if(sum > target)return;
        if(sum == target)
        {
            result.push_back(curr);
            return;
        }
        for(int i=index; i<candidates.size();i++)
        {
            sum += candidates[i];curr.push_back(candidates[i]);
            helper(sum,result,curr,i,candidates,target);
            sum -= candidates[i];curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<vector<int>>result;
        vector<int>curr;
        helper(sum,result,curr,0,candidates,target);
        return result;
    }
};
