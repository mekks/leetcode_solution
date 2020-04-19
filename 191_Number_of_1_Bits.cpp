/*
Question:
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).


Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

*/
//Solution_1 0ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
		for(int i=0;i<32;i++)	if(n>>i & 1) count++;
		return count;
    }
};
//Solution_2 4ms
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
    int count  = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
    }
};
*/

//Solution_3  4ms
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = bitset<32>(n).to_string();
        int count=0;
        for(int i =0; i<s.size(); i++)
        {
                if(s[i]== '1')
                    count++;
        }
        return count;
    }
};
*/
