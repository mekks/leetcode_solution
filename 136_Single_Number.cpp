/*
Question:
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/
// Soltion_1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> mySet;
        for(int i = 0;i < nums.size();++i)
        {
            if(mySet.find(nums[i]) == mySet.end()) mySet.insert(nums[i]);
            else mySet.erase(nums[i]);
        }
          auto it = mySet.begin();
          return *it;
    }
};


// Solution_2
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x_or=0;
        for(int i : nums)
        {
            x_or ^=i;
        }
        return x_or;
    }
};
*/
