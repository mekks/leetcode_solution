/*
Question:

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/


//Sol:1 12ms
/*
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
                const auto N = s.size();
        const auto M = wordDict.size();
        if (N == 0 || M == 0) return false;

        std::vector<bool> dp(N + 1, false);dp[0] = true;
        for (int i = 0; i < N; ++i) {
            for(auto& str : wordDict) {
                int len = str.size();
                if(dp[i]) {
                    if(s.substr(i,len) == str) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        return dp[N];
    }
};
*/

//Sol:2 8ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto a:wordDict) mp[a]++;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j] && mp.find(s.substr(j,i-j))!=mp.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];  
    }
};
