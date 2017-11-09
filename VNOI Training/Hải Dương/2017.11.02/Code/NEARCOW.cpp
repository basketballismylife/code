#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int cow[N], f[N][22], g[N][22];
vector <int> adj[N];

void load() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &cow[i]);
}

void dfs(int u, int p) {
    f[u][0] = cow[u];
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        for (int i = 1; i <= k; ++i) f[u][i] += f[v][i - 1];
    }
}

void dfs1(int u, int p) {
    g[u][0] = cow[u];
    for (int v : adj[u]) if (v != p) {
        for (int i = 1; i <= k; ++i) {
            g[v][i] += g[u][i - 1];
            if (i > 1) g[v][i] += (f[u][i - 1] - f[v][i - 2]);
        }
        dfs1(v, u);
    }
}

void process() {
    dfs(1, 0);
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= k; ++j) {
        f[i][j] += f[i][j - 1]; g[i][j] += g[i][j - 1];
    }
    for (int i = 1; i <= n; ++i) printf("%d\n", f[i][k] + g[i][k] - cow[i]);
}

int main() {
    freopen("NEARCOW.inp", "r", stdin);
    freopen("NEARCOW.out", "w", stdout);

    load();
    process();

    return 0;
}
