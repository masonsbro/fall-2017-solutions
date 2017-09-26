m, n = map(int, input().strip().split())
graph = [list(input().strip()) for _ in range(m)]
i, j = list(filter(lambda i: graph[i[0]][i[1]] == 'C', [(i, j) for j in range(n) for i in range(m)]))[0]
e = int(input().strip())
dirs = list(map(int, input().strip().split()))
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
seen = set([(i, j)])
while graph[i][j] != 'E':
    for t, (x, y) in enumerate(zip(dx, dy)):
        if 0 <= i + x < m and 0 <= j + y < n and (i + x, j + y) not in seen and graph[i + x][j + y] in 'E.':
            seen.add((i + x, j + y))
            e -= dirs[t]
            i, j = i + x, j + y
            break
print(max(e, -1))
