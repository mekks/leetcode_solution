/*
Question:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

//Sol:1 1324ms
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
        if(matrix[i].size()!=0&&target<matrix[i][0]&&target<matrix[i][matrix[i].size()-1])
             return 0;
        
            
        auto id=lower_bound(matrix[i].begin(),matrix[i].end(),target);
            if(id!=matrix[i].end()&&*id==target)
                return 1;
        }
        
        return 0;
    }
};
*/

//Sol:2 124ms
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return false;
        int M=matrix.size() , N=matrix[0].size();
        int row=M-1 , col=0;
        
        while(row>= 0 && col < N)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col] > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};
