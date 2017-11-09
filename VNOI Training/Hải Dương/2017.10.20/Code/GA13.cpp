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
#define task "GA13"
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

int n, m, s, p, id, nComp, tail;
int num[N], low[N], idComp[N], atm[N], w[N], game[N], st[N], tp[N];
long long dp[N];
bool vis[N];
vector <int> a[N], adj[N];
vector < pair <int, int> > edges;

void load() {
    scanf("%d%d", &n, &m);
    REP(love, m) {
        int u, v; scanf("%d%d", &u, &v);
        a[u].push_back(v);
        edges.push_back({u, v});
    }
    FOR(i, 1, n) scanf("%d", w + i);
    scanf("%d%d", &s, &p);
    FOR(i, 1, p) scanf("%d", game + i);
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
    if (low[u] == num[u]) {
        int v; nComp++;
        do {
            v = st[tail--];
            idComp[v] = nComp; //cerr << v << " ";
            low[v] = num[v] = 1e9 + 7;
        } while (v != u);
        //cerr << "\n";
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) {
        dfs(v);
    }
    tp[id--] = u;
}

void process() {
    FOR(i, 1, n) if (!num[i]) {
        dfs(i, i);
    }
    FOR(i, 1, n) atm[idComp[i]] += w[i];
    REP(i, m) {
        int u = edges[i].first, v = edges[i].second;
        if (idComp[u] != idComp[v]) {
            adj[idComp[u]].push_back(idComp[v]);
        }
    }
    FOR(i, 1, nComp) {
        sort(all(adj[i]));
        uni(adj[i]);
    }
    id = nComp;
    dfs(idComp[s]);
    dp[idComp[s]] = atm[idComp[s]];
    FOR(i, 1, nComp) {
        int u = tp[i];
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + atm[v]);
        }
    }
    long long answer = 0;
    FOR(i, 1, p) answer = max(answer, dp[idComp[game[i]]]);
    printf("%lld\n", answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}
