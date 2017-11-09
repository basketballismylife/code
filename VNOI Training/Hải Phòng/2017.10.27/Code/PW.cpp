#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

const int N = 1e5 + 10;

int n, m, k;
int lz[N << 2];
pair <int, int> t[N << 2];
vector < pair <int, int> > add[N], sub[N];

void load() {
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
        x = max(1, x - k + 1);
        y = max(1, y - k + 1);
        u = min(u, n - k + 1);
        v = min(v, n - k + 1);
        add[x].push_back({y, v});
        sub[u + 1].push_back({y, v});
    }
}
#define mid ((l + r) >> 1)
void build(int k, int l, int r) {
    if (l > r) return;
    if (l == r) {
        t[k] = make_pair(0, l);
        return;
    }
    build(k << 1, l, mid);
    build((k << 1) + 1, mid + 1, r);
    t[k] = max(t[k << 1], t[(k << 1) + 1]);
}

void lazy(int k, int l, int r) {
    if (!lz[k]) return;
    if (l != r) {
        lz[k << 1] += lz[k];
        lz[(k << 1) + 1] += lz[k];
        t[k << 1].first += lz[k];
        t[(k << 1) + 1].first += lz[k];
    }
    lz[k] = 0;
}

void update(int k, int l, int r, int i, int j, int value) {
    lazy(k, l, r);
    if (i > r || j < l) return;
    if (i <= l && r <= j) {
        lz[k] += value;
        t[k].first += value;
        return;
    }
    update(k << 1, l, mid, i, j, value);
    update((k << 1) + 1, mid + 1, r, i, j, value);
    t[k] = max(t[k << 1], t[(k << 1) + 1]);
}
#undef mid

void process() {
    build(1, 1, N - 1);
    int ans = 0, x, y;
    for (int i = 1; i < N; ++i) if (sz(add[i]) || sz(sub[i])) {
        for (int j = 0; j < sz(add[i]); ++j)
            update(1, 1, N - 1, add[i][j].first, add[i][j].second, 1);
        for (int j = 0; j < sz(sub[i]); ++j)
            update(1, 1, N - 1, sub[i][j].first, sub[i][j].second, -1);
        if (ans < t[1].first) {
            ans = t[1].first;
            x = i; y = t[1].second;
        }
    }
    printf("%d\n%d %d\n", ans, x, y);
}

int main() {
    freopen("PW.inp", "r", stdin);
    freopen("PW.out", "w", stdout);

    load();
    process();

    return 0;
}
