```py
for _ in range(int(input())):
    n = int(input())
    n >>= 1
    print(((n*(n+1)*(2*n + 1))//6)*8)
            
