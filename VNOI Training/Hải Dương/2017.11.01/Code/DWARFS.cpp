#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 2e5 + 10;

int n, a, b;
int d[N], depth[N], f[N], g[N];
bool color[N];
vector <int> vx;
vector <int> adj[N];

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
        if (!color[v]) {
            d[u] = max(d[u], d[v] + 1);
        }
    }
    color[u] = ok || u == b;
    if (color[u]) {
        vx.push_back(u);
    }
    return color[u];
}

void process() {
    dfs(a, a);
   // for (int i = 0; i < sz(vx); ++i) cerr << vx[i] << "\n";
    for (int i = 0; i < sz(vx); ++i)
        f[i] = max(!i ? 0 : f[i - 1], d[vx[i]] + depth[b] - depth[vx[i]]);
    for (int i = sz(vx) - 1; i >= 0; --i)
        g[i] = max(i == sz(vx) - 1 ? 0 : g[i + 1], d[vx[i]] + depth[vx[i]] - depth[a]);
    int ans = 0;
    for (int i = 1; i < sz(vx); ++i)
        ans = max(ans, min(f[i - 1], g[i]) + 1);
    printf("%d\n", ans);
}

int main() {
    freopen("DWARFS.inp", "r", stdin);
    freopen("DWARFS.out", "w", stdout);

    load();
    process();

    return 0;
}
