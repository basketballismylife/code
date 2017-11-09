#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "GA12"
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

const int N = 1e5 + 10;

int n, m, s, t, id;
int tp[N], vis[N];
long long dp[N];
vector < pair < int, int > > adj[N];

void load() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
    }
    scanf("%d%d", &s, &t);
}

void dfs(int u) {
    vis[u] = 1;
    REP(i, sz(adj[u])) {
        int v = adj[u][i].second, w = adj[u][i].first;
        if (!vis[v])
            dfs(v);
    }
    tp[id--] = u;
}

void process() {
    id = n;
    FOR(i, 1, n) if (!vis[i]) dfs(i);
    FOR(i, 1, n) dp[i] = -1e18;
    dp[s] = 0;
    for (int i = 1; i <= n; ++i) {
        int u = tp[i];
        REP(i, sz(adj[u])) {
            int v = adj[u][i].second, w = adj[u][i].first;
            if (dp[u] != -1e18)
                dp[v] = max(dp[v], dp[u] + w);
        }
    }
    if (dp[t] == -1e18) puts("NO PATH"); else printf("%lld\n", dp[t]);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
