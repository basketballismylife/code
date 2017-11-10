#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 7
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

const int N = 1e5 + 10;

struct Dinitz2 {
    int n, s, t, nE;
    ll cap[N], flow[N], pre[N];
    int q[N], d[N], adj[N], last[N], pro[N], next[N];
    bool mx[N];

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
        if (!flowed) return 0;
        if (u == t) return flowed;
        //cerr << u << " ";
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
    ll maxflow() {
        ll ans = 0;
        while (bfs()) {
            FOR(i, 1, n) pro[i] = last[i];
            while (ll pushed = dfs(s, INF)) {
                ans += pushed;
            }
        }
        return ans;
    }
    void trace(int x, int y) {
        int cnt = 0;
        for (int i = 1; i <= x; ++i) cnt += d[i] != -1;
        if (!cnt) puts("0"); else {
            for (int i = 1; i <= x; ++i) if (d[i] != -1) printf("%d ", i);
        }
        puts("");
        cnt = 0;
        for (int i = 1; i <= y; ++i) cnt += d[i + x] != -1;
        if (!cnt) puts("-1"); else {
            for (int i = 1; i <= y; ++i) if (d[i + x] != -1) printf("%d ", i);
        }
        puts("");
    }
} dinic;

int n, m, s, t;
ll sum;

void load() {
    scanf("%d%d", &n, &m);
    s = n + m + 1; t = n + m + 2;
    dinic.init(n + m + 10, s, t);
    for (int i = 1; i <= n; ++i) {
        int p; scanf("%d", &p);
        dinic.add(s, i, p, 0);
        sum += p;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        int cp; scanf("%d", &cp);
        dinic.add(i, t, cp, 0);
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        int x; scanf("%d", &x);
        if (x) dinic.add(i, j + n, INF, 0);
    }
}

void process() {
    printf("%lld\n", sum - dinic.maxflow());
    dinic.trace(n, m);
}

int main() {
    freopen("NASA.inp", "r", stdin);
    freopen("NASA.out", "w", stdout);

    load();
    process();

    return 0;
}
