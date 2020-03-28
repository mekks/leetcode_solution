/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vt(numRows, vector<int> (1,1));//vector initialization with first row initialize with number 1
        if(numRows == 0)return vt;
        vector<int> prevRow;
        for(int i=1; i<numRows; i++)
        {
            prevRow = vt[i-1];
            for(int j=1; j<i; j++)
            {
                vt[i].push_back(prevRow[j]+prevRow[j-1]);
            }
            vt[i].push_back(1);
        }
        return vt;
    }
};
