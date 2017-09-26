#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 52;
int n, m;
char grid[MAXN][MAXN];
bool visit[MAXN][MAXN];
int sx, sy;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int costs[4];

int solve() {
    queue<tuple<int, int, int> > q;
    visit[sx][sy] = true;
    q.push({0, sx, sy});

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        int cost = get<0>(pos);
        int x = get<1>(pos);
        int y = get<2>(pos);
        
        if (grid[x][y] == 'E') {
            return cost;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 and ny >= 0 and nx < n and ny < m
                and grid[x][y] != 'X' and !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({cost + costs[d], nx, ny});
            }
        }
    }
    
    return 987654321;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'C') {
                sx = i; sy = j;
            }
        }
    }
    
    int energy;
    scanf("%d", &energy);
    scanf("%d %d %d %d", costs + 2, costs, costs + 3, costs + 1);
    int cost = solve();
    
    if (cost > energy) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", energy - cost);
    }
    
    return 0;
}
