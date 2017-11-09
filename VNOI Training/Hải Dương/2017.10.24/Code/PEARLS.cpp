#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N], c[N];
long long mn[N], mx[N], f[N], g[N];

void update(long long t[], int x, long long value) {
    for (; x > 0; x -= x & -x)
        t[x] = max(t[x], value);
}

long long get(long long t[], int x) {
    long long res = 0;
    for (; x < N; x += x & -x)
        res = max(res, t[x]);
    return res;
}

int main() {
    freopen("PEARLS.inp", "r", stdin);
    freopen("PEARLS.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[i] = a[i];
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);

    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(c + 1, c + n + 1, a[i]) - c;
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);

    for (int i = n; i >= 1; --i) {
        f[i] = get(mx, a[i] + 1) + b[i];
        g[i] = get(mn, n - a[i] + 2) + b[i];
        update(mx, a[i], f[i]);
        update(mn, n - a[i] + 1, g[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[i] + g[i] - b[i]);
      //  cerr << i << " " << b[i] << " " << f[i] << " " << g[i] << "\n";
    }
    printf("%lld\n", ans);

    return 0;
}
