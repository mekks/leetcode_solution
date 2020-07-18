/*
Question:
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

//Sol:1 216ms
/*
class Solution {
public:
    int numSquares(int n) {
	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;
        //dynamic programing solution
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], 1 + dp[i-j*j]);
		}
	}
	return dp[n];
    }
};
*/


//Sol:2 20ms
class Solution {
public:
    int numSquares(int n) {
    //using Lagrange's four-square theorem, also known as Bachet's conjecture, states that every natural 
	//number can be represented as the sum of four integer squares. 

		vector<int> sqr;
		int x=1;
		while(x*x<=n){ //saving all squares till n
			sqr.push_back(x*x);
			x++;
		}
		int size= sqr.size();

		for(int i=0; i<size; i++){ //for one
			if(sqr[i]==n)
				return 1;
		}

		for(int i=0; i<size; i++){
			for(int j=i; j<size; j++){ //for two
				if(sqr[i]+sqr[j]==n)
					return 2;
			}
		}

		for(int i=0; i<size; i++){ //for three
			for(int j=i; j<size; j++){
				for(int k=j; k<size; k++){
					if(sqr[i]+sqr[j]+sqr[k]==n)
						return 3;
				}
			}
		}

		return 4;
    }
};
