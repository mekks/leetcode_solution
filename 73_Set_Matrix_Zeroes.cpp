/*
Question:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

*/
//Sol:1 32 ms
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize=matrix.size(); 
        int columnsize=matrix[0].size(); 
        vector<int>rowmarker(rowsize,1);
        vector<int>columnmarker(columnsize,1); 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowmarker[i]=0; 
                    columnmarker[j]=0;
                }
            }
        } 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(rowmarker[i]==0 or columnmarker[j]==0)
                    matrix[i][j]=0;
             }
        }
    }
};
