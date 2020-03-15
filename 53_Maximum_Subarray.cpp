/*
QUESTION:

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
-----------------------------------------
DEVIDE AND CONQUER:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         return maxSub(nums, 0, nums.size() - 1);  
    }
private:
   int maxSub(vector<int>& nums, int l, int r) {
        if (l > r)
            return INT_MIN;
        int mid = (r-l)/2+l;
        int lMax = maxSub(nums, l, mid-1);
        int rMax = maxSub(nums, mid+1, r);
        int s1 = 0, s2 = 0;
        for (int i = mid-1, cur = 0; i >= l; i--) {
            cur += nums[i];
            s1 = max(s1, cur);
        }
        for (int i = mid+1, cur = 0; i <= r; i++) {
            cur += nums[i];
            s2 = max(s2, cur);
        }
        return max(s1+s2+nums[mid], max(lMax, rMax));
    }
};
*/
class Solution {
public:
    int maxSubArray(vector<int>&A) {
        int max = A[0], sum = 0;
        for(int i = 0; i < A.size(); i++){
          sum += A[i];
          if(max < sum)
            max = sum;
          if(sum < 0)
            sum = 0;
        }
        return max;
    }
};
