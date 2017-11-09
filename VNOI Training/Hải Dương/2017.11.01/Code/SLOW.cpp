#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, id;
int in[N], out[N], t[N << 2], lz[N << 2];
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
    in[u] = ++id;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
    }
    out[u] = id;
}
#define mid ((l + r) >> 1)
void lazy(int k, int l, int r) {
    if (!lz[k]) return;
    if (l != r) {
        t[k << 1] += lz[k];
        lz[k << 1] += lz[k];
        t[(k << 1) + 1] += lz[k];
        lz[(k << 1) + 1] += lz[k];
    }
    lz[k] = 0;
}
void update(int k = 1, int l = 1, int r = n, int i = 0, int j = 0) {
    if (l > j || r < i) return;
    lazy(k, l, r);
    if (i <= l && r <= j) {
        t[k]++;
        lz[k]++;
        return;
    }
    update(k << 1, l, mid, i, j);
    update((k << 1) + 1, mid + 1, r, i, j);
    t[k] = t[k << 1] + t[(k << 1) + 1];
}

int get(int k = 1, int l = 1, int r = n, int i = 0, int j = 0) {
    if (l > j || r < i) return 0;
    lazy(k, l, r);
    if (i <= l && r <= j) return t[k];
    return get(k << 1, l, mid, i, j) + get((k << 1) + 1, mid + 1, r, i, j);
}
#undef mid
void process() {
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        int p; scanf("%d", &p);
        printf("%d\n", get(1, 1, n, in[p], in[p]));
        update(1, 1, n, in[p], out[p]);
    }
}

int main() {
    freopen("SLOW.inp", "r", stdin);
    freopen("SLOW.out", "w", stdout);

    load();
    process();

    return 0;
}
