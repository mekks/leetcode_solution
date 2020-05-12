/*
Question:
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

*/

//Sol_1 8ms
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          vector<int> res_Vec; 
		unordered_map<int, int> map;
        for (int number: nums1) {
            map[number]++; // Store the count of each number
        }
        for ( int number: nums2) {
            map[number]--; // If it appears in the second map, pop it back into the vector
            if (map[number] >= 0) res_Vec.push_back(number); 
        }
        return res_Vec;
    }
};
