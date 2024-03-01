```py
dp = [[-1 for _ in range(61)] for _ in range(61)]
Case = 0

def trib(n, m):
    
    if(n <= 1): return 1
    if(dp[n][m] != -1): return dp[n][m]
    dp[n][m] = 1
    for i in range(1, m+1): dp[n][m] += trib(n-i, m)
    return dp[n][m]

while(1):
    
    Case += 1
    n, m = map(int, input().split())
    if(n > 60): break
    print(f"Case {Case}: {trib(n, m)}")
    
