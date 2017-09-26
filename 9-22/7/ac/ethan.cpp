#include <cstdio>
#include <utility>
#include <cmath>

constexpr int MAX_N = 50100;

constexpr double EPS = 1e-5;

using namespace std;

int t, n;
int x[MAX_N], y[MAX_N];

pair<double, double> vec(int i, int j) {
    return make_pair(x[j] - x[i], y[j] - y[i]);
}

pair<double, double> sub(pair<double, double> u, pair<double, double> v) {
    return make_pair(u.first - v.first, u.second - v.second);
}

pair<double, double> add(pair<double, double> u, pair<double, double> v) {
    return make_pair(u.first + v.first, u.second + v.second);
}

double dot(pair<double, double> u, pair<double, double> v) {
    return 1.0 * u.first * v.first + 1.0 * u.second * v.second;
}

pair<double, double> scale(pair<double, double> u, double s) {
    return make_pair(u.first * s, u.second * s);
}

double length(pair<double, double> ab) {
    return sqrt(dot(ab, ab));
}

double dist(pair<double, double> pt, pair<double, double> u, pair<double, double> v) {
    return length(sub(pt, add(u, scale(sub(v, u), dot(sub(v, u), sub(pt, u)) / dot(sub(v, u), sub(v, u))))));
}

bool is_parallel(pair<double, double> ab, pair<double, double> cd) {
    if (abs(cd.first) < EPS && abs(ab.first) < EPS) return true;
    return abs(ab.second / ab.first - cd.second / cd.first) < EPS;
}

bool is_bowl_valid() {
    pair<double, double> ab = vec(0, 1);
    pair<double, double> cd = vec(2, 3);

    return is_parallel(ab, cd);
}

long long cross2(int i, int j, int k) {
    pair<int, int> ab = vec(i, j);
    pair<int, int> bc = vec(j, k);

    long long prod = 1LL * ab.first * bc.second - 1LL * ab.second * bc.first;

    return prod;
}

int sign(int i, int j, int k) {
    if (cross2(i, j, k) < 0) return -1;
    if (cross2(i, j, k) > 0) return 1;
    return 0;
}

bool is_tail_valid() {
    int turn = sign(0, 4, 5);
    if (turn == 0) return false;
    for (int i = 4; i < n + 2; i++) {
        turn *= -1;
        if (sign(i, i + 1, i + 2) != turn) {
            return false;
        }
    }

    return true;
}

int aabs(int a) {
    return a < 0 ? -a : a;
}

bool is_bowl_big() {
    return aabs(cross2(0, 1, 2) + cross2(0, 2, 3)) >= 2000;
}

int main() {
    scanf(" %d", &t);
    for (int qq = 0; qq < t; qq++) {
        scanf(" %d", &n);
        for (int i = 0; i < n + 4; i++) {
            scanf(" %d %d", &x[i], &y[i]);
        }

        if (!is_bowl_valid() || !is_tail_valid()) {
            printf("Not a Dipper\n");
        } else {
            if (is_bowl_big()) {
                printf("Big Dipper\n");
            } else {
                printf("Little Dipper\n");
            }
        }
    }

    return 0;
}
