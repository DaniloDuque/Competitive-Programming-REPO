```py


def decodeWays(s, i, length, memo):
        
    if(i >= length): return 1

    if(s[i] == '0'): return 0
    
    if(i in memo): return memo[i]
    
    memo[i] = decodeWays(s, i+1, length, memo)
    
    if((s[i] == '1' or s[i] == '2') and i < length-1):
        
        if(s[i] == '1' or (s[i] == '2' and s[i+1] in "0123456")):
            
            memo[i] += decodeWays(s, i+2, length, memo)
            
    return memo[i]


            
    


class Solution:
    def numDecodings(self, word: str) -> int:

        return decodeWays(word, 0, len(word), {})
        
