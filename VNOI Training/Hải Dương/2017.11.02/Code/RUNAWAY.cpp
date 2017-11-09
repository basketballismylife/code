#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 2e5 + 10;

int n;
long long l;
int root[22][N], deg[N];
long long depth[N];
vector < pair <long long, int> > adj[N];

void load() {
    scanf("%d%lld", &n, &l);
    for (int i = 2; i <= n; ++i) {
        int p; long long w; scanf("%d%lld", &p, &w);
        adj[p].push_back({w, i});
    }
}
#define v adj[u][i].second
#define w adj[u][i].first
void dfs(int u, int p) {
    root[0][u] = p;
    for (int i = 0; i < sz(adj[u]); ++i) if (v != p) {
        depth[v] = depth[u] + w;
        dfs(v, u);
    }
}

void dfs1(int u, int p) {
    for (int i = 0; i < sz(adj[u]); ++i) if (v != p) {
        dfs1(v, u);
        deg[u] += deg[v];
    }
}

void process() {
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i)
        root[j][i] = root[j - 1][root[j - 1][i]];
    for (int u = 1; u <= n; ++u) {
        int p = u;
        for (int k = 21; k >= 0; --k) if (depth[u] - depth[root[k][p]] <= l) {
            p = root[k][p];
        }
        deg[u]++;
        if (p != root[0][p]) deg[root[0][p]]--;
    }
    dfs1(1, 1);
    for (int i = 1; i <= n; ++i) printf("%d\n", deg[i]);
}

int main() {
    freopen("RUNAWAY.inp", "r", stdin);
    freopen("RUNAWAY.out", "w", stdout);

    load();
    process();

    return 0;
}
