/*
QUESTION:

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
            
        int m=haystack.size(),n=needle.size();
        if(needle.empty())return 0;
        else if(n>m) return -1;
        for(int i=0; i<= (m-n); i++)
        {   
            int j=0;
            for(;j<n ;j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if(j == n)return i;
        }
        return -1;
    }
};
