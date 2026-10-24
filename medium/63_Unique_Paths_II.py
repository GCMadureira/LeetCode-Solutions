# standard dynamic programming solution
# 0ms

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = 1 # assume the top left cell cannot be an obstacle

        # fill the first line
        for i in range(1, n):
            if obstacleGrid[0][i] == 0:
                dp[0][i] = 1
            else:
                break
        
        # fill the first col
        for i in range(1, m):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = 1
            else:
                break

        for line in range(1, m):
            for col in range(1, n):
                if obstacleGrid[line][col] == 0:
                    dp[line][col] = dp[line - 1][col] + dp[line][col - 1]

        return dp[m - 1][n - 1]
