/*
    Author: houtaru
    Create: 23.10.2017
    Status: AC
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

class SegmentTree {
private:
    long long lz[N << 2];
public:
    void lazy(int k, int l, int r) {
        if (l == r || !lz[k]) return;
        lz[k << 1] += lz[k];
        lz[(k << 1) + 1] += lz[k];
        lz[k] = 0;
    }
    void update(int k, int l, int r, int i, int j, int value) {
        if (i > r || j < l) return;
        lazy(k, l, r);
        if (i <= l && r <= j) {
            lz[k] += value;
            return;
        }
        int mid = (l + r) >> 1;

        update(k << 1, l, mid, i, j, value);
        update((k << 1) + 1, mid + 1, r, i, j, value);
    }
    long long get(int k, int l, int r, int i) {
        lazy(k, l, r);
        if (l == r) return lz[k];
        int mid = (l + r) >> 1;
        return i <= mid ? get(k << 1, l, mid, i) : get((k << 1) + 1, mid + 1, r, i);
    }
} it;

int n, m, q, nChain, nBase;
int chainHead[N], chainInd[N], posInBase[N], depth[N], sz[N], par[N];
long long dist[N], value[N];
vector <int> adj[N];

void load() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != par[u]) {
        depth[v] = depth[u] + 1; par[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
}

void hld(int u) {
    if (chainHead[nChain] == 0) chainHead[nChain] = u;

    chainInd[u] = nChain;
    posInBase[u] = ++nBase;

    int bigChild = -1;
    for (int v : adj[u]) if (v != par[u] && (bigChild == -1 || sz[bigChild] < sz[v])) {
        bigChild = v;
    }
    if (bigChild != -1) hld(bigChild);
    for (int v : adj[u]) if (v != par[u] && v != bigChild) {
        nChain++;
        hld(v);
    }
}

int lca(int u, int v) {
    while (chainInd[u] != chainInd[v]) {
        if (depth[chainHead[chainInd[u]]] < depth[chainHead[chainInd[v]]]) v = par[chainHead[chainInd[v]]];
        else u = par[chainHead[chainInd[u]]];
    }
    return depth[u] < depth[v] ? u : v;
}

void update(int r, int u, int w) {
    while (chainInd[u] != chainInd[r]) {
        it.update(1, 1, nBase, posInBase[chainHead[chainInd[u]]], posInBase[u], w);
        u = par[chainHead[chainInd[u]]];
    }
    it.update(1, 1, nBase, posInBase[r], posInBase[u], w);
}

void dfs1(int u) {
    for (int v : adj[u]) if (v != par[u]) {
        dist[v] = dist[u] + value[v];
        dfs1(v);
    }
}

void process() {
    dfs(1);
    hld(1);
    while (m--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        int r = lca(u, v);
        update(r, u, w);    update(r, v, w);
        it.update(1, 1, nBase, posInBase[r], posInBase[r], -w);
    }
    for (int i = 1; i <= n; ++i) value[i] = it.get(1, 1, nBase, posInBase[i]);//, cerr << value[i] << "\n";
    dist[1] = value[1];
    dfs1(1);
   // for (int i = 1; i <= n; ++i) cerr << dist[i] << "\n";
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        int r = lca(u, v);
        printf("%lld\n", dist[u] + dist[v] - dist[r] - dist[par[r]]);
    }
}

int main() {
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);

    load();
    process();

    return 0;
}
