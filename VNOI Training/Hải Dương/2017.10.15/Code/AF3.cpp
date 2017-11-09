#include <bits/stdc++.h>
using namespace std;

#define id(i, j, k) i * n * r + j * r + k
const int N = 2e6 + 10;

int m, n, r;
int sum[N];

void load() {
    scanf("%d%d%d", &m, &n, &r);
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) for (int k = 1; k <= r; ++k) {
        scanf("%d", &sum[id(i, j, k)]);
        sum[id(i, j, k)] += sum[id(i - 1, j, k)] + sum[id(i, j - 1, k)] + sum[id(i, j, k - 1)]
                            - sum[id(i - 1, j - 1, k)] - sum[id(i - 1, j, k - 1)] - sum[id(i, j - 1, k - 1)]
                            + sum[id(i - 1, j - 1, k - 1)];
    }
}

void process() {
    int q; scanf("%d", &q);
    while (q--) {
        int i1, j1, k1, i2, j2, k2; scanf("%d%d%d%d%d%d", &i1, &j1, &k1, &i2, &j2, &k2);
        int ans = sum[id(i2, j2, k2)]
                    - sum[id(i1 - 1, j2, k2)] - sum[id(i2, j1 - 1, k2)] - sum[id(i2, j2, k1 - 1)]
                    + sum[id(i1 - 1, j1 - 1, k2)] + sum[id(i1 - 1, j2, k1 - 1)] + sum[id(i2, j1 - 1, k1 - 1)]
                    - sum[id(i1 - 1, j1 - 1, k1 - 1)];
        printf("%d\n", ans);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= r; ++k) cerr << sum[id(i, j, k)] << " ";
            cerr << "\n";
        }
        cerr << "\n";
    }
}

int main() {
    freopen("AF3.inp", "r", stdin);
    freopen("AF3.out", "w", stdout);

    load();
    process();

    return 0;
}
