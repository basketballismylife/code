#include <bits/stdc++.h>
using namespace std;

template <class T> T getBit(T x, T k) { return x >> (k - 1) & 1; }
template <class T> T onBit(T x, T k) { return x | (T(1) << (k - 1)); }
template <class T> T offBit(T x, T k) { return x ^ (T(1) << (k - 1)); }

const int N = 22;

int n, k;
int a[N][N];

void load() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
}

int getsum(int x, int y, int u, int v) { return a[u][v] - a[u][y - 1] - a[x - 1][v] + a[x - 1][y - 1]; }

bool ok(int mask, int r, int l, int w) {
    int j = 1;
    for (int i = 1; i < n; ++i) if (getBit(mask, i)) {
        if (getsum(j, l, i, r) > w) return 0;
        j = i + 1;
    }
    return getsum(j, l, n, r) <= w;
}

bool check(int w) {
    for (int x = 0; x < 1 << (n - 1); ++x) {
        int cnt = __builtin_popcount(x); bool can = 1;
        for (int i = 1, j = 1; i <= n; ++i) {
            if (!ok(x, i, j, w)) {
                if (i == j) {
                    can = 0;
                    break;
                }
                cnt++; j = i;
                if (!ok(x, i, j, w)) {
                    can = 0; break;
                }
            }
        }
        if (cnt <= k && can) return 1;
    }
    return 0;
}

void process() {
    int l = 0, r = 1e9 + 7, ans = 0;
    check(1219);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("PARTITION.inp", "r", stdin);
    freopen("PARTITION.out", "w", stdout);

    load();
    process();

    return 0;
}
