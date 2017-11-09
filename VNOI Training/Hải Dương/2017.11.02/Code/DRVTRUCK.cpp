#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int) v.size()

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

int n, k;
int cnt[N];
long long f[2][N], g[N], t[2][N];
bool have[N];
vector < pair <int, int> > adj[N];

void load() {
    read(n); read(k);
    for (int i = 1; i < n; ++i) {
        int u, v, w; read(u); read(v); read(w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for (int i = 0; i < k; ++i) {
        int x; read(x);
        have[x] = 1;
    }
}
#define v it.second
#define w it.first
void dfs(int u, int p) {
    cnt[u] = have[u];
    for (pair <int, int> it : adj[u]) if (v != p) {
        dfs(v, u);
        cnt[u] += cnt[v];
        t[0][u] += t[0][v] + (!!cnt[v]) * w;
        if (cnt[v]) {
            if (f[0][v] + w > f[0][u]) {
                f[1][u] = f[0][u]; f[0][u] = f[0][v] + w;
            } else if (f[0][v] + w > f[1][u]) {
                f[1][u] = f[0][v] + w;
            }
        }
    }
}

void dfs1(int u, int p) {
    for (pair <int, int> it : adj[u]) if (v != p) {
        if (cnt[v] != k) {
            t[1][v] += t[1][u] + (t[0][u] - t[0][v] - (!!cnt[v]) * w) + (!!(k - cnt[v])) * w;
            g[v] = g[u] + w;
            if (f[0][v] + w == f[0][u]) {
                g[v] = max(g[v], f[1][u] + w);
            } else {
                g[v] = max(g[v], f[0][u] + w);
            }
        }
        dfs1(v, u);
    }
}
#undef v
#undef w
void process() {
    dfs(1, 0);
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i) {
        long long ans = 2 * (t[0][i] + t[1][i]) - max(f[0][i], g[i]);
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("DRVTRUCK.inp", "r", stdin);
    freopen("DRVTRUCK.out", "w", stdout);

    load();
    process();

    return 0;
}
