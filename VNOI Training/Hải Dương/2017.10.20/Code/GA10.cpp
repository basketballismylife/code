#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "GA10"
#define sqr(x) 1ll * (x) * (x)
#define EPS 1e-9

template <class T> int getBit(T x, int k) { return x >> k & 1; }
template <class T> T onBit(T x, int k) { return x  (T(1) << k); }
template <class T> T offBit(T x, int k) { return x & (~(T(1) << k)); }
template < class T > void read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
template <class T> void write(T x) { if (x / 10) write(x / 10); putchar(x % 10 + '0'); }
template <class T> void writeln(T x) { if (x < 0) putchar('-'); write(abs(x)); putchar('\n'); }

const int N = 5e4 + 10;

int n, m, id, nComp;
int num[N], low[N], idComp[N], head[N];
bool vis[N];
vector < int > a[N], adj[N];
vector < pair < int, int > > bridge;
map < pair <int, int>, int> isbridge;

void load() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs1(int u, int p) {
    num[u] = low[u] = ++id;
    for (int v : a[u]) if (v != p) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs1(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
                bridge.push_back({u, v});
                isbridge[minmax(u, v)] = 1;
    //            cerr << u << " " << v << "\n";
            }
        }
    }
}

void dfs2(int u) {
    idComp[u] = nComp;
    vis[u] = 1;
    for (int v : a[u]) if (!vis[v] && !isbridge.count(minmax(u, v))) {
        dfs2(v);
    }
}

void process() {
    dfs1(1, 1);
    FOR(i, 1, n) if (!vis[i]) {
        nComp++; head[nComp] = i;
        dfs2(i);
    }
    REP(i, sz(bridge)) {
        int u = bridge[i].first, v = bridge[i].second;
        adj[idComp[u]].push_back(idComp[v]);
        adj[idComp[v]].push_back(idComp[u]);
    }
    FOR(i, 1, nComp) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    vector < int > leaf;
    FOR(i, 1, nComp) if (sz(adj[i]) == 1) {
        leaf.push_back(i);
    }
    printf("%d\n", (sz(leaf) + 1) / 2);
    for (int i = 0; i < sz(leaf); i += 2) {
        printf("%d %d\n", head[leaf[i]], head[leaf[(i + 1) % sz(leaf)]]);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
