#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())
#define task "GA4"
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

const int N = 5e5 + 10;

int n, m, id, tail, ans, nComp, head;
int num[N], low[N], st[N], idComp[N], par[N], out[N];
bool vis[N];
vector <int> a[N], comp[N];
vector < pair<int, int> > edges;

void load() {
    scanf("%d", &n);
    int u, v;
    while (~scanf("%d%d", &u, &v)) {
        a[u].push_back(v);
        edges.push_back({u, v});
    }
}

void dfs(int u, int p) {
    st[++tail] = u; num[u] = low[u] = ++id;
    for (int v : a[u]) if (v != p) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        int v = 0, cnt = 0; nComp++;
        do {
            cnt++;
            v = st[tail--];
            idComp[v] = nComp; comp[nComp].push_back(v);
            low[v] = num[v] = 1e9 + 7;
        } while (v != u);
    }
}

void process() {
    FOR(i, 1, n) if (!num[i]) dfs(i, i);
    REP(i, sz(edges)) {
        int u = edges[i].first, v = edges[i].second;
        if (idComp[u] != idComp[v])
            out[idComp[u]]++;
    }
    ans = 1e9 + 7;
    FOR(i, 1, nComp) if (!out[i]) {
        if (ans > sz(comp[i])) {
            ans = sz(comp[i]);
            head = i;
        }
    }
    printf("%d\n", ans);
    REP(i, sz(comp[head])) printf("%d ", comp[head][i]);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
