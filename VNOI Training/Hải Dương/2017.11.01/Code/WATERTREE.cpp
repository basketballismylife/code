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

const int N = 5e5 + 10;

class SegmentTree {
private:
    int t[N << 2], lz[N << 2];
public:
    #define mid ((l + r) >> 1)
    void lazy(int k, int l, int r) {
        if (!lz[k]) return;
        if (l != r) {
            t[k << 1] = t[(k << 1) + 1] = t[k];
            lz[k << 1] = lz[(k << 1) + 1] = lz[k];
        }
        lz[k] = 0;
    }
    void update(int k, int l, int r, int i, int j, int value) {
        if (l > j || r < i) return;
        lazy(k, l, r);
        if (i <= l && r <= j) {
            t[k] = value;
            lz[k] = 1;
            return;
        }
        update(k << 1, l, mid, i, j, value);
        update((k << 1) + 1, mid + 1, r, i, j, value);
        t[k] = max(t[k << 1], t[(k << 1) + 1]);
    }
    int get(int k, int l, int r, int i, int j) {
        if (i > r || l > j) return 0;
        lazy(k, l, r);
        if (i <= l && r <= j) return t[k];
        return max(get(k << 1, l, mid, i, j), get((k << 1) + 1, mid + 1, r, i, j));
    }
    #undef mid
} it[2];

int n, id;
int in[N], out[N];
vector <int> adj[N];

void load() {
    read(n);
    for (int i = 1; i < n; ++i) {
        int u, v; read(u); read(v);
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

void process() {
    dfs(1, 1);
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int t, u; scanf("%d%d", &t, &u);
        if (t == 1) {
            it[0].update(1, 1, n, in[u], out[u], i);
        } else if (t == 2) {
            it[1].update(1, 1, n, in[u], in[u], i);
        } else {
            printf("%d\n", it[0].get(1, 1, n, in[u], in[u]) > it[1].get(1, 1, n, in[u], out[u]));
        }
    }
}

int main() {
    freopen("WATERTREE.inp", "r", stdin);
    freopen("WATERTREE.out", "w", stdout);

    load();
    process();

    return 0;
}
