m, n = map(int, raw_input().split())
grid = [raw_input() for i in range(m)]
e = int(raw_input())
de = map(int, raw_input().split())
dxy = [(-1, 0), (1, 0), (0, -1), (0, 1)]

start = None
for i in range(m):
    for j in range(n):
        if grid[i][j] == 'C':
            start = (i, j, e)

to_visit = [start]
visited = [[False] * n for i in range(m)]

while len(to_visit) > 0:
    x, y, e = to_visit.pop()
    if x < 0 or y < 0 or x >= m or y >= n:
        continue
    if visited[x][y]:
        continue
    visited[x][y] = True
    if grid[x][y] == 'X':
        continue
    if grid[x][y] == 'E':
        if e < 0:
            print -1
        else:
            print e
        break
    for i in range(4):
        nx = x + dxy[i][0]
        ny = y + dxy[i][1]
        ne = e - de[i]
        to_visit.append((nx, ny, ne))
