/*
Question:
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

//Sol:1 132ms
/*
class Solution {
public:class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector for storing longest increasing subsequence
        vector<int> lis;
        for(const int& num: nums) {
            // find the first number greater than current in LIS
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            // if no such number is found, we can add the current
            if(it == lis.end()) {
                lis.emplace_back(num);
            }
            // if a number greater exists, then replace it with current, this is
            // because putting the smaller number in place of a bigger number will allow
            // more numbers greater than current to be part of LIS
            else if(*it > num)
                *it = num;
        }
        return lis.size();
    }
};
    int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int ans=1;
    int list[n];
    list[0]=1;
    for(int i=1;i<nums.size();i++)
    {
        list[i]=1;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                list[i]=max(list[i],list[j]+1);
            }
        }
        ans=max(ans,list[i]);
    }
    return ans;
    }
};
*/
//Sol:2 4ms
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector for storing longest increasing subsequence
        vector<int> lis;
        for(const int& num: nums) {
            // find the first number greater than current in LIS
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            // if no such number is found, we can add the current
            if(it == lis.end()) {
                lis.emplace_back(num);
            }
            // if a number greater exists, then replace it with current, this is
            // because putting the smaller number in place of a bigger number will allow
            // more numbers greater than current to be part of LIS
            else if(*it > num)
                *it = num;
        }
        return lis.size();
    }
};
