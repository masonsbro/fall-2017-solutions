t = int(raw_input())
for qq in range(t):
    n, k = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    cur = [None] * n
    best = [None] * n
    for i in range(k):
        cur[i] = arr[i]
        best[i] = cur[i]
        if i > 0:
            best[i] = max(best[i], best[i - 1])
    for i in range(k, n):
        cur[i] = arr[i] + best[i - k]
        best[i] = max(cur[i], best[i - 1])
    print best[-1]
