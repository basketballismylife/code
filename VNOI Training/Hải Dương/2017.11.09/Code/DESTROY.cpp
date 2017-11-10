#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define INF 1e9 + 7

const int N = 1e5 + 10;

struct Dinitz {
    int n, s, t, nE;
    ll cap[N], flow[N];
    int q[N], d[N], adj[N], last[N], pro[N], next[N];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        fill_n(last, n + 1, -1);
    }
    void add(int u, int v, int w, int _w) {
        adj[nE] = v; cap[nE] = w; flow[nE] = 0; next[nE] = last[u]; last[u] = nE++;
        adj[nE] = u; cap[nE] = _w; flow[nE] = 0; next[nE] = last[v]; last[v] = nE++;
    }
    bool bfs() {
        fill_n(d, n + 1, -1);
        int head = 0, tail = 0;
        q[tail++] = s; d[s] = 0;
        while (head < tail) {
            int u = q[head++];
            for (int id = last[u]; id != -1; id = next[id]) {
                int v = adj[id];
                if (d[v] == -1 && flow[id] < cap[id]) {
                    d[v] = d[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return d[t] != -1;
    }
    ll dfs(int u, ll flowed) {
   //     cerr << u << " ";
        if (!flowed) return 0;
        if (u == t) return flowed;
        for (int &id = pro[u]; id != -1; id = next[id]) {
            int v = adj[id];
            if (flow[id] < cap[id] && d[v] == d[u] + 1) {
                ll pushed = dfs(v, min(flowed, cap[id] - flow[id]));
                if (pushed) {
                    flow[id] += pushed;
                    flow[id ^ 1] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll run() {
        ll ans = 0;
        while (bfs()) {
            FOR(i, 1, n) pro[i] = last[i];
            while (ll pushed = dfs(s, INF)) {
                ans += pushed;
         //       cerr << "\n";
            }
        }
        return ans;
    }
} mf;

int n, m;

void load() {
    scanf("%d%d", &n, &m);
    int s = n + n + 1, t = n + n + 2;
    mf.init(2 * n + 10, s, t);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        mf.add(s, i, x, 0);
    }
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        mf.add(n + i, t, x, 0);
    }
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        mf.add(u, n + v, INF, 0);
    }
}

void process() {
    printf("%d\n", mf.run());
}

int main() {
    freopen("DESTROY.inp", "r", stdin);
    freopen("DESTROY.out", "w", stdout);

    load();
    process();

    return 0;
}
