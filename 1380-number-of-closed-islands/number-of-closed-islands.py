class Solution(object):
   
    def dfs(self,grid,r,c,rows,cols):
        # rows = len(grid)
        # cols = len(grid[0])

        if r<0 or r>=rows or c<0 or c>=cols:
            return False
        if grid[r][c]==1:
            return True

        grid[r][c] =1 

        up = self.dfs(grid,r-1,c,rows,cols)
        down = self.dfs(grid,r+1,c,rows,cols)
        right = self.dfs(grid,r,c+1,rows,cols)
        left = self.dfs(grid,r,c-1,rows,cols)

        return up and down and left and right 

    
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        count = 0

        for i in range(1,rows-1):
            for j in range(1,cols-1):
                if grid[i][j]==0:
                     if self.dfs(grid,i,j,rows,cols)==1:
                         count+=1
                    

        
        return count
        