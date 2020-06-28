/*
Question:
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

//Sol:1 28 ms
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         if(nums.empty()){
            return vector<int>{};
        }
        int n = nums.size();
        vector<int> ans(n, 1);
        int begin = 1, end = 1;
        for(int i = 0;i < n; ++i){
            ans[i] *= begin;
            begin *= nums[i];
            ans[n - 1 - i] *= end;
            end *= nums[n - 1 - i];
        }
        return ans;
    }
};

/*
//Sol:2 28ms

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int i,n = nums.size();
    vector<int> res(n,1);
    for(i=1;i<n;i++){
        res[i] = nums[i-1]*res[i-1];
    }
    long long pro = 1;
    for(i=n-1;i>=0;i--){
        res[i] *= pro;
        pro *= nums[i];
    }
    return res;
    }
};

*/
