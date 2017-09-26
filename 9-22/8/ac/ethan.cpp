#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 100100;
constexpr int MAX_SALARY = 100100;

constexpr int MOD = 1000000007;

using namespace std;

int n, k, d;
int age[MAX_N];
int salary[MAX_N];

vector<int> young;
vector<int> old;

int tree[8 * MAX_SALARY];

int query(int i, int l, int r, int a, int b) {
    if (r < l) return 0;
    if (r < a || b < l) return 0;
    if (l >= a && r <= b) return tree[i];
    return query(2 * i + 1, l, (l + r) / 2, a, b) + query(2 * i + 2, (l + r) / 2 + 1, r, a, b);
}

int query(int a, int b) {
    return query(0, 0, MAX_SALARY, a, b);
}

int update(int i, int l, int r, int j, int v) {
    if (r < l) return 0;
    if (j < l || j > r) return tree[i];
    if (l == r) {
        tree[i] += v;
    } else {
        tree[i] = update(2 * i + 1, l, (l + r) / 2, j, v) + update(2 * i + 2, (l + r) / 2 + 1, r, j, v);
    }
    return tree[i];
}

void remove_idx(int i) {
    update(0, 0, MAX_SALARY, salary[i], -1);
}

void add_idx(int i) {
    update(0, 0, MAX_SALARY, salary[i], 1);
}

int solve(const vector<int> &idxs) {
    memset(tree, 0, sizeof(tree));

    int ans = 0;
    int i = 0;
    for (int j = 0; j < idxs.size(); j++) {
        while (i < j && age[idxs[i]] < (age[idxs[j]] / 2) - k) {
            remove_idx(idxs[i++]);
        }
        ans = (ans + query(salary[idxs[j]] - d, salary[idxs[j]] + d)) % MOD;
        add_idx(idxs[j]);
    }

    return ans;
}

bool compare_idx(int i, int j) {
    return age[i] < age[j];
}

int main() {
    scanf(" %d %d %d", &n, &k, &d);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &age[i], &salary[i]);
        if (12000 <= age[i] && age[i] < 18000) {
            young.push_back(i);
        } else if (12000 <= age[i]) {
            old.push_back(i);
        }
    }

    sort(young.begin(), young.end(), compare_idx);
    sort(old.begin(), old.end(), compare_idx);

    int ans1 = solve(young);
    int ans2 = solve(old);

    printf("%d\n", (ans1 + ans2) % MOD);

    return 0;
}
