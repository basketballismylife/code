#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
long long a[N], t[N];

void update(int x, long long value) {
    for (; x < N; x += x & -x)
        t[x] += value;
}

long long get(int x) {
    long long res = 0;
    for (; x > 0; x -= x & -x)
        res += t[x];
    return res;
}

int main() {
    freopen("AD2.inp", "r", stdin);
    freopen("AD2.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        update(i, a[i]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int t, u; long long v; scanf("%d%d%lld", &t, &u, &v);
        if (t == 1) {
            update(u, v);
            a[u] += v;
        } else if (t == 2) {
            update(u, v - a[u]);
            a[u] = v;
        } else {
            printf("%lld\n", get(v) - get(u - 1));
        }
    }

    return 0;
}
