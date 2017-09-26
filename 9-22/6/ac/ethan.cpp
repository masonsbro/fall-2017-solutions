#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100100;

using namespace std;

int t, n, k;
int arr[MAX_N];
int cur[MAX_N];
int best[MAX_N];

int main() {
    scanf(" %d", &t);
    for (int qq = 0; qq < t; qq++) {
        scanf(" %d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &arr[i]);
        }

        cur[0] = 0;
        best[0] = 0;
        for (int i = 1; i <= n; i++) {
            cur[i] = arr[i];
            if (i > k) {
                cur[i] += best[i - k];
            }
            best[i] = max(cur[i], best[i - 1]);
        }

        printf("%d\n", best[n]);
    }

    return 0;
}
