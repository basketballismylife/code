#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int n;
int c[N][N];
long long f[1 << 20], g[1 << 20];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) scanf("%d", &c[i][j]);
}

int getBit(int x, int k) { return x >> (k - 1) & 1; }
int offBit(int x, int k) { return x ^ (1 << (k - 1)); }

void process() {
    g[0] = 1;
    for (int x = 1; x < 1 << n; ++x) for (int i = 1; i <= n; ++i) if (getBit(x, i)) {
        if (f[x] < f[offBit(x, i)] + c[__builtin_popcount(x)][i]) {
            f[x] = f[offBit(x, i)] + c[__builtin_popcount(x)][i];
            g[x] = g[offBit(x, i)];
        } else if (f[x] == f[offBit(x, i)] + c[__builtin_popcount(x)][i]) {
            g[x] += g[offBit(x, i)];
        }
    }
    printf("%lld %lld\n", f[(1 << n) - 1], g[(1 << n) - 1]);
}

int main() {
    freopen("MARRIAGE.inp", "r", stdin);
    freopen("MARRIAGE.out", "w", stdout);

    load();
    process();

    return 0;
}
