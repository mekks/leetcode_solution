/* 
Question:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

Solution:
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            while(l<r && !isalnum(s[l]))
            {
                l++;
            }
            while(l<r && !isalnum(s[r]))
            {
                r--;
            }
            if(tolower(s[l++]) != tolower(s[r--]))
            {
                return false;
            }
        }
        return true;
    }
};
