/*
Question:
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

//Sol_1 8ms
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> res;
	    for(int i = 1; i <= n; i++) 
            res.push_back(i % 5 ? (i % 3 ? to_string(i) : "Fizz") : (i % 3 ? "Buzz" : "FizzBuzz"));
        return res;
    }
};
