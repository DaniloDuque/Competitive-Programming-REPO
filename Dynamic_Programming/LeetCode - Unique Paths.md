```py
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        memo = {}



        def UniquePaths(i, j):
            
            
            if(i==1 or j==1): return 1
            
            key = (i, j)
            
            if(key in memo): return memo[key]
            
            memo[key] = UniquePaths(i-1, j) + UniquePaths(i, j-1)
            
            return memo[key]


        return UniquePaths(n, m)
