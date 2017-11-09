#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, q;
int depth[N], root[22][N];
long long dist[N];
vector < pair <int, int> > adj[N];

void load() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}

void dfs(int u, int p) {
    root[0][u] = p;
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        dist[it.second] = dist[u] + it.first;
        depth[it.second] = depth[u] + 1;
        dfs(it.second, u);
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
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        int r = lca(u, v); //cerr << r << "\n";
        printf("%lld\n", dist[u] + dist[v] - 2 * dist[r]);
    }
}

int main() {
    freopen("MQUERY.inp", "r", stdin);
    freopen("MQUERY.out", "w", stdout);

    load();
    process();

    return 0;
}
