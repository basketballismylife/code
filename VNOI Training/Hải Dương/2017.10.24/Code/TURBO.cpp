#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int id[N], f[N], g[N];

void update(int t[], int x) {
    for (; x <= n; x += x & -x)
        t[x]++;
}

int get(int t[], int x) {
    int res = 0;
    for (; x > 0; x -= x & -x)
        res += t[x];
    return res;
}

int main() {
    freopen("TURBO.inp", "r", stdin);
    freopen("TURBO.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        id[x] = i;
    }

    for (int i = 1, l = 1, r = n; i <= n; ++i) {
        int j = (i & 1) ? l++ : r--;
        if (i & 1) {
            printf("%d\n", id[j] - get(f, id[j] - 1) - 1);
        } else {
            printf("%d\n", n - id[j] - get(g, n - id[j]));
        }
        //cerr << i << "\n";
        update(f, id[j]);
        update(g, n - id[j] + 1);
    }

    return 0;
}
