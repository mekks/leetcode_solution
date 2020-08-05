/*
Question:
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false
*/

//Sol:1 12ms
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // we need to prove that for a given num 2 
        //smaller numbers exist before a given number
        
        int x=INT_MAX,y=INT_MAX;
        for(auto a:nums)
        {
            if(x>=a) x=a;
            else if(y>=a) y=a;
            else return true;                
        }
        return false;
    }
};
*/

//Sol:2 8ms
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // we need to prove that for a given num 2 
        //smaller numbers exist before a given number
        int n=nums.size();
        if(n<3)return false;
        
        int x=INT_MAX,y=INT_MAX;
        for(auto a:nums)
        {
            if(x>=a) x=a;
            else if(y>=a) y=a;
            else return true;                
        }
        return false;
    }
};
