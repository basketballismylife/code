#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORE(i, v) for (__typeof (v.begin()) i = v.begin(); i != v.end(); ++i)
#define FORR(i, v) for (__typpeof (v.rbegin()) i = v.rbegin(); i != v.rend(); ++i)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define task "GA8"
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

int n, m, K, L, id, answer;
int low[N], num[N], numA[N], numB[N];
bool dvu[N], ttin[N];
vector < int > adj[N];

void load() {
    read(n); read(m); read(K); read(L);
    FOR(i, 1, K) {
        int x; read(x);
        dvu[x]++;
    }
    FOR(i, 1, L) {
        int x; read(x);
        ttin[x]++;
    }
    while (m--) {
        int u, v; read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p) {
    num[u] = low[u] = ++id;
    for (int v : adj[u]) if (v != p) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v] && (numA[v] == 0 || numA[v] == K || numB[v] == 0 || numB[v] == L)) {
                answer++;
              //  cerr << u << " " << v << "\n";
            }
            //if (low[v] >= num[v]) cerr << u << " " << v << "\n";
            numA[u] += numA[v];
            numB[u] += numB[v];
        }
    }
    numA[u] += dvu[u]; numB[u] += ttin[u];
}

void process() {
    dfs(1, 1);
    printf("%d\n", answer);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    load();
    process();

    return 0;
}

