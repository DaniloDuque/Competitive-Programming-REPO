```py
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        

        memo = [1<<30]*(amount+1)
        memo[0] = 0

        def CoinChange(n, coins):

            for i in range(1, n+1):
                for c in coins:
                    if(i-c >= 0):
                        memo[i] = min(memo[i], 1+memo[i-c])
            
            if(memo[n] != 1<<30):return memo[n]
            return -1


        return(CoinChange(amount, coins))
