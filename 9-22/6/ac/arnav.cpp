#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int MAXN = 100005;
int n, k;
int a[MAXN];
ll dp[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        ll ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            int next_ind = i + k;
            ll next_val = next_ind < n ? dp[next_ind] : 0;

            dp[i] = a[i] + next_val;
            ans = max(ans, dp[i]);

            if (i < n - 1)
                dp[i] = max(dp[i], dp[i + 1]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
