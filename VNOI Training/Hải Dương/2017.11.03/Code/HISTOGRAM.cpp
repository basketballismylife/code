#include <bits/stdc++.h>
using namespace std;

template <class T> T getBit(T x, T k) { return x >> k & 1; }
template <class T> T onBit(T x, T k) { return x | (1 << k); }
template <class T> T offBit(T x, T k) { return x ^ (1 << k); }

const int N = 15;

int n;
int a[N], f[1 << N][N];
long long g[1 << N][N];

bool load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    return !!n;
}

void process()  {
    memset(f, 0, sizeof f); memset(g, 0, sizeof g);
    for (int i = 0; i < n; ++i) {
        f[1 << i][i] = a[i];
        g[1 << i][i] = 1;
    }
    for (int x = 1; x < 1 << n; ++x) for (int i = 0; i < n; ++i) if (getBit(x, i)) {
        for (int j = 0; j < n; ++j) if (getBit(offBit(x, i), j)) {
            if (f[x][i] < f[offBit(x, i)][j] + abs(a[i] - a[j])) {
                f[x][i] = f[offBit(x, i)][j] + abs(a[i] - a[j]);
                g[x][i] = g[offBit(x, i)][j];
            } else if (f[x][i] == f[offBit(x, i)][j] + abs(a[i] - a[j])) {
                g[x][i] += g[offBit(x, i)][j];
            }
        }
    }
    int w = 0; long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (w < f[(1 << n) - 1][i] + 2 * n + a[i]) {
            w = f[(1 << n) - 1][i] + 2 * n + a[i];
            cnt = g[(1 << n) - 1][i];
        } else if (w == f[(1 << n) - 1][i] + 2 * n + a[i]) {
            cnt += g[(1 << n) - 1][i];
        }
    }
    printf("%d %lld\n", w, cnt);
}

int main() {
    freopen("HISTOGRAM.inp", "r", stdin);
    freopen("HISTOGRAM.out", "w", stdout);

    while (load()) {
        process();
    }

    return 0;
}
