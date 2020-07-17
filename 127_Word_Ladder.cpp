/*
Question:
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

//Sol:1 52ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1;
		unordered_set<string> s2;
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if(!dict.count(endWord)) return 0;
		int len=beginWord.size();
		int ans=0;
		s1.insert(beginWord);
		s2.insert(endWord);
        
        while(!s1.empty() && !s2.empty())
        {
			ans++;
			if(s1.size()>s2.size()){
				swap(s1,s2);
			}
            unordered_set<string> cur;
            for(string w:s1)
            {
                for(int i=0;i<len;i++)
                {
                    char temp=w[i];
                    for(char x='a'; x <= 'z' ; x++)
                    {
                       w[i]=x;
                        if(s2.count(w))return ans+1;
                        if(!dict.count(w))continue;
                        dict.erase(w);
						cur.insert(w);
                    }
                    w[i]=temp;
                }
            }
            s1=cur;
       }
        return 0;
    }
};
