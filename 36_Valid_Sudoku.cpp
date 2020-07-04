/*
Question:
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
    
*/
//Sol:1 52ms
bool grid(vector<vector<char>>& board, int r, int c)
{
    int map[10] = {0,};
    for(int i=r; i<r+3; i++)
    {
        for(int j=c; j<c+3; j++)
        {
            if(board[i][j] != '.')
                {
                    if(map[board[i][j] - '0'])
                        return false;

                    map[board[i][j] - '0']++;
                }
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
                    // checking entire rows and columns
        for(int i=0; i<9; i++)
        {
            int row[10] = {0,};
            int column[10] = {0,};
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(row[board[i][j] - '0'])
                        return false;

                    row[board[i][j] - '0']++;
                }
                
                if(board[j][i] != '.')
                {
                    if(column[board[j][i] - '0'])
                        return false;

                    column[board[j][i] - '0']++;
                }
                
            }
        }
        
                    // checking every 3X3 grid
        int row = 0;
        int column = 0;
        for(int i=0; i<9; i++)
        {
            if(i>0 && i%3==0)
            {
                column = 0;
                row += 3;
            }
            if(!grid(board,row,column))
                return false;
            column += 3;
        }
        return true;
    }
};
