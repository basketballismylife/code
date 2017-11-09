#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 5e4 + 10;

int n;
int f[N][2];
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
    for (int i = 0; i < sz(adj[u]); ++i) {
        int v = adj[u][i].second, w = adj[u][i].first;
        if (v == p) continue;
        dfs(v, u);
        f[u][0] = max({f[u][0], f[v][0], f[v][1]});
        f[u][1] = max(f[u][1], f[u][1] + w + f[v][1]);
    }
}

void process() {
    dfs(1, 1);
    printf("%d\n", max(f[1][0], f[1][1]));
}

int main() {
    freopen("MAXTREE.inp", "r", stdin);
    freopen("MAXTREE.out", "w", stdout);

    load();
    process();

    return 0;
}
