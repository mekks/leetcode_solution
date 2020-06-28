/*
Question:
Given a string, find the length of the longest substring without repeating characters
Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring
*/

//Sol:1 52ms 
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i=0,j=0,ans=0,n=s.size();
        
        while( i<n && j<n)
        {
            if(set.find(s[j])==set.end() )//check char is in set or not 
            {
                set.insert(s[j++]); //insert char
                ans=max(ans, j-i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }
        return ans;
    }
};
*/

//Sol:2 32ms
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>m;
        int maxlen=0 ;
        
        for(int i = 0, j = 0; j < s.size(); j++)
        {
            m[s[j]]++;
            while(m[s[j]] > 1)m[s[i++]]--;
            maxlen=max(maxlen , j-i+1);
                                  
        }
        return maxlen;
    }
};
*/

//Sol:3 12ms

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs = "";
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            size_t at = subs.find(s[i]);
            if ( at != string::npos) {
                subs.erase(0, at+1);
            }
            subs += s[i];
            res = subs.size() > res ? subs.size() : res;
        }
        return res;
    }
};
          
