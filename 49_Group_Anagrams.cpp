/*
Question:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter
*/

//Sol:1 112ms

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagram;
        unordered_map<string , vector<string>> mp;
        
        for(auto i: strs)
        {
            string s=i;
            sort(s.begin() , s.end());
            mp[s].push_back(i);
        }
        
        for(auto str: mp)
        {
            anagram.push_back(str.second);
        }
        return anagram;
    }
};
