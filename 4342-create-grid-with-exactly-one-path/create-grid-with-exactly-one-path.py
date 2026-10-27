class Solution(object):
    def createGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: List[str]
        """

        

        grid = [['#' for j in range(n)] for i in range(m)]


        for i in range(0,n):
            grid[0][i] = '.'

        for j in range(0,m):
            grid[j][n-1] = '.'   

        ans = []
        for row in grid:
            ans.append(''.join(row))

        return ans    


        