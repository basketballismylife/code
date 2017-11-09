#include <bits/stdc++.h>
using namespace std;

const int N = 444;

int n, m;
int a[N][N];

int get_sum(int x, int y, int u, int v) {
    return a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1];
}

int main() {
    freopen("AF10.inp", "r", stdin);
    freopen("AF10.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        scanf("%d", a[i] + j);
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    int ans = -1e9;
    for (int lo = 1; lo <= n; ++lo) for (int hi = lo; hi <= n; ++hi) {
        int mn = 0;
        for (int r = 1; r <= m; ++r) {
            int cur = get_sum(lo, 1, hi, r);
            ans = max(ans, cur - mn);
            mn = min(mn, cur);
        }
    }
    printf("%d\n", ans);

    return 0;
}
