#include <bits/stdc++.h>
using namespace std;

template <class T> void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') nega = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> wri(T x) { if (x / 10) wri(x / 10); putchar(x % 10 + '0'); }
template <class T> write(T x) { if (x < 0) putchar('-'); wri(abs(x)); }
template <class T> writeln(T x) { write(x); putchar('\n'); }

const int N = 1e6 + 10;

int n;
int depth[N], root[22][N];
long long dist[N];
vector < pair <int, int> > adj[N];

void load() {
    read(n);
    for (int i = 2; i <= n; ++i) {
        int p, w; read(p); read(w);
        adj[p].push_back({w, i});
    }
}

void dfs(int u, int p) {
    root[0][u] = p;
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        dist[it.second] = dist[u] + it.first;
        depth[it.second]= depth[u] + 1;
        dfs(it.second, u);
    }
}

int lca(int u, int v) {
    for (int k = 20; k >= 0; --k) if (depth[root[k][u]] >= depth[v])
        u = root[k][u];
    for (int k = 20; k >= 0; --k) if (depth[root[k][v]] >= depth[u])
        v = root[k][v];
    if (u == v) return u;
    for (int k = 20; k >= 0; --k) if (root[k][u] != root[k][v]) {
        u = root[k][u]; v = root[k][v];
    }
    return root[0][u];
}

void process() {
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i)
        root[j][i] = root[j - 1][root[j - 1][i]];
    int q; read(q);
    while (q--) {
        int u, v, w; read(u); read(v); read(w);
        int r = lca(u, v);
        long long ans = min(dist[u], dist[v] + w);
        ans += min(dist[u] + dist[v] - 2 * dist[r], 1ll * w);
        writeln(ans);
    }
}

int main() {
    freopen("FRIENDS.inp", "r", stdin);
    freopen("FRIENDS.out", "w", stdout);

    load();
    process();

    return 0;
}
