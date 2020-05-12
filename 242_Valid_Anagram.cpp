/*
Question:
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

// Sol_1 12 ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        
        int counts[26]={0};
        for(int i=0; i< s.length();i++)
        {
            counts[s[i]- 'a']++;
            counts[t[i]- 'a']--;
        }
        for(int i=0; i<26 ;i++)
        {
            if (counts[i]) return false;
        }
        return true;
    }
};

// Sol_2  28ms  map solution
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
   unordered_map<char,int> lettersStore;
        if(s.length()!=t.length()) return false;
        for(int i=0; i<s.length(); i++)
        {
            lettersStore[s[i]]++;
        }
        for(int i=0; i<t.length(); i++)
        {
           lettersStore[t[i]]--;
           if(lettersStore[t[i]] < 0)
           {
               return false;
           }
        }
        return true;
    }
};
*/
//Sol_3 72 ms sorting solution
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
   //Rearrange the strings in alphabetical order
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
		//Strings will be the same if they are anagrams
        return s == t;
    }
};
*/
