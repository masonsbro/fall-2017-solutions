#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll n;
    scanf("%lld", &n);
    ll ans = 0LL;
    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
