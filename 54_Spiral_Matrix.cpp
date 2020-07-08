/*
Question:
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/
//Sol:1 4ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        if(n==0) return ans;
        int r1=0,r2=n-1;
        int c1=0,c2=matrix[0].size()-1;
        while(r1<=r2&&c1<=c2)
        {
            for(int c=c1;c<=c2;c++) // upper layer
            {
                ans.push_back(matrix[r1][c]);
            }
            for(int r=r1+1;r<=r2;r++)  //side layer
            {
                ans.push_back(matrix[r][c2]);
            }
            if(r1<r2 && c1<c2)
            {
                for(int c=c2-1;c>c1;c--) //down layer wrapping up to row start
                {
                    ans.push_back(matrix[r2][c]);
                }
                for(int r=r2;r>r1;r--) 
                {
                    ans.push_back(matrix[r][c1]);
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};
