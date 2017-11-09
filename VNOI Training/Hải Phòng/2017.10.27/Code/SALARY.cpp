#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;


int n, m, id;
int in[N], out[N];
long long v[N], value[N];
vector <int> adj[N];

class SegmentTree {
private:
    long long t[N << 2], lz[N << 2];
public:
    void build(int k, int l, int r) {
        if (l > r) return;
        if (l == r) {
            t[k] = value[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build((k << 1) + 1, mid + 1, r);
      //  cerr << k << " " << l << " " << r << "\n";
    }
    void lazy(int k, int l, int r) {
        if (!lz[k]) return;
        if (l != r) {
            lz[k << 1] += lz[k];
            lz[(k << 1) + 1] += lz[k];
            t[k << 1] += lz[k];
            t[(k << 1) + 1] += lz[k];
        }
        lz[k] = 0;
    }
    void update(int k, int l, int r, int i, int j, int value) {
        if (l > j || r < i) return;
        lazy(k, l, r);
        if (i <= l && r <= j) {
            lz[k] += value;
            t[k] += value;
            return;
        }
        int mid = (l + r) >> 1;
        update(k << 1, l, mid, i, j, value);
        update((k << 1) + 1, mid + 1, r, i, j, value);
    }
    long long get(int k, int l, int r, int i) {
        lazy(k, l, r);
        if (l == r) return t[k];
        int mid = (l + r) >> 1;
        if (mid >= i) return get(k << 1, l, mid, i);
        else return get((k << 1) + 1, mid + 1, r, i);
    }
} it;

void dfs(int u) {
    in[u] = ++id;
    value[in[u]] = v[u];
    for (int v : adj[u])
        dfs(v);
    out[u] = id;
}

int main() {
    freopen("SALARY.INP", "r", stdin);
    freopen("SALARY.OUT", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        if (i == 1) scanf("%lld", &v[i]);
        else {
            int p; scanf("%lld%d", &v[i], &p);
            adj[p].push_back(i);
        }
    }
    dfs(1);
    it.build(1, 1, n);
    while (m--) {
        char s[2]; int u, v; scanf("%s", s);
        if (s[0] == 'p') {
            scanf("%d%d", &u, &v);
            it.update(1, 1, n, in[u] + 1, out[u], v);
        } else {
            scanf("%d", &u);
            printf("%lld\n", it.get(1, 1, n, in[u]));
        }
    }

    return 0;
}
