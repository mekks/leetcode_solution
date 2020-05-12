/*
Question:
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

//Sol_1 56ms
class Solution {
public:
    int firstUniqChar(string s) {
        int c_count[26] ={0};
        
        for(int i=0; i<s.length(); i++)
            c_count[s[i] - 'a']++;
        
        for(int i=0; i<s.length(); i++)
            if(c_count[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};
