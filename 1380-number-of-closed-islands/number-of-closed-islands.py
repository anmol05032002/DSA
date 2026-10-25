class Solution(object):
    rows = 0
    cols = 0
    def dfs(self,grid,r,c):
        # rows = len(grid)
        # cols = len(grid[0])

        if r<0 or r>=Solution.rows or c<0 or c>=Solution.cols:
            return False
        if grid[r][c]==1:
            return True

        grid[r][c] =1 

        up = self.dfs(grid,r-1,c)
        down = self.dfs(grid,r+1,c)
        right = self.dfs(grid,r,c+1)
        left = self.dfs(grid,r,c-1)

        return up and down and left and right 

    
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        Solution.rows = len(grid)
        Solution.cols = len(grid[0])
        count = 0

        for i in range(1,Solution.rows-1):
            for j in range(1,Solution.cols-1):
                if grid[i][j]==0:
                     if self.dfs(grid,i,j)==1:
                         count+=1
                    

        
        return count
        