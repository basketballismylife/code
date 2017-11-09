#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
    int x, y, z;
    node() {}
    node(int x, int y, int z) : x(x), y(y), z(z) {}
};

int n;
int cnt[111][111][111], sum[3][111][111], s[3][111];
int x[N], y[N], z[N];

int main() {
    freopen("ONEIDX.inp", "r", stdin);
    freopen("ONEIDX.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        cnt[x[i]][y[i]][z[i]]++;
        sum[0][x[i]][y[i]]++;
        sum[1][x[i]][z[i]]++;
        sum[2][y[i]][z[i]]++;
        s[0][x[i]]++;  s[1][y[i]]++; s[2][z[i]]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += s[0][x[i]] - sum[0][x[i]][y[i]] - sum[1][x[i]][z[i]] + cnt[x[i]][y[i]][z[i]];
        ans += s[1][y[i]] - sum[0][x[i]][y[i]] - sum[2][y[i]][z[i]] + cnt[x[i]][y[i]][z[i]];
        ans += s[2][z[i]] - sum[1][x[i]][z[i]] - sum[2][y[i]][z[i]] + cnt[x[i]][y[i]][z[i]];
    }
    printf("%lld\n", ans / 2);

    return 0;
}
