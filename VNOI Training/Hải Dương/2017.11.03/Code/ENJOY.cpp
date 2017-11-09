#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int n, m, k;
int a[N], c[N][N];
long long f[1 << 18][22];

void load() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while (k--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        c[u][v] += w;
    }
}

int getBit(int x, int k) { return x >> (k - 1) & 1; }
int onBit(int x, int k) { return x | (1 << (k - 1)); }
int offBit(int x, int k) { return x ^ (1 << (k - 1)); }

void process() {
    for (int i = 0; i < 1 << n; ++i) for (int j = 1; j <= n; ++j) f[i][j] = -1e18;
    for (int i = 0; i < n; ++i)
        f[1 << i][i + 1] = a[i + 1];
    long long ans = 0;
    for (int x = 0; x < 1 << n; ++x) for (int i = 1; i <= n; ++i) if (f[x][i] != -1e18) {
        for (int j = 1; j <= n; ++j) if (!getBit(x, j))
            f[onBit(x, j)][j] = max(f[onBit(x, j)][j], f[x][i] + a[j] + c[i][j]);
       // cerr << x << " " << i << " " << f[x][i] << "\n";
    }
    for (int x = 0; x < 1 << n; ++x) for (int i = 1; i <= n; ++i) if (__builtin_popcount(x) == m)
        ans = max(ans, f[x][i]);
    printf("%lld\n", ans);
}

int main() {
    freopen("ENJOY.inp", "r", stdin);
    freopen("ENJOY.out", "w", stdout);

    load();
    process();

    return 0;
}
