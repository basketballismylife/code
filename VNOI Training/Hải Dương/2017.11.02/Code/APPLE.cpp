#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 111;

int n, q;
int dp[N][N], sz[N];
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
    int v0 = 0, v1 = 0, w0, w1;
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        dfs(it.second, u);
        if (!v0) {
            v0 = it.second; w0 = it.first;
        } else {
            v1 = it.second; w1 = it.first;
        }
    }
    if (!v0 || !v1) return;
    for (int i = 1; i < n; ++i) {
        if (i > 1) {
            int cur = 0;
            for (int j = 0; j < n; ++j) if (i - j - 2 >= 0)
                cur = max(cur, dp[v0][j] + dp[v1][i - j - 2]);
            dp[u][i] = max(dp[u][i], w0 + w1 + cur);
        }
        dp[u][i] = max(dp[u][i], dp[v0][i - 1] + w0);
        dp[u][i] = max(dp[u][i], dp[v1][i - 1] + w1);
    }
}

void process() {
    dfs(1, 0);
    printf("%d\n", dp[1][q]);
}

int main() {
    freopen("APPLE.inp", "r", stdin);
    freopen("APPLE.out", "w", stdout);

    load();
    process();

    return 0;
}
