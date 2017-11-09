#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], f[2][N], t[N], b[N];

void update(int x, int value) {
    for (; x < n; x += x & -x)
        t[x] = max(t[x], value);
}

int get(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x)
        res = max(res, t[x]);
    return res;
}

int main() {
    freopen("AD1.inp", "r", stdin);
    freopen("AD1.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;

    for (int i = 1; i <= n; ++i) {
        if (i == 1 || a[i] <= a[i - 1])
            f[0][i] = 1;
        else
            f[0][i] = f[0][i - 1] + 1;
        f[1][i] = get(a[i] - 1) + 1;
        if (a[i] > a[i - 1]) f[1][i] = max(f[1][i - 1] + 1, f[1][i]);
        update(a[i], f[0][i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max({ans, f[1][i], f[0][i]});
    printf("%d\n", ans);

    return 0;
}
