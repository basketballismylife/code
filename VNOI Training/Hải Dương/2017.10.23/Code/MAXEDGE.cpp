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

const int N = 2e5 + 10;

struct node {
    int u, v, w;
    node() {}
    node(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const node &p) { return w < p.w; }
};

int n, m;
int root[22][N], depth[N], mx[22][N], par[N];
vector <node> edges;
vector < pair <int, int> > adj[N];

void load() {
    read(n); read(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w; read(u); read(v); read(w);
        edges.push_back({u, v, w});
    }
}

void dfs(int u, int p) {
    root[0][u] = p;
    for (pair <int, int> it : adj[u]) if (it.second != p) {
        depth[it.second] = depth[u] + 1;
        mx[0][it.second] = it.first;
        dfs(it.second, u);
    }
}

int anc(int p) { return par[p] == p ? p : par[p] = anc(par[p]); }
void join(int p, int q) { par[anc(p)] = anc(q); }

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

int getmax(int r, int u) {
    int res = -1e9;
    for (int k = 21; k >= 0; --k) if (depth[root[k][u]] >= depth[r]) {
        res = max(res, mx[k][u]);
        u = root[k][u];
    }
    return res;
}

void process() {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (anc(u) != anc(v)) {
            join(u, v);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
            //cerr << u << " " << v << " " << w << "\n";
        }
    }
    dfs(1, 1);
    for (int j = 1; j < 22; ++j) for (int i = 1; i <= n; ++i) {
        root[j][i] = root[j - 1][root[j - 1][i]];
        mx[j][i] = max(mx[j - 1][i], mx[j - 1][root[j - 1][i]]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; read(u); read(v);
        int r = lca(u, v); //getmax(r, v);
        writeln(max(getmax(r, u), getmax(r, v)));
    }
}

int main() {
    freopen("MAXEDGE.inp", "r", stdin);
    freopen("MAXEDGE.out", "w", stdout);

    load();
    process();

    return 0;
}
