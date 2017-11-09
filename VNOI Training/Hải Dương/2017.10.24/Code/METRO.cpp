#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int depth[N], root[22][N];
vector <int> adj[N];

void load() {
    scanf("%d%d", &n, &m);
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
    if (u == v) return u;
    for (int k = 21; k >= 0; --k) if (root[k][u] != root[k][v]) {
        u = root[k][u]; v = root[k][v];
    }
    return root[0][u];
}

void process() {
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i)
        root[j][i] = root[j - 1][root[j - 1][i]];

    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        int r = lca(u, v);
        if (r != u) {
            r = root[0][u];
        } else {
            for (int k = 21; k >= 0; --k) if (depth[root[k][v]] > depth[u])
                v = root[k][v];
            r = v;
        }
        printf("%d\n", r);
    }
}

int main() {
    freopen("METRO.inp", "r", stdin);
    freopen("METRO.out", "w", stdout);

    load();
    process();

    return 0;
}
