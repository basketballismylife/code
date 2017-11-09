#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "GA9"
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

int n, m, id;
int num[N], low[N], nChild[N], par[N];
bool isCut[N];
long long query[N];
vector < int > adj[N];
vector < pair < int, int > > edges;

void load() {
    read(n); read(m);
    while (m--) {
        int u, v; read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
}

void dfs(int u) {
    num[u] = low[u] = ++id; nChild[u] = 1; int cnt = 0;
    vector < int > child;
    for (int v : adj[u]) if (v != par[u]) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            par[v] = u; cnt++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            nChild[u] += nChild[v];
            if (low[v] >= num[u]) {
                if (v == par[u] && cnt < 2) continue;
                isCut[u] = 1;
                child.push_back(v);
            }
        }
    }
    if (!isCut[u]) query[u] = 2 * (n - 1); else {
        query[u] = n - 1;
        int c = n - 1;
        for (int v : child) {
            query[u] += 1ll * nChild[v] * (n - nChild[v]);
            c -= nChild[v];
        }
        if (par[u] != -1) query[u] += 1ll * c * (n - c);
    }
}

void process() {
    par[1] = -1;
    dfs(1);
    FOR(u, 1, n) writeln(query[u]);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
