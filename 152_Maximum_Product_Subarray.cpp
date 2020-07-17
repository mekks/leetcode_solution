/*
Question:
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

//Sol:1 16ms
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int current_max = 1;
        int current_min = 1;
        int prev_max = 1;
        int prev_min = 1;
        
        int maximum = INT_MIN;
                
        for (int current: nums) {
            //max at current number
            current_max = max (current, max (current * prev_max, current * prev_min));
            
            //min at current number
            current_min = min (current, min (current * prev_max, current * prev_min));
            
            //keep track of overall max
            maximum = max (maximum, current_max);
            
            //keep track of previous
            prev_max = current_max;
            prev_min = current_min;
        }
        
        
        return maximum;
    }
    
};
*/

//Sol:2 12ms
class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n=nums.size();
        //product from start and end
        int f_prod = 1;
    	int b_prod = 1;
  		int ans = INT_MIN;
        
        
        
  		for (int i = 0; i < n; ++i) {
  			f_prod *= nums[i];
  			b_prod *= nums[n - i - 1];
  			ans = max(ans,max(f_prod,b_prod));
            
            //when any prod become zero start from 1
  		    f_prod = f_prod == 0 ? 1 :f_prod;
  		    b_prod= b_prod == 0 ? 1 : b_prod;
        }
        
        return ans;
    }
    
};
