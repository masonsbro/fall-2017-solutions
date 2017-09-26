#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 100005;
constexpr int MOD = 1e9 + 7;
int n, k, d;
int age[MAXN], salary[MAXN];

inline bool safe_ages(const int& a, const int& b) {
    if (a < 12000 or b < 12000) {
        return false;
    }

    if ((a < 18000) ^ (b < 18000)) {
        return false;
    }

    return min(a, b) >= (max(a, b) / 2) - k;
}


inline bool safe_salary(const int& a, const int& b) {
    return abs(a - b) <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    scanf(" %d %d %d", &n, &k, &d);

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", age + i, salary + i);
        for (int j = 0; j < i; ++j) {
            if (safe_ages(age[i], age[j]) and safe_salary(salary[i], salary[j])) {
                ++ans;
            }
        }
    }

    printf("%lld\n", ans % MOD);

    return 0;
}
