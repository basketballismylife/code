#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e5 + 10;

struct node {
    int u, v; long long w;
    node () {}
    node(int u, int v, long long w) : u(u), v(v), w(w) {}
    bool operator < (const node &p) const { return w < p.w; }
};

int n, m;
int par[N], root[22][N], depth[N];
long long mx[22][N];
bool mark[N];
vector < pair <long long, int> > adj[N];
vector <node> edges;

int anc(int p) { return par[p] == p ? p : par[p] = anc(par[p]); }
void join(int p, int q) { par[anc(p)] = anc(q); }

void dfs(int u, int p) {
    root[0][u] = p;
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        depth[it.second] = depth[u] + 1;
        mx[0][it.second] = it.first;
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

long long getmax(int r, int u) {
    long long res = -1e9;
    for (int k = 21; k >= 0; --k) if (depth[root[k][u]] >= depth[r]) {
        res = max(res, mx[k][u]);
        u = root[k][u];
    }
    return res;
}

int main() {
    freopen("MAXCYC.inp", "r", stdin);
    freopen("MAXCYC.out", "w", stdout);

    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v; long long w; scanf("%d%d%lld", &u, &v, &w);
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; ++i) par[i] = i;

    for (int i = sz(edges) - 1; i >= 0; --i) {
        int u = edges[i].u, v = edges[i].v; long long w = edges[i].w;
        if (anc(u) != anc(v)) {
            join(u, v);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
            mark[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) if (!depth[i]) {
        dfs(i, i);
    }
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i) {
        root[j][i] = root[j - 1][root[j - 1][i]];
        mx[j][i] = max(mx[j - 1][i], mx[j - 1][root[j - 1][i]]);
    }

    long long ans = 0;
    for (int i = 0; i < sz(edges); ++i) if (!mark[i]) {
        int u = edges[i].u, v = edges[i].v; long long w = edges[i].w;
        int r = lca(u, v);
        long long mxe = max(getmax(r, u), getmax(r, v));
        ans = max(ans, mxe + w);
    }
    printf("%d\n", ans);

    return 0;
}
