#include <bits/stdc++.h>
using namespace std;

const int N = 333;

int n, m, k;
long long w[N][N], d[N][N];
bool on[N];

void load() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        w[i][j] = (i != j) * (1e18);
    }
    while (m--) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        w[u][v] = min(w[u][v], 1ll * c);
    }
}

void process() {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
        d[i][j] = w[i][j];
    while (k--) {
        char s[2]; int u, v; scanf("%s", s);
        if (s[0] == 'X') {
            scanf("%d", &u);
            if (!on[u]) {
                for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
                    d[i][j] = min(d[i][j], d[i][u] + d[u][j]);
                on[u] = 1;
            }
        } else {
            scanf("%d%d", &u, &v);
            if (on[u] && on[v] && d[u][v] < 1e18) {
                printf("%d\n", d[u][v]);
            } else {
                puts("-1");
            }
        }
    }
}

int main() {
    freopen("DWLABYR.inp", "r", stdin);
    freopen("DWLABYR.out", "w", stdout);

    load();
    process();

    return 0;
}
