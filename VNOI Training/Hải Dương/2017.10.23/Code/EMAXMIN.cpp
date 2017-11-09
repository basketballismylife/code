#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int depth[N], root[22][N], mn[22][N], mx[22][N];
vector < pair <int, int> > adj[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
}

void dfs(int u, int p) {
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        mn[0][it.second] = mx[0][it.second] = it.first;
        root[0][it.second] = u; depth[it.second] = depth[u] + 1;
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

int getmin(int r, int u) {
    int res = 1e9;
    for (int k = 21; k >= 0; --k) if (depth[root[k][u]] >= depth[r]) {
        res = min(res, mn[k][u]);
        u = root[k][u];
    }
    return res;
}

int getmax(int r, int u) {
    int res = -1e9;
    for (int k = 21; k >= 0; --k) if (depth[root[k][u]] >= depth[r]) {
        res = max(res, mx[k][u]);
        u = root[k][u];
    }
    return res;
}

void process() {
    mn[0][1] = 1e9; mx[0][1] = -1e9; root[0][1] = 1;
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i) {
        root[j][i] = root[j - 1][root[j - 1][i]];
        mn[j][i] = min(mn[j - 1][i], mn[j - 1][root[j - 1][i]]);
        mx[j][i] = max(mx[j - 1][i], mx[j - 1][root[j - 1][i]]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        int r = lca(u, v);
        int mne = min(getmin(r, u), getmin(r, v));
        int mxe = max(getmax(r, u), getmax(r, v));
        printf("%d %d\n", mne, mxe);
    }
}

int main() {
    freopen("EMAXMIN.inp", "r", stdin);
    freopen("EMAXMIN.out", "w", stdout);

    load();
    process();

    return 0;
}
