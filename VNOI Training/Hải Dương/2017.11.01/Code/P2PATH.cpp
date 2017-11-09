#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n;
int f[3][N], g[N], dp[2][N];
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
            f[2][u] = f[1][u]; f[1][u] = f[0][u]; f[0][u] = f[0][v] + 1;
        } else if (f[0][v] + 1 > f[1][u]) {
            f[2][u] = f[1][u]; f[1][u] = f[0][v] + 1;
        } else if (f[0][v] + 1 > f[2][u]) {
            f[2][u] = f[0][v] + 1;
        }

        dp[0][u] = max(dp[0][u], dp[0][v]);
    }
    dp[0][u] = max(dp[0][u], f[0][u] + f[1][u]);
}

void dfs1(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        g[v] = max(g[v], g[u] + 1);
        if (f[0][v] + 1 == f[0][u]) {
            g[v] = max(g[v], f[1][u] + 1);
        } else {
            g[v] = max(g[v], f[0][u] + 1);
        }

        dp[1][v] = max(dp[1][v], dp[1][u]);
        if (f[0][v] + 1 == f[0][u]) {
            dp[1][v] = max(dp[1][v], g[u] + f[1][u]);
        } else {
            dp[1][v] = max(dp[1][v], g[u] + f[0][u]);
        }
        if (f[0][v] + 1 == f[0][u]) {
            dp[1][v] = max(dp[1][v], f[1][u] + f[2][u]);
        } else if (f[0][v] + 1 == f[1][u]) {
            dp[1][v] = max(dp[1][v], f[0][u] + f[2][u]);
        } else {
            dp[1][v] = max(dp[1][v], f[0][u] + f[1][u]);
        }

        dfs1(v, u);
    }
}

void process() {
    dfs(1, 0);
    dfs1(1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, 1ll * dp[0][i] * dp[1][i]);
    printf("%lld\n", ans);
}

int main() {
    freopen("P2PATH.inp", "r", stdin);
    freopen("P2PATH.out", "w", stdout);

    load();
    process();

    return 0;
}
