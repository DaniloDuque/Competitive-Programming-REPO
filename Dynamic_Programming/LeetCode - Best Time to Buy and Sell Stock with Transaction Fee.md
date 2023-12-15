```py
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        

        memo = {}
        n=len(prices)
        def BestTimeFee(i, buy=True):
            
            if(i==n): return 0
            
            key = (i, buy)
            
            if(key in memo): return memo[key]
            
            if(buy): 
                
                memo[key] = max(BestTimeFee(i, False)-prices[i], BestTimeFee(i+1, buy))
            
            else:
                memo[key] = max(BestTimeFee(i+1, True)+prices[i]-fee, BestTimeFee(i+1, buy))
                
            return memo[key]

        return BestTimeFee(0)
