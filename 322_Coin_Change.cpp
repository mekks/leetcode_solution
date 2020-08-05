/*
Question:
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
*/

//Sol:1 240ms
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int j = 1; j <= amount; j++){
            for(int i = 0; i < coins.size(); i++){
                if(coins[i] <= j){
                    if(dp[j - coins[i]] == -1) continue;
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
                }
            }
            if(dp[j] == INT_MAX) dp[j] = -1;
        }
        return dp[amount];
    }
};
*/

//Sol:2 116ms
class Solution {
public:
    int coinChange(vector<int>& coins, int val) {
    int dp[val+1];
    dp[0]=0;
    
    for(int i=1;i<=val;i++)
    {
        dp[i]=INT_MAX;
    }
    
    for(int i=1;i<=val;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(coins[j]<=i)
            {
                int sub_res = dp[i-coins[j]];
                if(sub_res!=INT_MAX)
                {
                    dp[i] = min(dp[i],sub_res+1);
                }
            }
        }
    }
    return dp[val]==INT_MAX?-1:dp[val];
    }
};
