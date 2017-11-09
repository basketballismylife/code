#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], w[6];
long long f[6][N];

void load() {
    scanf("%d%d%d", &n, &w[1], &w[2]);
    w[3] = 1; w[4] = w[2]; w[5] = w[1];
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}

void process() {
    for (int i = 1; i <= 5; ++i) for (int j = 0; j <= n; ++j) f[i][j] = -1e18;
    for (int id = 1; id <= 5; ++id) for (int i = 1 + id - 1; i <= n; ++i) {
        f[id][i] = max(f[id][i - 1], f[id - 1][i - 1] + 1ll * w[id] * a[i]);
       // cerr << id << " " << i << " " << f[id][i] << "\n";
    }
    printf("%lld\n", f[5][n]);
}

int main() {
    freopen("FIVESET.inp", "r", stdin);
    freopen("FIVESET.out", "w", stdout);

    load();
    process();

    return 0;
}
