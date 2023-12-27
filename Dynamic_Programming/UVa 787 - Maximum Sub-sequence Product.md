```py
import sys

nums = []

def maxProduct():

    rslt = Max = Min = nums[0]
    
    for i in nums[1:]:
        
        auxMax = Max*i
        auxMin = Min*i
        Max = max(i, max(auxMax, auxMin))
        Min = min(i, min(auxMax, auxMin))
        rslt = max(Max, rslt)
        
    return rslt


for line in sys.stdin:
    
    nums = list(map(int, line.split()))
    nums.pop()
    print(maxProduct())
