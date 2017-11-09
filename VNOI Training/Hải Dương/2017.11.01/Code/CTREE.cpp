#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e5 + 10;

int n;
int f[2][N], g[N];
vector <int> adj[N];

void load() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        if (f[0][v] + 1 > f[0][u]) {
            f[1][u] = f[0][u]; f[0][u] = f[0][v] + 1;
        } else if (f[0][v] + 1 > f[1][u]) {
            f[1][u] = f[0][v] + 1;
        }
    }
}

void dfs1(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        g[v] = max(g[v], g[u] + 1);
        if (f[0][v] + 1 == f[0][u]) {
            g[v] = max(g[v], f[1][u] + 1);
        } else {
            g[v] = max(g[v], f[0][u] + 1);
        }
        dfs1(v, u);
    }
}

void process() {
    dfs(1, 0);
    dfs1(1, 0);

    int w = 1e9 + 7;
    vector <int> ans;
    for (int i = 1; i <= n; ++i) {
        if (w > max(f[0][i], g[i])) {
            w = max(f[0][i], g[i]);
            ans.clear();
        }
        if (w == max(f[0][i], g[i]))
            ans.push_back(i);
    }
    printf("%d\n", sz(ans));
    for (int v : ans) printf("%d ", v);
}

int main() {
    freopen("CTREE.inp", "r", stdin);
    freopen("CTREE.out", "w", stdout);

    load();
    process();

    return 0;
}
