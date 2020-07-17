/*
Question:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

//Sol:1 164ms
/*
class Solution {
public:
    vector<vector<string>> res;
	string S;
	bool check(string s){
		int start=0;
		int end=s.size()-1;
		while(start<end){
			if(s[start]!=s[end]){
				return false;
			}
			start++;
			end--;
		}

		return true;

	}
    
	void dfs(int index,vector<string> path){
		if(index==S.size()){
			res.push_back(path);
			return;
		}
		for(int i=index;i<S.size();i++){
			string sub=S.substr(index,i-index+1);
			if(check(sub)){
				path.push_back(sub);
				dfs(i+1,path);
				path.pop_back();
			}
		}

	}
    vector<vector<string>> partition(string s) {
		S=s;
		vector<string> path;
		dfs(0,path);
		return res;
	}
    
};
*/

//Sol:2 16ms
class Solution {
public:
    vector<vector<string>> rst;
    vector<vector<bool>> dp;
    
    void helper(const string& s, int i, vector<string>& path) {
        if (i == s.size()) {
            rst.push_back(path);
        }
        else {
            for (int j(i); j < s.size(); ++j) {
                if (dp[i][j]) {
                    path.push_back(s.substr(i, j-i+1));
                    helper(s, j+1, path);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // use DP to find all palindrome
        int N = s.size();
        dp.assign(N, vector<bool>(N, false));
        for (int i(0); i < N; ++i) {
            dp[i][i] = true;
        }
        for (int l(2); l <= N; ++l) {
            for (int i(0); i <= N - l; ++i) {
                int j = i + l - 1;
                dp[i][j] = (s[i] == s[j]) and ((i == j-1) or (dp[i+1][j-1]));
            }
        }
        // backtracking to get all possible partitions
        vector<string> path;
        helper(s, 0, path);
        return rst;
    }
    
};
