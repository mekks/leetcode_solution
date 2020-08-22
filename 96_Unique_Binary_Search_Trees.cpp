/*
Question:
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


//Sol:1 0ms By formula
/*
class Solution {
public:
    int numTrees(int n) {
         double ans=1,i=2*n;
         for(int j=1;j<=n;j++,i--){
             ans*=(i/j);
              }
         return ans/(n+1);
     
    }
};

*/

//Sol:2 0ms Dynamic programing
class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n + 1);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
