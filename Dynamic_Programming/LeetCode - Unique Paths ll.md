```py
class Solution:
    def uniquePathsWithObstacles(self, mat: List[List[int]]) -> int:
        

        memo = {}
        n=len(mat)
        m=len(mat[0])

        if(mat[0][0] or mat[-1][-1]): return 0

        def UniquePathsII(i, j):
        
            if(i<0 or j<0 or mat[i][j]): return 0
            if((i, j) in memo): return memo[(i, j)]
            if(i==0 and j==0): return 1
            if(i==0): return UniquePathsII(i, j-1)
            if(j==0): return UniquePathsII(i-1, j)
            memo[(i, j)] = UniquePathsII(i-1, j) + UniquePathsII(i, j-1)
            return memo[(i, j)]

        return UniquePathsII(n-1, m-1)
