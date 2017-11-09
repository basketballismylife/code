#include <bits/stdc++.h>
using namespace std;

#define sz(c) (int) c.size()

const int N = 3e5 + 10;

int n, a, b;
int depth[N], d[N], f[N], g[N];
bool color[N], vis[N];
vector <int> c;
vector <int> adj[N];
stack <int> stt;

void load() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d%d", &a, &b);
}

bool dfs(int u, int p) {
    bool ok = 0;
    for (int v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        ok |= dfs(v, u);
        if (!color[v]) d[u] = max(d[u], d[v] + 1);
    }
    ok |= u == b;
    if (ok) c.push_back(u);
    color[u] = ok;
    return ok;
}

void process() {
    dfs(a, a);
    for (int i = 0; i < sz(c); ++i)
        f[i] = (!i) ? d[c[i]] : max(f[i - 1], d[c[i]] + depth[b] - depth[c[i]]);
    for (int i = sz(c) - 1; i >= 0; --i)
        g[i] = (i == sz(c) - 1) ? d[c[i]] : max(g[i + 1], d[c[i]] + depth[c[i]] - depth[a]);
    int ans = 0;
    for (int i = 0; i < sz(c) - 1; ++i)
        ans = max(ans, min(f[i], g[i + 1]) + 1);
    printf("%d\n", ans);
}

int main() {
    freopen("WEDDING.inp", "r", stdin);
    freopen("WEDDING.out", "w", stdout);

    load();
    process();

    return 0;
}
