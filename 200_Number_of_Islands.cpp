/*
Question:
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/


//Sol:1 28ms
class Solution {
public:
    int r,c;
    int no_of_lan=0;
    
    void markCurr(vector<vector<char>>& grid , int x,int y)
    {
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y] != '1')return ;
        grid[x][y]='2';
        // check for connecting adjacent horizontally and vertically
        
        markCurr(grid,x+1,y);
        markCurr(grid,x-1,y);
        markCurr(grid,x,y+1);
        markCurr(grid,x,y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        if(r==0)return 0;
        c=grid[0].size();
        
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                if(grid[i][j]=='1')
                {
                    markCurr(grid,i,j);
                    no_of_lan++;
                }
            }
        }
        return no_of_lan;
    }
};
