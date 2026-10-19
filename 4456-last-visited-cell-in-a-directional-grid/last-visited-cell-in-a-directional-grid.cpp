class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int row = 0;
        int col = 0;

       map<pair<int,int>, int> mp;
       mp[{row, col}] = 1;
          while(row<n && col<m && row>=0 && col >=0){

              if(grid[row][col]=='R'){
                if(mp[{row,col+1}]==1)
                {
                  return {row,col};
                }
                 
                else{
                    col = col + 1;
                    if(col>=m)return {row,col-1};
                    mp[{row,col}]=1;
                }

            }
           else if(grid[row][col]=='D'){
                if(mp[{row+1,col}]==1)
                {
                 return {row,col};
                } 
                else{
                    row = row + 1;
                    if(row>=n)return {row-1,col};
                    mp[{row,col}]=1;
                }
                


            }
         else if(grid[row][col]=='L'){
                if(mp[{row,col-1}]==1)
                {
                 return {row,col};
                }
                 
                else{
                   col = col - 1;
                   if(col<0)return{row,col+1};
                   mp[{row,col}]=1;
                }
                

            }
           else if(grid[row][col]=='U'){
                if(mp[{row-1,col}]==1)
                {
                  return {row,col};
                }
                 
                else{
                   row = row - 1;
                   if(row<0)return {row+1,col};
                   mp[{row,col}]=1;
                }

            }
       }
        return {row,col};
    }
};