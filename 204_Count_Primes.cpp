/*
Question:
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
//Solution:1  basic solution 
/*
class Solution {
private:
    bool isPrime(int n) {
        for (int i=2; i * i <= n; i++)
        { 
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int cnt=0;
        for (int i=2; i < n; i++) 
        {
            if (isPrime(i)) cnt++; 
        }
        return cnt;
    }
};
*/

//Sol:2
class Solution {

public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        bool res[n]; //array is faster than vector
        memset(res, true, sizeof(res)); 
        int counts = 2;
        for(int i = 2; i * i < n; i++){
            if(res[i]){
                int step = (i > 2) ? 2 * i : 2;  //trick:prime is odd,except 2.
                for(int j=i*i;j<n;j += step){ //odd+even=odd
                    if(res[j]){
                        res[j]=false;
                        counts++;
                    }
                }
            }
        }
        return n-counts;
    }
};
