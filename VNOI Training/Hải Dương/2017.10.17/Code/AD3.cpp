#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], f[N], g[N];

void update(int t[], int x, int value) {
    for (; x <= n; x += x & -x)
        t[x] = max(t[x], value);
}

int get(int t[], int x) {
    int res = -1e9;
    for (; x > 0; x -= x & -x)
        res = max(res, t[x]);
    return res;
}

int main() {
    freopen("AD3.inp", "r", stdin);
    freopen("AD3.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i) f[i] = g[i] = -1e9;
    for (int i = 1; i <= n; ++i) {
        update(f, i, a[i]);
        update(g, n - i + 1, a[i]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int t, u, v; scanf("%d", &t); scanf("%d", &u); if (t < 3) scanf("%d", &v);
        switch (t) {
        case 1:
            update(f, u, a[u] + v);
            update(g, n - u + 1, a[u] + v);
            break;
        case 2:
            update(f, u, v);
            update(g, n - u + 1, v);
            a[u] = v;
            break;
        case 3:
            printf("%d\n", get(f, u));
            break;
        case 4:
            printf("%d\n", get(g, n - u + 1));
            break;
        }
    }

    return 0;
}
