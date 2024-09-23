```py
def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    if n < 3: return -1
    ts = sum(arr)
    c = sum((i * n * 2) < ts for i in arr)
    if 2 * c > n: return 0
    arr.sort()
    ts = sum(arr)
    return arr[len(arr)//2] * n * 2 - ts + 1

def main():
    for _ in range(int(input())):
        print(solve())

if __name__ == "__main__":
    main()
