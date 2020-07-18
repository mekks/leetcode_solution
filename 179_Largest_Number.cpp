/*
Question:
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

//Sol:1 20ms
class Solution {
public:
    static bool cmp(int a,int b)
    {          
        string x=to_string(a),y=to_string(b);
        return x+y > y+x;
    }
    
    string largestNumber(vector<int>& nums) {
        if(!nums.empty() && nums[0]==0 && accumulate(nums.begin(),nums.end(),0)==0) return "0";
        sort(nums.begin(),nums.end(),cmp);
        string x;
        for(auto a:nums) x+=to_string(a);
        return x;
    }
    
};
