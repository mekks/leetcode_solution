/*
Question:
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

//Sol:1 468ms
/*
class Solution {
public:
     bool check(int f[],int k){
        for(int i=0;i<26;i++)
            if(f[i]!=0 && f[i]<k) return 0;
        return 1;
    }
    int longestSubstring(string s, int k) {      
        int ans{0};
        for(int i=0;i<s.length();i++){
             int f[26]={0};
            for(int j=i;j<s.length();j++){
                f[s[j]-'a']++; if(f[s[j]-'a']<k) continue;
                if(check(f,k)) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
*/

//Sol:2 232ms
class Solution {
public:
    int longestSubstring(string s, int k) {
        return divideAndConquer(0, s.length(), s, k);
    }
public:
    int divideAndConquer(int start, int end, string s, int k)
    {
        //store frequency of each character in string
        int charCount[26] = {0};
        for(int i = start; i < end; i++)
            charCount[s[i] - 'a']++;
        
        int flag = 1;
        
        //check if frequency of any character in string is less than k
        for(int i = 0; i < 26; i++)
            if(charCount[i] > 0 && charCount[i] < k)
                flag = 0;
        
        //if frequency of all characters is more than k, return length of string
        if(flag)
            return end - start;
        
        //split string at character whose frequency is less than k
        for(int i = start; i < end; i++)
        {
            int count = charCount[s[i] - 'a'];
            if(count > 0 && count < k)
            {
                int leftside = divideAndConquer(start, i, s, k);
                int rightside = divideAndConquer(i + 1, end, s, k);
                return max(leftside, rightside); //return max length from left and right substring
            }
        }
        return end - start; //return length of string
    }
};
