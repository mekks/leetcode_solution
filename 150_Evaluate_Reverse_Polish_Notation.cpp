/*
Question:

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


//Sol:1 36 ms
/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     //stack solution
     stack<int>s;
     for(auto x:tokens){
       int len=x.length();
       char c=x[0]; char c1= x[1];
       if( len==1 && (!isdigit(c))){//true when operator is detect
           int f=s.top(); s.pop();
           int se=s.top(); s.pop(); 
           if(c=='+') se=se+f;
           if(c=='-') se=se-f;
           if(c=='*') se=se*f;
           if(c=='/') se=se/f; 
           s.push(se);
       }
       else{
       int i=stoi(x);
       s.push(i);
       }
    }        
        return s.top();
    }
};
*/


//Sol:2  36 ms
/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     //stack solution with map
    unordered_set<string> ops = {"+", "-", "*", "/"};
  	stack<int> stk;
	for(string &t : tokens) {
		if(ops.count(t)) {
			int a = stk.top(); stk.pop();
			int b = stk.top(); stk.pop();
			stk.push(t == "+" ? b + a : t == "-" ? b - a : t == "*" ? b * a : b / a);
		} else stk.push(stoi(t));
	}
	return stk.top();
    }
};
*/

//Sol:3 24ms
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     //stack solution with map
         stack <int> s;
        for(auto t: tokens)
        {
            if(t=="+"||t=="*"||t=="-"||t=="/")
            {
                int x=s.top(); 
                s.pop();
                int y=s.top();
                s.pop();
                switch(t.front())
                {
                    case '+':
                        y=y+x;
                        break;
                    case '-':
                        y=y-x;
                        break;
                    case '*':
                        y=y*x;
                        break;
                    case '/':
                        y=y/x;
                        break;
                }
                s.push(y);
            }
            else
                s.push(stoi(t));
        }
        return s.top();
    }
};
