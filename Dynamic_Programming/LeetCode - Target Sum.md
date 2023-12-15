```py
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        memo = {}

        def BT(i=0, sum=0):
            
            
            if(i>=len(nums)): return int(target == sum)
            
            key = (i, sum)
            
            if(key in memo): return memo[key]
            
            memo[key] = BT(i+1, sum + nums[i]) + BT(i+1, sum - nums[i])
            
            return memo[key]
        
        return BT()
     
    
