class Solution {
public:
    int rows, cols;

    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;
        long long sum=grid[r][c];
        grid[r][c]=0;
        long long up = dfs(grid, r - 1, c);
        long long down = dfs(grid, r + 1, c);
        long long left = dfs(grid, r, c - 1);
        long long right = dfs(grid, r, c + 1);
        return sum+up + down + left + right;
    }

    int countIslands(vector<vector<int>>& grid,int k) {
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != 0) {
                    if (dfs(grid, r, c)%k==0){
                        count++;
                    }      
                }
            }
        }
        return count;
    }
};



