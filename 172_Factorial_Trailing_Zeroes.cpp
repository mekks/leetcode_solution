/*
Question:
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.

*/
//Solution_1   0ms

class Solution {
public:
    int trailingZeroes(int n) {
        long long a = 5, ans = 0;
        while(n/a) {
            ans += n/a;
            a *= 5;
        }
        return ans;
    }
};
