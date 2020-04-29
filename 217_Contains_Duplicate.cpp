/*
Question:
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

//Sol:1 56ms
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return false;
        sort(nums.begin(), nums.end());
        int slow = nums[0];
        int fast = nums[1];
        for(int i = 2 ; i < nums.size() ; i++)
        {
            if(slow == fast) return true;
            slow = fast;
            fast = nums[i];
        }
        if(slow == fast) return true; // check the last two elements
        return false;
    }
};

//Sol:2  52 ms
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) { return false; }
        unordered_map<int,int> mp;
        for (int i : nums) {
            if (++mp[i] > 1) {
                return true;
            }
        }
        return false;
    }
};

//Sol:3 156 ms 
// hash map solution 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    map<int, bool> myMap;
    // unordered_map<int, bool> myMap;
    for (auto& num: nums) {
        if (myMap.find(num) != myMap.end())
            return true;
        else
            myMap[num] = true;
    }
    return false;
    }
};

*/
//Sol:4 44ms  without using extra variabl
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     if (nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};
