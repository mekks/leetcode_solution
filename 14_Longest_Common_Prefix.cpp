/*
QUESTION:

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(strs), end(strs));
        string start_str =strs[0];
        string end_str=strs[n-1];  
        
        // just compare first and last string 
        
        for(int i=0; i< start_str.size();i++)
        {
            if(start_str[i] ==end_str[i] )
            {
                ans += start_str[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
