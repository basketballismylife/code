#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 7
const int N = 222;

int n, m, k, kt;
int a[N][N];
int kc[N], pre[N], cl[N], d[N], x[N], y[N], preL[N];

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
        a[i][j] *= -1;
    }
    scanf("%d", &k);
}

bool findPath() {
    for (int i = 0; i <= n; ++i) cl[i] = 0, kc[i] = INF;
    queue <int> q;
    for (int u = 1; u <= n; ++u) if (x[u] == 0) {
        kc[u] = 0; pre[u] = 0; cl[u] = 1;
        q.push(u);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cl[u] = 0;
        for (int v = 1; v <= m; ++v) {
            int L = a[u][v];
            int w = y[v];
            if (kc[w] > kc[u] + L - d[w]) {
                kc[w] = kc[u] + L - d[w];
                pre[w] = u;
                preL[w] = L;
                if (w == 0) kt = v;
                else if (cl[w] == 0) {
                    cl[w] = 1;
                    q.push(w);
                }
            }
        }
    }
    return kc[0] < INF;
}

void incFlow() {
    int u = pre[0], v = kt, L = preL[0];
    while (u) {
        int v1 = x[u], L1 = preL[u];
        x[u] = v; y[v] = u;
        d[u] = L;
        u = pre[u]; v = v1; L = L1;
    }
}

void process() {
    for (int i = 1; i <= k; ++i) if (findPath()){
        incFlow();
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (x[i]) ans -= a[i][x[i]];
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        if (x[i]) printf("%d %d\n", i, x[i]);
}

int main() {
    freopen("ATHLETE.inp", "r", stdin);
    freopen("ATHLETE.out", "w", stdout);

    load();
    process();

    return 0;
}
