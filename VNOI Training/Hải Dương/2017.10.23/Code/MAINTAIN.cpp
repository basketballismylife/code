#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, p;
long long t;
int root[22][N], depth[N];
vector <int> adj[N];

void load() {
    scanf("%d%d%lld", &n, &p, &t);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p) {
    root[0][u] = p;
    for (int v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    for (int k = 21; k >= 0; --k) if (depth[root[k][u]] >= depth[v])
        u = root[k][u];
    for (int k = 21; k >= 0; --k) if (depth[root[k][v]] >= depth[u])
        v = root[k][v];
    if (v == u) return u;
    for (int k = 21; k >= 0; --k) if (root[k][u] != root[k][v]) {
        u = root[k][u]; v = root[k][v];
    }
    return root[0][u];
}

void process() {
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i)
        root[j][i] = root[j - 1][root[j - 1][i]];
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        int r = lca(u, v);
        //cerr << depth[r] << " " << r << "\n";
        long long ans = depth[u] + depth[v] - 2 * depth[r];
        ans += 1ll * ((depth[u] - depth[r] - 1) / p + (depth[v] - depth[r] - 1) / p) * t;
        if (u != r && v != r) ans += t;
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("MAINTAIN.inp", "r", stdin);
    freopen("MAINTAIN.out", "w", stdout);

    load();
    process();

    return 0;
}
